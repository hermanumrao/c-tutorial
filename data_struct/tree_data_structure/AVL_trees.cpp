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
    struct treenode *parent;

};
treenode *create_node(int value)
{
	treenode *node =new treenode();
	node->value=value;
	node->left=NULL;
	node->right=NULL;
    node->parent=NULL;
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

treenode * rt_rot(treenode *root)
{
    root->left->right=create_node(root->value);
    root=root->left;
    delete(root->parent);
    return root; 
}
treenode * l_rot(treenode *root)
{
    root->right->left=create_node(root->value);
    root=root->right;
    delete(root->parent);
    return root; 
}

bool search_tree(treenode *root, int item)
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
bool ins_node(treenode *root,int item)
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

treenode *ins_tree(int *arr,int start,int end)
{
    if (end<start) return NULL;
    int mid=(start+end)/2;
    treenode *root=create_node(arr[mid]);
    root->left=ins_tree(arr,start,mid-1);
    root->right=ins_tree(arr,mid+1,end);
    return root;
}

void insertion(treenode *root,int item)
{
    bool found=search_tree(root,item);
    if(found==false) cout<<"item is not in array"<<ins_node(root,item)<< endl;
    else cout<<"item already exists"<<endl;
}

int main()
{
    int arr[]={};
    treenode *root = create_node(arr[0]);
    int l=sizeof(arr)/sizeof(arr[0]);
    int i=1;
    root=ins_tree(arr,0,l-1);
    print_tree(root,0);
    //insertion(root,4);
    //insertion(root,5);
    cout<<"-----------------------"<<endl;
    print_tree(root,0);
    int bal=check_height(root);
    cout<<"bal="<<bal;
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
