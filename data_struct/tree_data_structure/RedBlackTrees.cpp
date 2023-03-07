/*
BASIC RULES:-


I have taken color as a bool where red=true and black=false
there can be 4 cases for Red Black tree rotations 
  b
 / \
a   c
 \
  z
c is the uncle node for z

The foru possble cases are :
case:0 - node is the root --> for this just cange color of node to black
case:1 - (node->uncle->color==red) then set node->parent=black uncle=black and grand parent=red
case:2 - (node->uncle->color==black(triangle)) then rotate node->parent
case:3 - (node->uncle->color==black(line)) the rotate node->grandparent 
*/
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
    cout<<"value="<<root->value;
    if (level==0) cout<<"|"<<root->height;
    else cout<<"<-"<<root->parent->value<<"|"<<root->height;
    if (root->color==true) cout<<"(red)"<<endl;
    else cout<<"(black)"<<endl;
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
    if (root->height>2)
    {
        fix_parent(root->left);
        fix_parent(root->right);
    }
    else return;
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

treenode *add_node(treenode *root,int item)
{
    //when root has no childeren
    if (root->left==NULL && root->right==NULL)
    {
        if (root->value>item) 
        {
            root->left=create_node(item);
            return root->left;
        }
        else 
        {
            root->right=create_node(item);
            return root->right;
        }
    }
    //when root has one child
    if (root->value<item && root->right==NULL) 
    {
        root->right=create_node(item);
        return root->right;
    }
    if (root->value>item && root->left==NULL) 
    {
        root->left=create_node(item);
        return root->left;
    }
    //in last case if root turns out to have 2 childeren
    if (root->value>item) 
    {
        return add_node(root->left,item);
    }
    else 
    {
        return add_node(root->right,item);
    }
}


void RedBlack_fix(treenode *root,int tree_height)
{
    while (root->parent->color==true)
    {
        if (root->parent==root->parent->parent->left)
        {
            treenode * y =root->parent->parent->right;
            if (y->color==true)
            {
                root->parent->color=false;              //case 1
                y->color=false;                         //case 1
                root->parent->parent->color=true;       //case 1
            }
            else if (root==root->parent->right)
            {
                root=root->parent;                      //case 2
                l_rot(root);                            //case 2
            }
            root->parent->color=false;                  //case 3
            root->parent->parent->color=true;           //case 3
            rt_rot(root->parent->parent);                //case 3
        }
        //else //write
    }
    if (root->height==tree_height) root->color=false  ; //case 0
}
 
treenode * ins_RedBlack(treenode * root,int item,int tree_height)
{
    if (root==NULL) 
    {
        return  create_node(item,NULL,NULL,NULL,false);
        cout<<"null";
    }
    RedBlack_fix(add_node(root,item),tree_height);

}

int main()
{
    treenode *root ;
    print_tree(ins_RedBlack(root,5,0),0);
    print_tree(ins_RedBlack(root,6,1),0);
    print_tree(ins_RedBlack(root,3,2),0);
    // fix_parent(root);
    // print_tree(root,0);
    // int tree_height=root->height;
    

}
