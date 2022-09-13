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

// void print_tree(treenode *root)
// {
// 	if (root==NULL)
// 	{
// 		printf("%s\n","--" );
// 		return;
// 	}
// 	printf("left ");
// 	print_tree(root->left);
// 	printf("value=%d",root->value );
// 	printf("right ");
// 	print_tree(root->right);
// }


/* Print nodes at a given level */
void printLevelOrder(treenode *root)
{
    // Base Case
    if (root == NULL) return;
 
    // Create an empty queue for level order traversal
    queue<treenode *> q;
 
    // Enqueue Root and initialize height
    q.push(root);
 
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
            cout << node->value << " ";
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            nodeCount--;
        }
        cout << endl;
    }
}

void draw_tree()
{

}

int main()
{
	treenode *n1 = create_node(1);
	treenode *n2 = create_node(2);
	treenode *n3 = create_node(3);
	treenode *n4 = create_node(4);
	treenode *n5 = create_node(5);

	n1->left = n2;
	n1->right= n3;
	n3->left= n4;
	n3->right= n5;

	printLevelOrder(n1);

}
/*
  1
 / \ 
2   3 

		*/
