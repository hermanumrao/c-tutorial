//program to convert BST to Array
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <bits/stdc++.h>
using namespace std ;

// the root of a binary search tree is the Median of sorted array
// left node < root < right node
// left hand side is always smaller than right hand side 
// this is basically inoerder traversal
// to any travrsal method we can pass aany binary tree

/*
       5
     /  \ 
    2    7 
   / \   /\
  1  3  6  8
      \    \
       4    9


[1,2,3,4,5,6,7,8,9] // inorder traversal
 [5,2,7,1,3,6,8,4,9]
        
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
    int arr[]={1,2,3,4,5,6,7,8,9};
    treenode *root = crt_node(arr[0]);
    int l=sizeof(arr)/sizeof(arr[0]);
    root=ins_tree(arr,0,l-1);
    print_tree(root,0);
    int len=treeSize(root);
    int new_arr[len];
    int i=0;
    BSTtoArray(root, new_arr,i);
    for (int it=0;it<len;it++) cout<<arr[it]<<" ";
    return 0;
}

