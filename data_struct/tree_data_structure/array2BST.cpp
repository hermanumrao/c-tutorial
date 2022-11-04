//convert array to BST
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <bits/stdc++.h>
using namespace std ;


/*
[1,2,3,4,5,6,7,8,9]

       5
     /  \ 
    2    7 
   / \   /\
  1  3  6  8
      \    \
       4    9
        
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
    int i=1;
    root=ins_tree(arr,0,l-1);
    print_tree(root,0);
    return 0;
}

