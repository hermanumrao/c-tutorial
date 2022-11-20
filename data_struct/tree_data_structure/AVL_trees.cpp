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

treenode *insert_avl(treenode*node, int item)
{
    if (node==NULL)return create_node(item);
    else
    {
        if (item<node->value)
        {
            node->left=insert_avl(node->left,item);
            if ((check_height(node->left)-check_height(node->right))==2)
            {
                if (item<(node->left->value)) 
                {
                    cout<<"l_rot"<<endl;
                    node=l_rot(node);
                }
                else 
                {
                    cout<<"rt_l_rot"<<endl;
                    node=rt_l_rot(node);
                }
            }
        }
        if (item>node->value)
        {
            node->right=insert_avl(node->right,item);
            if ((check_height(node->right)-check_height(node->left))==2)
            {
                if (item>(node->right->value)) 
                {
                    cout<<"rt_rot"<<endl;
                    node=rt_rot(node);
                }
                else 
                {
                    cout<<"l_rt_rot"<<endl;
                    node=l_rt_rot(node);
                }
            }
        }
        node->height=check_height(node);
        return node;
        
    }
}

int del_successor(treenode *node)//deletes the successor node and returns val of the successor node to the original function
{
    if (node->left->left!=NULL) return del_successor(node->left);
    else
    {
        int a=node->left->value;
        delete(node->left);
        node->left=NULL;
        return a;
    }
}
bool check_node(treenode *root, int item)
{
    if (root==NULL) return false;
    if (root->left==NULL && root->right==NULL)return false;
    if (item<(root->value))
    {
        if(root->left->value==item)
        {
            if (root->left->right!=NULL && root->left->left!=NULL) 
            {
                root->left->value=del_successor(root->left);
                return true;
            }
            else if (root->left->right==NULL)
            {
                treenode *tmp=root->left->left;
                delete(root->left);
                root->left=tmp;
                return true;
            }
            else 
            {
                treenode *tmp=root->left->right;
                delete(root->left);
                root->left=tmp;
                return true;
            }
        }
        else return check_node(root->left,item);
    }
    else
    {
        if (root->right->value==item) 
        {
            if (root->right->right!=NULL || root->right->left!=NULL) 
            {
                root->right->value=del_successor(root->right);
                return true;
            }
            else if (root->right->left==NULL)
            {
                treenode *tmp=root->right->right;
                delete(root->right);
                root->right=tmp;
                return true;
            }
            else 
            {
                treenode *tmp=root->right->left;
                delete(root->right);
                root->right=tmp;
                return true;
            }
        }
        else return check_node(root->right,item);
    }
}


int main()
{
    treenode *root = create_node(1);
    int i=1;
    print_tree(root,0);
    root=insert_avl(root,2);
    root=insert_avl(root,3);
    root=insert_avl(root,5);
    root=insert_avl(root,4);
    root=insert_avl(root,7);
    root=insert_avl(root,6);
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
