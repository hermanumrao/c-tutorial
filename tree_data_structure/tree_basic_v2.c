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


/* Print nodes at a given level */
void printLevelOrder(treenode *root)
{
    // Base Case
    int a;
    if (root == NULL) return;
 
    // Create an empty queue for level order traversal
    queue<treenode *> q;
 
    // Enqueue Root and initialize height
    q.push(root);
    a=0;
    while (q.empty() == false)
    {
        // nodeCount (queue size) indicates number
        // of nodes at current level.
        int nodeCount = q.size();
 
        // Dequeue all nodes of current level and
        // Enqueue all nodes of next level
        while (nodeCount > 0)
        {
            treenode *node = q.front();
            cout << node->value << "_";
            q.pop();
            if (node->left != NULL)
            {
                
                q.push(node->left);
            }
            if (node->right != NULL)
            {
                
                q.push(node->right);
            }
            nodeCount--;
        }
        cout << endl;
    }
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

	n1->left = n2;
	n1->right= n3;
	n2->right= n4;
    n3->left = n5;
    n3->right= n6;
    n5->left = n7;
    n5->right= n8;

	print_tree(n1,0);

}
