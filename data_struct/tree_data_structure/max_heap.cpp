//max_heap
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <queue>
#include <stdbool.h>
using namespace std ;

/*
INITIAL INPUT
   4
  / \ 
 2   8 
/ \  /\
1 3 6  9
   /\
  5  7

OUTPUT:
   9
  / \ 
 3   8 
/ \  /\
1 3 7  4
   /\
  5  6

INITIAL INPUT(2)
   4
  / \ 
 2   8 
/ \  /\
1 3 6  
   /\
  5  7

OUTPUT:
   9
  / \ 
 3   7 
/ \  /
1 3 6  
   /\
  5  4
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

int check_height(treenode *node)
{
    if (node == NULL)
        return 0;
    else {
        /* compute the depth of each subtree */
        int lDepth = check_height(node->left);
        int rDepth = check_height(node->right);
 
        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}


void sort_tree(treenode *root)
{
    if (root==NULL || (root->right==NULL && root->left==NULL))
    {
        return ;
    }
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
    sort_tree(root->right);
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
    sort_tree(root->left);
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
    n4->left = n2;
    n4->right= n8;
    n2->left= n1;
    n2->right = n3;
    n8->left= n6;
    n8->right = n9;
    n6->right= n7;
    n6->left= n5;
    print_tree(n4,0);
    cout<<"-----------------------"<<endl;

    int x=0;
    int lvl=check_height(n4);
    cout<<"level="<<lvl<<endl;
    while ((x+1)<lvl)
    {
        sort_tree(n4);
        x=x+1;
    }
    print_tree(n4,0);
    cout<<"-----------------------"<<endl;
}
