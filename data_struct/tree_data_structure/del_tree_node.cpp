//convert array to BST
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<stdbool.h>
using namespace std ;


/*
[1,2,3,4,5,6,7,8]

       4
     /  \ 
    2    6 
   / \   /\
  1  3  5  7
            \
             8 

cin>> 6

       4
     /  \ 
    2    7 
   / \   /\
  1  3  5  8
        
*/

struct treenode
{
    int value;
    struct treenode *left;
    struct treenode *right;

};
treenode *crt_node(int value )
{
    treenode *node =new treenode();
    node->value=value;
    node->left=NULL;
    node->right=NULL;
    return node;
}

void print_tabs(int i)
{
    while (i>0)
    {
        cout<<"\t";
        i=i-1;
    }
}
void print_tree(treenode *root, int level)
{
    if (root==NULL)
    {
        cout<<"--";
        return;
    }
    cout<<"value="<<root->value<<endl;
    print_tabs(level);
    cout<<"left=";
    print_tree(root->left,level+1);

    print_tabs(level);
    cout<<"right=";
    print_tree(root->right,level+1);
    cout<<endl;
}

// void del_node(treenode *node)
// {
//     if (root->left->left==NULL)
// }
bool check_node(treenode *root, int item)
{
    if (root==NULL) return false;
    if (root->left==NULL && root->right==NULL)return false;
    if (root->value>item)
    {
        if(root->left->value==item)
        {
            if (root->left->right==NULL && root->left->left==NULL) 
            {
                delete(root->left);
                root->left=NULL;
                return true;
            }
            if (root->left->right==NULL)
            {
                treenode *tmp=root->left->left;
                delete(root->left);
                root->left=tmp;
                return true;
            }
            if (root->left->left==NULL)
            {
                treenode *tmp=root->left->right;
                delete(root->left);
                root->left=tmp;
                return true;
            }
            cout<<"found item"<<endl;
            return false;
        }
        else return check_node(root->left,item);
    }
    else
    {
        if (root->right->value==item) 
        {
            if (root->right->right==NULL && root->left->left==NULL) 
            {
                delete(root->right);
                root->left=NULL;
                return true;
            }
            if (root->right->left==NULL)
            {
                treenode *tmp=root->right->right;
                delete(root->right);
                root->right=tmp;
                return true;
            }
            cout<<"found item"<<endl;
            return false;
        }
        else return check_node(root->right,item);
    }

//    return root;
}


treenode *ins_tree(int *arr,int start,int end)
{
    if (end<start) return NULL;
    int mid=(start+end)/2;
    treenode *root=crt_node(arr[mid]);
    root->left=ins_tree(arr,start,mid-1);
    root->right=ins_tree(arr,mid+1,end);
    return root;
}

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    treenode *root = crt_node(arr[0]);
    int l=sizeof(arr)/sizeof(arr[0]);
    int i=1;
    root=ins_tree(arr,0,l-1);
    print_tree(root,0);
    int item=7;
    //cin>>item;
    cout<<check_node(root,item)<<endl;
    print_tree(root,0);
    return 0;
}

