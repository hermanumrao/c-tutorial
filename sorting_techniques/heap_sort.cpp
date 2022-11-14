//priority queue
//refer tree data struct-> max_heap and array2tree
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<stdbool.h>
using namespace std ;



struct treenode
{
    int value;
    struct treenode *left;
    struct treenode *right;

};
treenode *crt_node(int value)
{
    treenode *node =new treenode();
    node->value=value;
    node->left=NULL;
    node->right=NULL;
    return node;
}

void disp_arr(int *arr, int l)
{
    cout<<"array=";
    for (int b=0;b<l;b++)
    {
        cout<<arr[b]<<' ';
    }
    cout<<endl;
}

int check_height(treenode *node)
{
    if (node == NULL) return 0;
    else return (1+max(check_height(node->left),check_height(node->right)));
}

void max_heap(treenode *root)
{
    if (root==NULL || (root->right==NULL && root->left==NULL))
    {
        return ;
    }
    max_heap(root->right);
    int a=root->value;
    if (root->left==NULL )
    {
        int c=root->right->value;
        if (c>a)
        {
            root->value=c;
            root->right->value=a;
        }
    }
    if (root->right==NULL)
    {
        int b=root->left->value;
        if(b>a)
        {
            root->value=b;
            root->left->value=a;
        }
    }
    if (root->right!=NULL && root->left!=NULL)
    {
        int b=root->left->value;
        int c=root->right->value;
        if (b>a || c>a)
        {
            if(b>c)
            {
                root->value=b;
                root->left->value=a;
            }
            else
            {
                root->value=c;
                root->right->value=a;
            }
        }
    }
    max_heap(root->left);
}

void BSTtoArray(treenode *root, int *arr, int &pos)
{
    if(root == NULL) return;
    arr[pos++] = root->value;

    BSTtoArray(root->left, arr, pos);
    BSTtoArray(root->right,arr,pos);

}

treenode *heapify(int *arr,int start,int end)
{
    if (end<start) return NULL;
    int mid=(start+end)/2;
    treenode *root=crt_node(arr[mid]);
    root->left=heapify(arr,start,mid-1);
    root->right=heapify(arr,mid+1,end);
    return root;
}

int main()
{
    int arr[]={4,7,6,5,3,8,2,11,15,63,144,1};
    int l=sizeof(arr)/sizeof(arr[0]);
    int pos;
    for (int it2=0;it2<l;it2++)
    {
    	pos=it2;
	    treenode *root=heapify(arr,pos,l-1);
	    int lvl=check_height(root);
	    for (int it1=0;it1<lvl;it1++) max_heap(root);
	    BSTtoArray(root,arr,pos);
	}
	cout<<"final-->";
	disp_arr(arr,l);
    return 0;
}



/*

{4,7,6,5,3,8,2,9,1}

      4
     / \ 
    7   6 
   / \  /\
  5  3 8  2
 /\
9  1


      9
     / \ 
    8   7 
   / \  /\
  5  3 6  2
 /\
4  1
        */