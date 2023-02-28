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
    int height=0;
};
treenode *create_node(int value,treenode * lt=NULL,treenode * rt=NULL)
{
    treenode *node =new treenode();
    node->value=value;
    node->left=lt;
    node->right=rt;
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
void fix_ht(treenode *node)
{
    node->height=check_height(node);
    if (node->left !=NULL) fix_ht(node->left);
    if (node->right !=NULL) fix_ht(node->right);
}

treenode * l_rot( treenode *root)
{
    treenode * temp=root->right;
    root->right=root->right->left;
    root->height= max(check_height(root->left), check_height(root->right)) + 1;
    temp->left=root;
    temp->height= max(check_height(temp->left), check_height(temp->right)) + 1;
    return temp;
}
treenode * rt_rot( treenode *root)
{
    treenode * temp=root->left;
    root->left=root->left->right;
    root->height= max(check_height(root->left), check_height(root->right)) + 1;
    temp->right=root;
    temp->height= max(check_height(temp->left), check_height(temp->right)) + 1;
    return temp;
}
treenode * l_rt_rot(treenode *root)
{
    root->left=l_rot(root->left);
    root=rt_rot(root);
    return root;
}
treenode * rt_l_rot(treenode *root)
{
    root->right=rt_rot(root->right);
    root=l_rot(root);
    return root;
}

void BST2AVL(treenode *node)
{
    if (node==NULL) return ;
    fix_ht(node);
    if (node->height>2 && node->left!=NULL) BST2AVL(node->left);
    if (node->height>2 && node->right!=NULL) BST2AVL(node->right);
    int lh,rh;
    if (node->left==NULL) lh=0;
    else lh=node->left->height;
    if (node->right==NULL) rh=0;
    else rh=node->right->height;
    cout<<lh<<' '<<rh<<endl;
    if ((lh-rh)>=2)
    {
        int llh,lrh;
        if (node->left==NULL) llh=0;
        else llh=node->left->left->height;
        if (node->right==NULL) lrh=0;
        else llh=node->left->right->height;
        cout<<llh<<' '<<lrh;
        lrh;
    }

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
        if (item>node->value)
        {
            node->right=insert_avl(node->right,item);
            if ((check_height(node->right)-check_height(node->left))==2)
            {
                if (item>(node->right->value)) 
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

bool check_node(treenode *root, int item)//search for a specific value within the tree
{
    if (root==NULL) return false;
    if (root->left==NULL && root->right==NULL)return false;
    if (root->value==item)
    {
        if (root->left->height>root->right->height) root=rt_rot(root);
        else root=l_rot(root);
        check_node(root,item);
        return true;
    }
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
    // treenode *root = create_node(0);
    // print_tree(root,0);
    // for ( int i=14;i>0;i--)
    // {
    //     cout<<"-----------------------"<<endl;  //this part of code is to test the insert_AVL function
    //     root=insert_avl(root,int(i));            //insert_avl function has beeen tested ad is completely working
    //     print_tree(root,0);
    // } 

    // int a_find=7;
    // //cin>> a_find;            ///this part of the code is to check if a number is present in the part of code
    // if (check_node(root,a_find)==true) cout<<"found value"<<endl;
    // else cout<<"not found value"<<endl;
    // print_tree(root,0);

    treenode *root = create_node(1,NULL,create_node(3,create_node(6),create_node(7)));
    print_tree(root,0);
    fix_ht(root);
    print_tree(root,0);
    BST2AVL(root);
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