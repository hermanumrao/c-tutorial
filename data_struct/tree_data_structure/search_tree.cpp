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



void search_tree(treenode *root , int item, bool &ans)
{
    if (root->value==item)
    {
        ans = true;
        return;
    }
    
    if (root->left!=NULL)
    {
        search_tree(root->left,item,ans);
    }
    if (root->right!=NULL)
    {
        search_tree(root->right,item,ans);
    }  
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
    n1->left = n2;
    n1->right= n3;
    n2->left= n4;
    n2->right = n5;
    n3->left= n6;
    n3->right = n7;
    n6->right= n9;
    n6->left= n8;
    print_tree(n1,0);
    cout<<"-----------------------"<<endl;
    int item;
    cout<<"input item to search"<<endl;
    cin>>item;
    bool ans=false;
    search_tree(n1,item,ans);
    if (ans==true)
    {
        cout<<"found";
    }
    else
    {
        cout<<"missing";
    }
}
