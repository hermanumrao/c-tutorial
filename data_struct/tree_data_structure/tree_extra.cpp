

//program to convert BST to Array

// the root of a binary search tree is the Median of sorted array
// left node < root < right node
// left hand side is always smaller than right hand side 
// to any travrsal method we can pass aany binary tree

/*
       5
     /  \ 
    2    7 
   / \   /\
  1  3  6  8
      \    \
       4    9


	[1,2,3,4,5,6,7,8,9] // inorder traversal	Used for generating sorted array from binary search tree
	[5,2,1,3,4,7,6,8,9] // preorder traversal	Used for search algorithms
	[1,4,3,2,6,9,8,7,5] // postorder traversal	Used for solving polynomials | postfix (2*(3+4))

Breadth First Traversal:[5,2,7,1,3,6,8,4,9]       (Queue)  // level order
Depth First search:     [5,7,8,9,6,2,3,4,1]       (stack)  
	shortest path of network (Dijkstra's algorithm)
	make partition of tree/graph
*/

struct treenode
{
    int value;
    struct treenode *left;
    struct treenode *right;

};
treenode *crt_node(int value )
{
    treenode *node =new treenode();
    node->value=value;
    node->left=NULL;
    node->right=NULL;
    return node;
}

int treeSize(treenode* root) {
    if(root == NULL) return 0;
    else
        return treeSize(root->left) + treeSize(root->right) + 1;
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

void BSTtoArray(treenode *root, int *arr, int &pos)
{
    if(root == NULL) return;

    BSTtoArray(root->left, arr, pos);
    arr[pos++] = root->value;
    BSTtoArray(root->right,arr,pos);

}

treenode *ins_tree(int *arr,int start,int end)
{
    if (end<start) return NULL;
    int mid=(start+end)/2;
    treenode *root=crt_node(arr[mid]);
    root->left=ins_tree(arr,start,mid-1);
    root->right=ins_tree(arr,mid+1,end);
    return root;
}

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    treenode *root = crt_node(arr[0]);
    int l=sizeof(arr)/sizeof(arr[0]);
    root=ins_tree(arr,0,l-1);
    print_tree(root,0);
    int len=treeSize(root);
    int new_arr[len];
    int i=0;
    BSTtoArray(root, new_arr,i);
    for (int it=0;it<len;it++) cout<<arr[it]<<" ";
    return 0;
}



// CPLUSTest.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "printTree.h"
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

#include <queue> 

#define WIDTH 5 


/*
 static Singleton getInstance() {
  if(singleton == null) {
    synchronized(Singleton.class) {
      if(singleton == null) {
        singleton = new Singleton();
      }
    }
  }
  return singleton;
} 

You don't need recursion to reverse a singly-linked list. 

Node *Reverse (Node *p) 
{ 
   Node *pr = NULL; 
   while (p != NULL) 
   { 
      Node *tmp = p->next; 
      p->next = pr; 
      pr = p; 
      p = tmp; 
   } 
   return pr; 
}

Node *reverseList(Node *current, Node *parent) 
{ 
        Node *revHead; 
   if(current == null) 
      revHead = parent; 
   else 
   { 
      revHead = reverseList(current->next,current); 
      current->next = parent;       
   } 
   return revHead; 
} 

*/
int myprintf ( char *str , int width ) 
{ 
    
    printf ( "%*s\n", width,  str ); 
    return 0; 
} 

#include <stdio.h> 


/*
 The code isBST() is the answer to the question: 
Given a binary tree, programmatically we need to prove it is a binary search tree.
If the given binary tree is a binary search tree, then the BSD traversal should output the elements in increasing order and inorder.
 
 */

void reverseOrderPrint(struct Tree *node)
{
	if(node == NULL) return;
	if(node->left == NULL && node->right == NULL) {
		cout << node->data << " ";
		return;
	}
	
	reverseOrderPrint(node->right);
	cout << node->data << " ";
	reverseOrderPrint(node->left);
}


mynode *root; 

void add_node(int value); 
void postorder(mynode *root); // Time complexity of traversals is O(n). 
void inorder(mynode *root); ///Time complexity of traversals is O(n). 
void preorder(mynode *root);// Time complexity of traversals is O(n). 
/*
Depth first search is another way of traversing graphs, which is closely related to preorder traversal of a tree. Recall that preorder traversal simply visits each node before its children. It is most easy to program as a recursive routine: 
pathfind in Hoffman
    preorder(node v)
    {
    visit(v);
    for each child w of v
        preorder(w);
    }


preorder(node)
  if node == null then return
  visit(node)
  preorder(node.left) 
  preorder(node.right)

	

iterativePreorder(node)    //
  parentStack = empty stack
  while (not parentStack.isEmpty() or node ≠ null)
  {
    if (node ≠ null) 
      visit(node)
      if (node.right ≠ null) parentStack.push(node.right) 
      node = node.left   
    else     
      node = parentStack.pop()
  }
*/

//heap sorting is  ->  priority queue  

//about smpart pointer
//http://www.codeproject.com/Articles/15351/Implementing-a-simple-smart-pointer-in-c 


void iterativePreorder(mynode *root); 
void iterativeInorder (mynode *root); 
void iterativePostorder(mynode *root); 

int setbf(mynode *p) ;

void levelOrderTraversal(mynode *root); // ==  BSD breath first serach 

int main(int argc, char* argv[]) 
{ 
   char test[]="ArvindUmrao";

  myprintf(test,1);

  root = NULL; 
   
  add_node(5); 
  add_node(1); 
  add_node(-20); 
  add_node(100); 
  add_node(23); 
  add_node(67); 
  add_node(13); 
   
  printf("\n\n\nLEVEL ORDER TRAVERSAL\n\n"); 


  setbf(root);

  levelOrderTraversal(root); 

  
//	getch(); 
  printf("\nPreorder (R)    : "); 
  preorder(root); 
  printf("\nPreorder (I)    : "); 
  iterativePreorder(root); 

  printf("\n\nPostorder (R)   : "); 
  postorder(root); 
  printf("\nPostorder (R)   : "); 
  iterativePostorder(root); 
   
   
  printf("\n\nInorder (R)     : "); 
  inorder(root); 
  printf("\nInorder (I)     : "); 
  iterativeInorder(root); 
	//getch(); 
} 

// Function to add a new node to the BST 
void add_node(int value) 
{ 
   mynode *prev, *cur, *temp; 
    
   temp        = (mynode *) malloc(sizeof(mynode)); 
   temp->value = value; 
   temp->right = NULL; 
   temp->left  = NULL; 

   if(root==NULL) 
   { 
     printf("\nCreating the root..\n"); 
     root = temp; 
     return; 
   } 

   prev=NULL; 
   cur=root; 

   while(cur!=NULL) 
   { 
      prev=cur; 
      cur=(value<cur->value)?cur->left:cur->right; 
   } 

   if(value < prev->value) 
     prev->left=temp; 
   else 
     prev->right=temp; 
} 


// Recursive Preorder 
void preorder(mynode *root) 
{ 
  if(root) 
  { 
    printf("[%d] ", root->value); 
    preorder(root->left); 
    preorder(root->right); 
  } 
} 

// Iterative Preorder 
void iterativePreorder(mynode *root) 
{ 
  mynode *save[100]; 
  int top = 0; 

  if (root == NULL) 
  { 
    return; 
  } 
   
  save[top++] = root; 
  while (top != 0) 
  { 
    root = save[--top]; 

    printf("[%d] ", root->value); 

    if (root->right != NULL) 
      save[top++] = root->right; 
    if (root->left != NULL) 
      save[top++] = root->left; 
  } 
} 

// Recursive Postorder 
void postorder(mynode *root) 
{ 
  if(root) 
  { 
    postorder(root->left); 
    postorder(root->right); 
    printf("[%d] ", root->value); 
  } 
} 

// Iterative Postorder 
void iterativePostorder(mynode *root) 
{ 
  struct 
  { 
    mynode *node; 
    unsigned vleft :1;   // Visited left? 
    unsigned vright :1;  // Visited right? 
  }save[100]; 
   
  int top = 0; 
   
  save[top++].node = root; 

  while ( top != 0 ) 
  { 
      /* Move to the left subtree if present and not visited */ 
      if(root->left != NULL && !save[top].vleft) 
      { 
          save[top].vleft = 1; 
          save[top++].node = root;   
          root = root->left; 
          continue; 
      } 

      /* Move to the right subtree if present and not visited */ 
      if(root->right != NULL && !save[top].vright ) 
      { 
          save[top].vright = 1; 
          save[top++].node = root; 
          root = root->right; 
          continue; 
      } 
     
      printf("[%d] ", root->value); 

      /* Clean up the stack */ 
      save[top].vleft = 0; 
      save[top].vright = 0; 

      /* Move up */ 
      root = save[--top].node; 
   } 
} 


// Recursive Inorder 
void inorder(mynode *root) 
{ 
  if(root) 
  { 
    inorder(root->left); 
    printf("[%d] ", root->value); 
    inorder(root->right); 
  } 
} 


// Iterative Inorder.. 
void iterativeInorder (mynode *root) 
{ 
  mynode *save[100]; 
  int top = 0; 

  while(root != NULL) 
  { 
      while (root != NULL) 
      { 
           if (root->right != NULL) 
           { 
             save[top++] = root->right; 
           } 
           save[top++] = root; 
           root = root->left; 
      } 
     
      root = save[--top]; 
      while(top != 0 && root->right == NULL) 
      { 
          printf("[%d] ", root->value); 
          root = save[--top]; 
      } 
     
      printf("[%d] ", root->value); 
      root = (top != 0) ? save[--top] : (mynode *) NULL; 
  } 
} 


// Depth First Search Also Preorder Search. Output matches
EnStack(root);

while(!isEmpty())
{
node = Top();
print(node);
Enqueue(node->right);   // stack // Note Right First other wish 
Enqueue(node->left);
//print(node);
}


/*
Enqueue(root);

while(!isEmpty())
{
node = Dequeue();
print(node);
Enqueue(node->left);
Enqueue(node->right);
//print(node);
}
 */

// Level order traversal.. 
void levelOrderTraversal(mynode *root)  // Breadth-first search // print all level in increasing oder in binary tree. 90 Degree rotation of inorder looks similar to Level order search. See the hoffman.cpp
{ 
	 printf("levelOrderTraversal\n"); 

  //mynode *queue[100] = {(mynode *)0}; // Important to initialize! 
  int size = 0; 
  int queue_pointer = 0; 
  
  std::queue< mynode*> queue;

  while(root) 
  { 
      printf("[%d,%d]  ", root->value, root->height); 

      if(root->left) 
      { 
        queue.push(  root->left); 
      } 

      if(root->right) 
      { 
        queue.push( root->right); 
      } 
       
	  if(!queue.size())
	  {
		  break;
	  }
		root = queue.front();  
		queue.pop();
  } 
} 

// Recursive function to set the balancing factor 
// of each node starting from the root! 
int setbf(mynode *p) 
{ 
   int templ, tempr; 
   int count; 
   count = 1; 

   if(p == NULL) 
   { 
     return(0); 
   } 
   else 
   { 
       templ = setbf(p->left); 
       tempr = setbf(p->right); 

       if(templ < tempr) 
         count = count + tempr; 
       else 
         count = count + templ; 
   } 

   // Set the nodes balancing factor. 
   printf("\nNode = [%3d], Left sub-tree height = [%1d], Right sub-tree height = [%1d], BF = [%1d]\n", 
          p->value, templ, tempr, (tempr - templ)); 
   p->bf = tempr - templ; 
   p->height = count ;
   return(count); 
} 



void remove(int d , mynode* root)
{
    //Locate the element
    bool found = false;

    mynode* curr;
    mynode* parent;
    curr = root;
    
    while(curr != NULL)
    {
         if(curr->value == d)
         {
            found = true;
            break;
         }
         else
         {
             parent = curr;
             if(d>curr->value) curr = curr->right;
             else curr = curr->left;
         }
    }
    if(!found)
		 {
        printf(" Data not found! \n");
        return;
    }


		 // 3 cases :
    // 1. We're removing a leaf node
    // 2. We're removing a node with a single child
    // 3. we're removing a node with 2 children

    // Node with single child
    if((curr->left == NULL && curr->right != NULL)|| (curr->left != NULL && curr->right == NULL))
    {
       if(curr->left == NULL && curr->right != NULL)
       {
           if(parent->left == curr)
           {
             parent->left = curr->right;
             delete curr;
           }
           else
           {
             parent->right = curr->right;
             delete curr;
           }
       }
       else // left child present, no right child
       {
          if(parent->left == curr)
           {
             parent->left = curr->left;
             delete curr;
           }
           else
           {
             parent->right = curr->left;
             delete curr;
           }
       }
     return;
    }

		 //We're looking at a leaf node
		 if( curr->left == NULL && curr->right == NULL)
    {
        if(parent->left == curr) parent->left = NULL;
        else parent->right = NULL;
		 		 delete curr;
		 		 return;
    }


    //Node with 2 children
    // replace node with smallest value in right subtree
    if (curr->left != NULL && curr->right != NULL)
    {
        mynode* chkr;
        chkr = curr->right;
        if((chkr->left == NULL) && (chkr->right == NULL))
        {
            curr = chkr;
            delete chkr;
            curr->right = NULL;
        }
        else // right child has children
        {
            //if the node's right child has a left child
            // Move all the way down left to locate smallest element

            if((curr->right)->left != NULL)
            {
                mynode* lcurr;
                mynode* lcurrp;
                lcurrp = curr->right;
                lcurr = (curr->right)->left;
                while(lcurr->left != NULL)
                {
                   lcurrp = lcurr;
                   lcurr = lcurr->left;
                }
		curr->value = lcurr->value;
                delete lcurr;
                lcurrp->left = NULL;
           }
           else
           {
               mynode* tmp;
               tmp = curr->right;
               curr->value = tmp->value;
	       curr->right = tmp->right;
               delete tmp;
           }

        }
		 return;
    }

}

/*
IsHeightBalanced(tree, out height)
    if (tree is empty)
        height = 0
        return true
    balance = IsHeightBalanced(tree.left, heightleft) and IsHeightBalanced(tree.right, heightright)
    height = max(heightleft, heightright)+1
    return balance and abs(heightleft - heightright) <= 1  
 * 
 */

/*
height( T, v )
{
    if t.isExternnal( v ) return 0;
    else
        
        h = 0
        
                for each w E T.Children(v)
                {
                    
                    h = max(h, height(T,w));
                    return 1 + h
                }
        
    
}
 **/
 
 
 Pre-order traversal while duplicating nodes and values can make a complete duplicate of a binary tree. It can also be used to make a prefix expression (Polish notation) from expression trees: traverse the expression tree pre-orderly.
void pathFinder(Node* node, int path[], int level)
Alos it is used in Hoffman coding to print code from top(root) to leave) please check the hoffman code. It is pathfinder


In-order traversal is very commonly used on ( BST) binary search trees because it returns values from the underlying set in order, according to the comparator that set up the binary search tree (hence the name).

Post-order traversal while deleting or freeing nodes and values can delete or free an entire binary tree. It can also generate a postfix representation of a binary tree



 
 DFS-iterative (G, s):                                   //Where G is graph and s is source vertex
      let S be stack
      S.push( s )            //Inserting s in stack 
      mark s as visited.
      while ( S is not empty):
          //Pop a vertex from stack to visit next
          v  =  S.top( )
         S.pop( )
         //Push all the neighbours of v in stack that are not visited   
        for all neighbours w of v in Graph G:
            if w is not visited :
                     S.push( w )         
                    mark w as visited


    DFS-recursive(G, s):
        mark s as visited
        for all neighbours w of s in Graph G:
            if w is not visited:
                DFS-recursive(G, w)
                
                
                
              How to find connected components using DFS?

A graph is said to be disconnected if it is not connected, i.e. if two nodes exist in the graph such that there is no edge in between those nodes. In an undirected graph, a connected component is a set of vertices in a graph that are linked to each other by paths.

Consider the example given in the diagram. Graph G is a disconnected graph and has the following 3 connected components.

    First connected component is 1 -> 2 -> 3 as they are linked to each other
    Second connected component 4 -> 5
    Third connected component is vertex 6
  
                
                Depth-first search. Depth-first search (DFS) is an algorithm for traversing or searching tree or graph data structures. One starts at the root (selecting some arbitrary node as the root in the case of a graph) and explores as far as possible along each branch before backtracking.
                
                
           Dijkstra's algorithm is an algorithm for finding the shortest paths between nodes in a graph, which may represent, for example, road networks. It was conceived by computer scientist Edsger W. Dijkstra in 1956 and published three years later.     
                

Applications of Depth First Search ( preOrder)

Depth-first search (DFS) is an algorithm (or technique) for traversing a graph.

Following are the problems that use DFS as a bulding block.

1) For an unweighted graph, DFS traversal of the graph produces the minimum spanning tree and all pair shortest path tree.

2) Detecting cycle in a graph
A graph has cycle if and only if we see a back edge during DFS. So we can run DFS for the graph and check for back edges. (See this for details)

3) Path Finding
We can specialize the DFS algorithm to find a path between two given vertices u and z.
i) Call DFS(G, u) with u as the start vertex.
ii) Use a stack S to keep track of the path between the start vertex and the current vertex.
iii) As soon as destination vertex z is encountered, return the path as the
contents of the stack

See this for details.

4) Topological Sorting
Topological Sorting is mainly used for scheduling jobs from the given dependencies among jobs. In computer science, applications of this type arise in instruction scheduling, ordering of formula cell evaluation when recomputing formula values in spreadsheets, logic synthesis, determining the order of compilation tasks to perform in makefiles, data serialization, and resolving symbol dependencies in linkers [2].

5) To test if a graph is bipartite
We can augment either BFS or DFS when we first discover a new vertex, color it opposited its parents, and for each other edge, check it doesn’t link two vertices of the same color. The first vertex in any connected component can be red or black! See this for details.

6) Finding Strongly Connected Components of a graph A directed graph is called strongly connected if there is a path from each vertex in the graph to every other vertex. (See this for DFS based algo for finding Strongly Connected Components)

7) Solving puzzles with only one solution, such as mazes. (DFS can be adapted to find all solutions to a maze by only including nodes on the current path in the visited set.)
8)Another common way to search for a node is by using a depth-first search (DFS). A depth-first search follows one branch of the tree down as many levels as possible until the target node is found or the end is reached. When the search can't go down any farther, it is continued at the nearest ancestor with unexplored children. 


BFS
1. Printing elements at the same level of binarry tree ( also inOrder )
        1. BreadthFirst_LevelElement_Print(root, levVec) 
It is used to print all elements at the same level (depth). The parameters are root and 2D vector levVec. The vector has the depth information and being used to set the size of the first index which is index for level. While traversing with Breadth First approach, each node will be pushed into the vector after finding the level of the element using getLevel() function. So, it looks like this for the tree diagram above. 
Level at 0: F
Level at 1: B G
Level at 2: A D I
Level at 3: C E H
