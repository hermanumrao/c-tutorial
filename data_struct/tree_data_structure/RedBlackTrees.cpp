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

The four possble cases are :
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
    struct treenode *left;      /* use struct only when you want to insert another tree at that node*/
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
    if (root->parent==NULL) cout<<"|"<<root->height;
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
void fix_ht(treenode *node)     //fixes node->height of full tree
{
    node->height=check_height(node);
    if (node->left !=NULL) fix_ht(node->left);
    if (node->right !=NULL) fix_ht(node->right);
}
void fix_parent(treenode * root)
{
    root->height=check_height(root);
    if (root->height==1) return;
    if (root->left!=NULL)root->left->parent=root;
    if (root->right!=NULL)root->right->parent=root;
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
    temp->left=root;
    fix_parent(temp);
    return temp;
}
treenode * rt_rot( treenode *root)
{
    cout<<"rt_rot"<<endl;
    treenode * temp=root->left;
    root->left=root->left->right;
    temp->right=root;
    fix_parent(temp);
    return temp;
}
treenode * l_rt_rot(treenode *root)
{
    cout<<"l_rt_rot"<<endl;
    root->left=l_rot(root->left);
    root=rt_rot(root);
    fix_parent(root);
    return root;
}
treenode * rt_l_rot(treenode *root)
{
    cout<<"rt_l_rot"<<endl;
    root->right=rt_rot(root->right);
    root=l_rot(root);
    fix_parent(root);
    return root;
}

treenode *add_node(treenode *root,int item)
{
    //when root has no childeren
    if (root->left==NULL && root->right==NULL)
    {
        if (root->value>item) 
        {
            root->left=create_node(item,NULL,NULL,root);
            return root->left;
        }
        else 
        {
            root->right=create_node(item,NULL,NULL,root);
            return root->right;
        }
    }
    //when root has one child
    if (root->value<item && root->right==NULL) 
    {
        root->right=create_node(item,NULL,NULL,root);
        return root->right;
    }
    if (root->value>item && root->left==NULL) 
    {
        root->left=create_node(item,NULL,NULL,root);
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
    cout<<"entry here-"<<root->height<<tree_height<<endl;

    print_tree(root,0);

    if (root->height==tree_height) 
    {
        cout<<"root";
        root->color=false  ;                            //case 0
        return;
    }
    if (root->parent->color==true)
    {
        treenode * y;
        cout<<"entry here-2"<<endl<<endl;
        if (root->parent==root->parent->parent->left)
        {
            if (root->parent->parent->right!=NULL) y =root->parent->parent->right;
            else y=create_node(0,NULL,NULL,NULL,false);
            print_tree(y,0);
            cout<<(y->color==true)<<"====casin_l"<<endl;
            if (y->color==true)
            {
                cout<<"case 1_l ";
                root->parent->color=false;              //case 1
                y->color=false;                         //case 1
                root->parent->parent->color=true;       //case 1
                //print_tree(root->parent->parent,0);
                y=NULL;
                if (tree_height>(root->height+1)) RedBlack_fix(root->parent->parent,tree_height);
            }
            else if (root==root->parent->right)
            {
                cout<<"case 2_l ";
                root=root->parent;                      //case 2
                root=l_rot(root);                       //case 2
                root=root->left;
            }
            root->parent->color=false;                  //case 3
            root->parent->parent->color=true; 
            cout<<"case 3_l ";                            //case 3
            root=rt_rot(root->parent->parent);
            fix_parent(root);                           //case 3
            if (tree_height>(root->height+1)) RedBlack_fix(root->parent->parent,tree_height);
        }
        else if (root->parent==root->parent->parent->right)
        {
            if (root->parent->parent->right==NULL) y =root->parent->parent->right;
            else y=create_node(0,NULL,NULL,NULL,false);
            cout<<(y->color)<<"====casin_r"<<endl;
            if (y->color==true)
            {
                cout<<"case 1_r ";
                root->parent->color=false;              //case 1
                y->color=false;                         //case 1
                root->parent->parent->color=true;       //case 1
                y=NULL;
                if (tree_height>(root->height+1)) RedBlack_fix(root->parent->parent,tree_height);
            }
            else if (root==root->parent->left)
            {
                cout<<"case 2_r ";
                root=root->parent;                      //case 2
                root=rt_rot(root);
                cout<<"came here2";                     //case 2
                root=root->right;
            }
            cout<<"case 3_r ";
            root->parent->color=false;                  //case 3
            root->parent->parent->color=true;           //case 3
            print_tree(root,0);
            root=l_rot(root->parent->parent);           //case 3   
            fix_parent(root);
            y=NULL;
            if (tree_height>(root->height+1)) RedBlack_fix(root->parent->parent,tree_height);
        }
    }
}
 
treenode * ins_RedBlack(treenode * root,int item)
{
    
    if (root==NULL) 
    {
        cout<<"null";
        return  create_node(item,NULL,NULL,NULL,false);
    }
    treenode *root1=add_node(root,item);
    cout<<"after BST insertion1"<<root->height<<endl;
    fix_ht(root);
    cout<<"after BST insertion2"<<root->height<<endl;
    //print_tree(root,0);
    RedBlack_fix(root1,root->height);
    return root;
}

int main()
{
    treenode * root= NULL;
    root=ins_RedBlack(root,1);
    print_tree(root,0);
    cout<<"first_______________________________"<<endl;
    root=ins_RedBlack(root,2);
    print_tree(root,0);
    cout<<"second_______________________________"<<endl;
    cout<<"-->";
    root=ins_RedBlack(root,3);
    print_tree(root,0);
    // root=ins_RedBlack(root,4);
    // cout<<"third"<<endl;
    // print_tree(root,0);
    // root=ins_RedBlack(root,5);
    // cout<<"4th"<<endl;
    // print_tree(root,0);

    // root=ins_RedBlack(root,8);
    // cout<<"5th"<<endl;
    // // print_tree(root,0);
    // // treenode *root1=add_node(root,2);
    // // fix_parent(root);
    // // root=ins_RedBlack(root,2);

    // // print_tree(root,0);
    // // cout<<"6th"<<endl;
    // print_tree(root,0);
    // root=ins_RedBlack(root,1);
    // cout<<"7th"<<endl;
    // print_tree(root,0);
    // root=ins_RedBlack(root,3);
    // cout<<"8th"<<endl;
    // print_tree(root,0);
    

}
