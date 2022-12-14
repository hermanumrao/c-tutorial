/*

 Heap sort is priority queue 
Heapsort is a comparison-based sorting algorithm. Heapsort can be thought of as an improved selection sort: like that algorithm, it divides its input into a sorted and an unsorted region, and it iteratively shrinks the unsorted region by extracting the smallest element and moving that to the sorted region. The improvement consists of the use of a heap data structure rather than a linear-time search to find the minimum.[2]

Although somewhat slower in practice on most machines than a well-implemented quicksort, it has the advantage of a more favorable worst-case O(n log n) runtime. Heapsort is an in-place algorithm, but it is not a stable sort.

 * 
 * The heapsort algorithm can be divided into two parts.

In the first step, a heap is built out of the data. The heap is often placed in an array with the layout of a complete binary tree. The complete binary tree maps the binary tree structure into the array indices; each array index represents a node; the index of the node's parent, left child branch, or right child branch are simple expressions. For a zero-based array, the root node is stored at index 0; if i is the index of the current node, then


 * 
 * In computer science, a binary tree is a tree data structure in which each node has at most two children, which are referred to as the left child and the right child. A recursive definition using just set theory notions is that a (non-empty) binary tree is a triple (L, S, R), where L and R are binary trees or the empty set and S is a singleton set.[1] Some authors allow the binary tree to be the empty set as well.[2]
 
 * In computer science, a binary search tree (BST), sometimes also called an ordered or sorted binary tree, 
 * is a node-based binary tree data structure where each node has a comparable key (and an associated value)
 *  and satisfies the restriction that the key in any node is larger than the keys in all nodes in that node's left subtree an
 * d smaller than the keys in all nodes in that node's right sub-tree. Each node has no more than two child nodes.
 *  Each child must either be a leaf node or the root of another binary search tree. The left sub-tree contains only nodes with keys 
 * less than the parent node; the right sub-tree contains only nodes with keys greater than the parent node.
 *  BSTs are also dynamic data structures, and the size of a BST is only limited by the amount of free memory in the operating system.
 *  The main advantage of binary search trees is that it remains ordered, which provides quicker search times than many other data
 *  structures. The common properties of binary search trees are as follows:[1]

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
The left and right subtree each must also be a binary search tree.
     20
    /  \
  10    30
       /  \
      5    40    value 5 is on the right subtree of the node containing 20, a violation of the BST( binary search tree) property! 
 * 
 * 
 * 
 * 
 * 
 * What is the depth of complete binary tree log2 (N + 1) = D
 * 
 * A balanced binary tree has the minimum possible maximum height (a.k.a. depth) for the leaf nodes, because for any given number of leaf nodes the leaf nodes are placed at the greatest height possible.
 * int maxHeight(BinaryTree *p) {
  if (!p) return 0;
  int left_height = maxHeight(p->left);
  int right_height = maxHeight(p->right);
  return (left_height > right_height) ? left_height + 1 : right_height + 1;
}
 * Remember that a heap is a way to implement a priority queue.

The property of a priority queue is:

when you get an item it is the one with the highest priority
Heaps have same complexity as a balanced search tree but:

they can easily be kept in an array
they are much simpler than a balanced search tree
they are cheaper to run in practice
A heap is a binary tree that has special structure compared to a general binary tree:

The root is greater than any value in a subtree
this means the highest priority is at the root
this is less information than a BST and this is why it can be easier and faster
    2.   It is a complete tree
the height is always log(n) so all operations are O(log(n))
 
*/



// C++ program for implementation of Heap Sort with recurstion

recursion vs itterative method

iParent(i)
smallest leading
iLeftChild(i)
iRightChild(i)
= floor((i) / 2) where floor functions map a real number to the
integer.
= 2*i + 1
= 2*i + 2


#include <iostream> 
  
using namespace std; 
  
// To heapify a subtree rooted with node i which is 
class PriorityQueue
{
public:

    PriorityQueue(int *ar, int sz) : arrSize(sz),chunk(arrSize)
    {
        arr = new int[sz];
        memcpy(arr, ar, sz * sizeof (int));
    }

    void Display()
    {
        for (int i = 0; i < arrSize; ++i)
            std::cout << arr[i] << ", ";

        std::cout << endl << flush;
    }

    void swap(int *f, int *s)
    {
        int tmp = *f;
        *f = *s;
        *s = tmp;
    }
    

  

    void heapyfyIt(int *arr, int parent, int size)
    {
        int left = 2 * parent + 1;
        int right = 2 * parent + 2;

        int smallest = parent;

        if (left < size && arr[left] < arr[parent])
        {
            smallest = left;
        }

        if (right < size && arr[right] < arr[left])
        {
            smallest = right;
        }

        if (smallest != parent)
        {
            swap(&arr[smallest], &arr[parent]);
            heapyfyIt(arr, smallest, size);
        }

        //cout << " recursion parent " << parent << endl;
        // Display();

    }

    void heapyfy()
    {
        cout << " heapyfy start " << endl;

        for (int i = arrSize / 2 - 1; i >= 0; --i)
        {
            //cout << " heapyfy parent " << i << endl;
            heapyfyIt(arr, i, arrSize);
        }

        cout << " heapyfy end " << endl;

    }

    int extractMin( )
    {
        
        swap(&arr[0], &arr[arrSize-1]);
        --arrSize;
        heapyfyIt(arr, 0, arrSize);
       
        return arr[arrSize];
    }
    
    int push( int value)
    {
        if( chunk == arrSize)
        {
           int *ar = new int [chunk + 256];   
           memcpy( ar, arr, arrSize*sizeof(int)  );
           delete [] arr;
           
           arr = ar;
        }
             
        /*
         0                               
      1      2
  3       4
         
         
        
        5
    10      15
 40    30  4
 
         */        
        ++arrSize;     
        int parent = arrSize;
       
        while ( parent > 1 && arr[parent/2 -1] > value  )
        {
            arr[parent-1] = arr[parent/2 -1];
                    
            parent = parent/2;
        }
        arr[parent -1] = value;
    }
    

    int *arr;
    int arrSize;
    int chunk;
};

int main(int argc, char**argv)
{

    char code[] = {'a', 'b', 'c', 'd', 'e'};
    int frequency[] = {40, 30, 15, 10, 5};


    PriorityQueue queue(frequency, sizeof (frequency) / sizeof (frequency[0]));

    //queue.swap( &queue.arr[0], &queue.arr[1] );

    queue.Display();

    queue.heapyfy();

    queue.Display();
    
    cout <<  "push Start " <<endl;
    queue.push(4);
    queue.Display();
    
    cout <<  "push end " <<endl;
    
    cout <<  "Extract Start " <<endl;
     
    while(queue.arrSize )
    {
        cout << queue.extractMin( )   << ", " ;
    }

    cout <<  "Extract end " <<endl;
    
    //snprinf( "%x")

    std::cout << std::endl;
    return 0;
}



M_Heapify with stack or heap memory
https://www.youtube.com/watch?v=MtQL_ll5KhQ

1    2    3      4        5 
4    10   3      5        1

         4
       10 
       
       
          4
    10         3
    
 5       1
 
 
 manange is itself ennough to put biggest eleemnt at beggeing

 round1  10     4       3    5   1
 round2  10     4       3    5   1 
 round3  
 round4
 round5  10      5      3    4   1

    
  
                10 
        
      5                  3
  
 
  4      1
      
      
     
remove biggest element 10 from begining and put at back   
      
round1   1      5      3    4   10

                1
         5            3
         
    4

//Max heap sort

#include<stdio.h>
//#include<conio.h>
#include <curses.h>

void manage(int *, int);
void heapsort(int *, int, int);

int main()
{
    int arr[20];
    int i, j, size, tmp, k;
    printf("\n\t------- Heap sorting method -------\n\n");
    printf("Enter the number of elements to sort : ");
    scanf("%d", &size);
    for (i = 1; i <= size; i++)
    {
        printf("Enter %d element : ", i);
        scanf("%d", &arr[i]);
        manage(arr, i);
    }
    j = size;
    for (i = 1; i <= j; i++)
    {
        tmp = arr[1];
        arr[1] = arr[size];
        arr[size] = tmp;
        size--;
        heapsort(arr, 1, size);
    }
    printf("\n\t------- Heap sorted elements -------\n\n");
    size = j;
    for (i = 1; i <= size; i++)
        printf("%d ", arr[i]);
    //getch();
    return 0;
}

void manage(int *arr, int i)
{
    int tmp;
    tmp = arr[i];
    while ((i > 1) && (arr[i / 2] < tmp))
    {
        arr[i] = arr[i / 2];
        i = i / 2;
    }
    arr[i] = tmp;
}

void heapsort(int *arr, int i, int size)
{
    int tmp, j;
    tmp = arr[i];
    j = i * 2;
    while (j <= size)
    {
        if ((j < size) && (arr[j] < arr[j + 1]))
            j++;
        if (arr[j] < arr[j / 2])
            break;
        arr[j / 2] = arr[j];
        j = j * 2;
    }
    arr[j / 2] = tmp;
}



HUFFMAN(C)
1	n ← |C|
2	Q ← C
3	for i 1 to n - 1
4		do allocate a new node z
5			left[z] ← x ← EXTRACT-MIN (Q)
6 			right[z] ← y ← EXTRACT-MIN (Q)
7 			f [z] ← f [x] + f [y]
8 			INSERT(Q, z)
9 	return EXTRACT-MIN(Q)


hoffman code
char    freq    fixcode
a	45	000
b	13	001
c	12	010
d	16	011
e	9	100
f	5	101

haracter	Variable-length codeword	Size of string in bit
a	0	1
b	101	3
c	100	3
d	111	3
e	1101	4
f	1100	4


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX_TREE_HT 100
struct MH_Node
{
	char character;
	unsigned frequency;
	struct MH_Node *l, *r;
};
 
 
struct M_Heap
{
	unsigned size;
	unsigned space;
	struct MH_Node **array;
};
 
struct MH_Node* newNode(char character, unsigned frequency)
{
    struct MH_Node* temp = (struct MH_Node*) malloc(sizeof(struct MH_Node));
    temp->l = temp->r = NULL;
    temp->character = character;
    temp->frequency = frequency;
    return temp;
}
 
 
struct M_Heap* createM_Heap(unsigned space)
{
    struct M_Heap* M_Heap = (struct M_Heap*) malloc(sizeof(struct M_Heap));
    M_Heap->size = 0;
    M_Heap->space = space;
    M_Heap->array = (struct MH_Node**)malloc(M_Heap->space * sizeof(struct MH_Node*));
    return M_Heap;
}
 
 
void swapMH_Node(struct MH_Node** a, struct MH_Node** b)
{
    struct MH_Node* t = *a;
    *a = *b;
    *b = t;
}
 
 
iParent(i)
smallest leading
iLeftChild(i)
iRightChild(i)
= floor((i) / 2) where floor functions map a real number to the
integer.
= 2*i + 1
= 2*i + 2

void M_Heapify(struct M_Heap* M_Heap, int idx)
{
    int smallest = idx;
    int l = 2 * idx + 1;
    int r = 2 * idx + 2;
 
    if (l < M_Heap->size && M_Heap->array[l]->frequency < M_Heap->array[smallest]->frequency)
		smallest = l;
 
	if (r < M_Heap->size && M_Heap->array[r]->frequency < M_Heap->array[smallest]->frequency)
		smallest = r;
 
    if (smallest != idx)
    {
		swapMH_Node(&M_Heap->array[smallest], &M_Heap->array[idx]);
		M_Heapify(M_Heap, smallest);
    }
}
 
int isSizeOne(struct M_Heap* M_Heap)
{
    return (M_Heap->size == 1);
}
 
 
struct MH_Node* extractMin(struct M_Heap* M_Heap)
{
    struct MH_Node* temp = M_Heap->array[0];
    M_Heap->array[0] = M_Heap->array[M_Heap->size - 1];
    --M_Heap->size;
    M_Heapify(M_Heap, 0);
    return temp;
}
 
 
void insertM_Heap(struct M_Heap* M_Heap, struct MH_Node* MH_Node)
{
 
    int i = M_Heap->size - 1;
    ++M_Heap->size;
    while (i && MH_Node->frequency < M_Heap->array[(i - 1)/2]->frequency)
    {
		M_Heap->array[i] = M_Heap->array[(i - 1)/2];
		i = (i - 1)/2;
    }
    M_Heap->array[i] = MH_Node;
}
 
 
void buildM_Heap(struct M_Heap* M_Heap)
{
    int n = M_Heap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
		M_Heapify(M_Heap, i);
}
 
 
void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
		printf("%d", arr[i]);
		printf("\n");
}
 
 
int isLeaf(struct MH_Node* root)
{
    return !(root->l) && !(root->r) ;
}
 
 
struct M_Heap* createAndBuildM_Heap(char character[], int frequency[], int size)
{
	int i;
    struct M_Heap* M_Heap = createM_Heap(size);
    for (i = 0; i < size; ++i)
        M_Heap->array[i] = newNode(character[i], frequency[i]);
    M_Heap->size = size;
    buildM_Heap(M_Heap);
    return M_Heap;
}
 
 
struct MH_Node* buildHuffmanTree(char character[], int frequency[], int size)
{
    struct MH_Node *l, *r, *top;
    struct M_Heap* M_Heap = createAndBuildM_Heap(character, frequency, size);
 
    while (!isSizeOne(M_Heap))
    {
        l = extractMin(M_Heap);
        r = extractMin(M_Heap);
        top = newNode('$', l->frequency + r->frequency);
        top->l = l;
        top->r = r;
        insertM_Heap(M_Heap, top);
    }
    return extractMin(M_Heap);
}
 
//pathfinder algorithm * recursion routine to find path */
//void pathFinder(Node* node, int path[], int level)
// preoder traversal.. Please do not confuse with leaves and print, see the code beneath for pathfinder
void printCodes(struct MH_Node* root, int arr[], int top)
{
    if (root->l)
    {
        arr[top] = 0;
        printCodes(root->l, arr, top + 1);
    }
 
    if (root->r)
    {
        arr[top] = 1;
        printCodes(root->r, arr, top + 1);
    }
 
    if (isLeaf(root))
    {
        printf("%c: ", root->character);
        printArr(arr, top);
    }
}
 
void HuffmanCodes(char character[], int frequency[], int size)
{
	struct MH_Node* root = buildHuffmanTree(character, frequency, size);
	int arr[MAX_TREE_HT], top = 0;
	printCodes(root, arr, top);
}
 
void main()
{
	char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	int frequency[] = {5, 9, 12, 13, 16, 45};
	int size; 
	clrscr();
	size = sizeof(arr)/sizeof(arr[0]);
	HuffmanCodes(arr, frequency, size);
	getch();
}




* recursion routine to find path */
void pathFinder(Node* node, int path[], int level)
{
        if(node == NULL) return;
        // leaf node save
        if(node->left == NULL && node->right == NULL) {
                path[level] = node->data;
                int sum = 0;
                for(int i = 0; i <= level; i++) {
                        cout << path[i] << " ";
                        sum += path[i];
                }
                cout << "  sum = " << sum << endl;
                return;
        }
        // parent node save
        path[level] = node->data;
        pathFinder(node->left, path, level+1);
        pathFinder(node->right, path, level+1);
}

struct Tree* insertNode(Tree *node, int data)
{
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        return node;
}

int main(int argc, char **argv)
{
        Tree *root = NULL;
        Tree *nodeLeft = NULL;
        Tree *nodeRight = NULL;

        // unsorted binary tree
        // root
        root = insertNode(new Tree, 3);

        // 1st level
        nodeLeft = insertNode(new Tree, -1);
        root->left = nodeLeft;
        nodeRight = insertNode(new Tree, 2);
        root->right = nodeRight;

        // 2nd level
        nodeLeft->left = insertNode(new Tree, 5);
        nodeLeft->right = insertNode(new Tree, 7);
        nodeRight->left = insertNode(new Tree, 1);

        // path find
        int path[10];
        pathFinder(root,path,0);
        
        return 0;
}

/* output */
/*
3 -1 5  sum = 7
3 -1 7  sum = 9
3 2 1  sum = 6
*/
