#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <queue>
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

int check_height(treenode *node)
{
    if (node == NULL) return 0;
    else return (1+max(check_height(node->left),check_height(node->right)));
}

void sort_tree(treenode *root)
{
    if (root->right==NULL || root->left==NULL)
    {
        return ;
    }
     
    int a=root->value;
    int b=root->left->value;
    int c=root->right->value;
    if(a<b)
    {
        root->value=b;
        root->left->value=a;
    }
    if(a>c)
    {
        root->value=c;
        root->right->value=a;
    }
    sort_tree(root->left);
    sort_tree(root->right);


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

    int x=0;
    int lvl=check_height(n1);
    cout<<"--"<<lvl<<endl;
    while ((x)<lvl)
    {
        sort_tree(n1);
        x=x+1;
    }
    print_tree(n1,0);
}
