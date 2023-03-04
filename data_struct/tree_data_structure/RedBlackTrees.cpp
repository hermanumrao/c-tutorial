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
    int height=0;
    bool color;
};
treenode *create_node(int value, treenode * lt=NULL,treenode * rt=NULL,treenode * pt=NULL,bool cl=true)
{
    treenode *node =new treenode();
    node->value=value;
    node->parent=pt;
    node->left=lt;
    node->right=rt;
    node->height=1;
    node->color=cl;
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
void fix_parent(treenode * root)
{
    fix_ht(root);
    root->left->parent=root;
    root->right->parent=root;
    if (root->height>1)
    {
        fix_parent(root->left);
        fix_parent(root->right);
    }
}

treenode * l_rot( treenode *root)
{
    cout<<"l_rot"<<endl;
    treenode * temp=root->right;
    root->right=root->right->left;
    root->height= max(check_height(root->left), check_height(root->right)) + 1;
    temp->left=root;
    temp->height= max(check_height(temp->left), check_height(temp->right)) + 1;
    return temp;
}
treenode * rt_rot( treenode *root)
{
    cout<<"rt_rot"<<endl;
    treenode * temp=root->left;
    root->left=root->left->right;
    root->height= max(check_height(root->left), check_height(root->right)) + 1;
    temp->right=root;
    temp->height= max(check_height(temp->left), check_height(temp->right)) + 1;
    return temp;
}
treenode * l_rt_rot(treenode *root)
{
    cout<<"l_rt_rot"<<endl;
    root->left=l_rot(root->left);
    root=rt_rot(root);
    return root;
}
treenode * rt_l_rot(treenode *root)
{
    cout<<"rt_l_rot"<<endl;
    root->right=rt_rot(root->right);
    root=l_rot(root);
    return root;
}

// viod prlvlorder(treenode *node)
// {

// }
 

int main()
{
    treenode *root = create_node(0,create_node(1));
    print_tree(root,0);
    

}
