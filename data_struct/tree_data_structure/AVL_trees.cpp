#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <queue>
using namespace std ;
struct treenode
{
	int value;
	/* use struct only when you want to insert another tree at that node*/
	struct treenode *left;
	struct treenode *right;
    int height;

};
treenode *create_node(int value)
{
	treenode *node =new treenode();
	node->value=value;
	node->left=NULL;
	node->right=NULL;
    node->height=1;
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
    cout<<"value="<<root->value<<'|'<<root->height<<endl;
    print_tabs(level);
    cout<<"left=";
    print_tree(root->left,level+1);

    print_tabs(level);
    cout<<"right=";
    print_tree(root->right,level+1);
    cout<<endl;
}

int check_height(treenode *node)//returns the height of the tree
{
    if (node == NULL) return 0;
    else return (1+max(check_height(node->left),check_height(node->right)));
}

treenode * rt_rot( treenode *root)
{
    treenode * temp=root->right;
    root->right=root->right->left;
    root->height= max(check_height(root->left), check_height(root->right)) + 1;
    temp->left=root;
    temp->height= max(check_height(temp->left), check_height(temp->right)) + 1;
    return temp;
}
treenode * l_rot( treenode *root)
{
    treenode * temp=root->left;
    root->left=root->left->right;
    root->height= max(check_height(root->left), check_height(root->right)) + 1;
    temp->right=root;
    temp->height= max(check_height(temp->left), check_height(temp->right)) + 1;
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
bool search_tree(treenode *root, int item)//checks if the value to be inserted already exits in tree
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
bool ins_node(treenode *root,int item)//inserts new node
{
    //when root has no childeren
    if (root->left==NULL && root->right==NULL)
    {
        if (root->value>item) 
        {
            root->left=create_node(item);
            return true;
        }
        else 
        {
            root->right=create_node(item);
            return true;
        }
    }
    //when root has one child
    if (root->value<item && root->right==NULL) 
    {
        root->right=create_node(item);
        return true;
    }
    if (root->value>item && root->left==NULL) 
    {
        root->left=create_node(item);
        return true;
    }
    //in last case if root turns out to have 2 childeren
    if (root->value>item) 
    {
        return ins_node(root->left,item);
    }
    else 
    {
        return ins_node(root->right,item);
    }
}

void insertion(treenode *root,int item)//insert new elment to BST by calling ins_node fn
{
    bool found=search_tree(root,item);
    if(found==false) cout<<"item is not in array"<<ins_node(root,item)<< endl;
    else cout<<"item already exists"<<endl;
}

int main()
{
    treenode *root = create_node(2);
    int i=1;
    print_tree(root,0);
    insertion(root,1);
    insertion(root,3);
    cout<<"-----------------------"<<endl;
    print_tree(root,0);
    cout<<"-----------------------"<<endl;
    print_tree(root,0);
    return 0;
}
/*
    1
   /
  2
 /
3
  1
 / \ 
2   3 

		*/
