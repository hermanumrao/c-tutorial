//for a tree to be balnaced every subtree must have a maximum difference in hieght equal to 1

#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <queue>
using namespace std ;
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
bool check_balanced(treenode *root)
{
    int a=check_height(root->left);
    int b=check_height(root->right);
    if (a==0 and b==0)
    {
        return true;
    }
    //cout<<"-->"<<a<<b;
    if (a==b or (a+1)==b or a==(b+1))
    {
        //cout<<"gotcha";
        check_balanced(root->left);
        check_balanced(root->right);
    }
    else return false;
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
    //n2->left= n4;
   // n2->right = n5;
    n3->left= n6;
    n3->right = n7;
    n6->right= n9;
    n6->left= n8;

    cout<<check_balanced(n1);

}
/*
   1
  / \ 
 2   3 
/ \  /\
4 5 6  7
   /\
  8  9
        */
