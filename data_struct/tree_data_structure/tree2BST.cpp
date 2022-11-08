// to perform this operation we need to first convert the treeee to array and then  convert it back to BST
//refer BST2array.cpp and array2BST for further help
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <queue>
#include <stdbool.h>
using namespace std ;

/*
   1
  / \ 
 2   3 
/ \  /\
4 5 6  7
   /\
  8  9
        */
//requirement of library function of quick sort
int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}


struct treenode
{
	int value;
	struct treenode *left;
	struct treenode *right;

};
treenode *create_node(int value)
{
	treenode *node =new treenode();
	node->value=value;
	node->left=NULL;
	node->right=NULL;
	return node;
}


int treeSize(treenode* root) {
    if(root == NULL) return 0;
    else
        return treeSize(root->left) + treeSize(root->right) + 1;
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
        cout<<"-- ";
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

void BSTtoArray(treenode *root, int *arr, int &pos)
{
    if(root == NULL) return;

    BSTtoArray(root->left, arr, pos);
    arr[pos++] = root->value;
    BSTtoArray(root->right,arr,pos);

}
int check_height(treenode *root,int lvl)
{
	if (root==NULL)
	{
		cout<<"-- ";
		return lvl ;
	}
    
	check_height(root->left,lvl+1);
	check_height(root->right,lvl+1);
}

treenode *ins_tree(int *arr,int start,int end)
{
    if (end<start) return NULL;
    int mid=(start+end)/2;
    treenode *root=create_node(arr[mid]);
    root->left=ins_tree(arr,start,mid-1);
    root->right=ins_tree(arr,mid+1,end);
    return root;
}

bool search_tree(treenode *root, int item)
{
    if (root==NULL) return false;
    int val=root->value;
    if (val==item) 
    {
        return true;
    }
    if (root->left==NULL && root->right==NULL) return false;
    if (val>item) return search_tree(root->left,item);
    else return search_tree(root->right,item);
}


int main()
{
	treenode *n1 = create_node(1);
	treenode *n2 = create_node(2);
	treenode *n3 = create_node(3);
	treenode *n4 = create_node(4);
    treenode *n5 = create_node(5);
    treenode *n6 = create_node(6);
    treenode *n7 = create_node(7);
    treenode *n8 = create_node(8);
    treenode *n9 = create_node(9);
    n1->left = n4;
	n1->right= n5;
	n5->left= n2;
    n5->right = n3;
    n3->left= n6;
    n3->right = n7;
    n4->right= n9;
    n4->left= n8;
	print_tree(n1,0);
	treenode * root =n1;
    cout<<"-----------------------"<<endl;

    int i=0;
    int len=treeSize(root);
    int new_arr[len];
    BSTtoArray(root, new_arr,i);
    //partition sort algorithm cld hv been called instead of library function at this place
    qsort(new_arr,len,sizeof(new_arr[0]), compare);
    for (int it=0;it<len;it++) cout<<new_arr[it]<<" ";
    cout<<endl<<"-----------------------"<<endl;
	ins_tree(new_arr,0,len-1);
	print_tree(root,0);
    int item=7;
//    cin>>item;
    bool found=search_tree(root,item);
    if(found==false) cout<<"item is not in array"<<endl;
    else cout<<"found item";
    return 0;
}
