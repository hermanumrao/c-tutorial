#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <queue>
using namespace std ;

/*
  1
 / \ 
2   3 
\   /\
 4 5  6
   /\
  7  8
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
	node->value =value;
	node->left=NULL;
	node->right=NULL;
	return node;
}

int check_height(treenode *node)//returns the height of the tree
{
    if (node == NULL) return 0;
    else return (1+max(check_height(node->left),check_height(node->right)));
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

    //print_tabs(level);
    cout<<"value="<<root->value<<endl;
    print_tabs(level);
	cout<<"left=";
	print_tree(root->left,level+1);

    print_tabs(level);
	cout<<"right=";
	print_tree(root->right,level+1);
    cout<<endl;
}

treenode * rt_rot( treenode *root)
{
    treenode * temp=root->right;
    root->right=root->right->left;
    //root->height= max(check_height(root->left), check_height(root->right)) + 1;
    temp->left=root;
    //temp->height= max(check_height(temp->left), check_height(temp->right)) + 1;
    return temp;
}
treenode * l_rot( treenode *root)
{
    treenode * temp=root->left;
    root->left=root->left->right;
    //root->height= max(check_height(root->left), check_height(root->right)) + 1;
    temp->right=root;
    //temp->height= max(check_height(temp->left), check_height(temp->right)) + 1;
    return temp;
}
treenode * rt_l_rot(treenode *root)
{
    root->left=rt_rot(root->left);
    root=l_rot(root);
    return root;
}
treenode * l_rt_rot(treenode *root)
{
    root->right=l_rot(root->right);
    root=rt_rot(root);
    return root;
}

treenode* tree2AVl(treenode *node)
{
    if (node==NULL) return node;
    int a=check_height(node->left);
    int b=check_height(node->right);
    cout<<"ht="<<a<<b<<endl;
    if ((a-b)==2)
    {
        if (node->left->right==NULL) node=l_rot(node);
        else node=rt_l_rot(node);
    }
    else if ((b-a)==2)
    {
        if (node->right->left==NULL) node=rt_rot(node);
        else node=l_rt_rot(node);
    }
    else 
    {
        if (a>1) return node->left=tree2AVl(node->left);
        if (b>1) return node->right=tree2AVl(node->right);
    }
}

int main()
{
	treenode *n1 = create_node(1);
	treenode *n2 = create_node(2);
	treenode *n3 = create_node(3);
	// treenode *n4 = create_node(4);
 //    treenode *n5 = create_node(5);
 //    treenode *n6 = create_node(6);
 //    treenode *n7 = create_node(7);
 //    treenode *n8 = create_node(8);
 //    treenode *n9 = create_node(9);
 //    treenode *n10 = create_node(10);
 //    treenode *n11 = create_node(11);

	n3->left = n2;
	//n8->right= n10;
	// n2->right= n6;
    n2->left = n1;
 //    n6->right= n7;
 //    n6->left = n4;
 //    n4->right= n5;
 //    n4->left = n3;
 //    n10->right= n11;
 //    n10->left = n9;
 //    // n5->right= n8;
    treenode * root =n3;

    print_tree(root,0);
    cout<<"---------------------------------"<<endl;
    //root->right=l_rot(root->right);
    //root=rt_rot(root);
    root=tree2AVl(root);
    print_tree(root,0);

}
