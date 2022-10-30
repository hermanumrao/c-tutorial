#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std ;

/*
      1
     / \ 
    2   3 
   / \  /\
  4  5 6  7
 /\
8  9
        */

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


//part of printing
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
//functin to create tree out of array
void ins_val(treenode *root,int *arr,int &i,int maxl)
{
    if (2*i+1>=maxl) return;
    root->left=crt_node(arr[2*i+1]);
    if (2*i+2>=maxl) return;
    root->right=crt_node(arr[2*i+2]);
    int a=2*i+1;
    ins_tree(root->left,arr,a,maxl);

    int b=2*i+2;
    ins_tree(root->right,arr,b,maxl);

}

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9};//insert your array here
    treenode *root = crt_node(arr[0]);
    int i=0;
    ins_tree(root,arr,i,(sizeof(arr)/sizeof(arr[0])));
    print_tree(root,0);
    return 0;
}
