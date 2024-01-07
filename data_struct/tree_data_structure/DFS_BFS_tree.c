////////////////// code for BFS we need to use queue data structure ////////////////

#include <stdio.h>
#include <stdlib.h>

//structure for tree 
struct treenode
{
	int value;
	struct treenode *left;
	struct treenode *right;
};


//structure for queue 
struct queue {
    struct treenode * data;
    struct queue * next;
};
struct queue * front =NULL ;
struct queue * rear =NULL ;


struct treenode * create_node(int value)
{
    struct treenode *new_node = (struct treenode *) malloc(sizeof(struct treenode));
    new_node ->value=value;
    new_node ->left=NULL;
    new_node ->right=NULL;
    return new_node;
}

void print_tabs(int i)
{
    while (i>0) { 
        printf("\t");
        i-=1;
    }
}

void print_tree(struct treenode *root, int level)
{
    if (root == NULL) {
    printf("%s\n","-- ");
        return ;
    }
    printf("value=%d\n",root ->value);
    print_tabs(level);
    printf("left=");
    print_tree(root ->left,level+1);
    print_tabs(level);
    print_tree(root ->right,level+1);
    printf("\n");
}



void enqueue (struct treenode * value)
{
    struct queue * ptr;
    ptr = (struct queue*) malloc(sizeof(struct queue));
    ptr ->data = value;
    ptr ->next = NULL;
    if (front==NULL && rear==NULL) front=rear=ptr;
    else 
    {
        rear ->next=ptr;
        rear= ptr;
    }
    printf("I just inserted a value\n");
}

struct treenode * deque ()
{
    if (front==NULL && rear==NULL) 
    {
        printf("underflow \n");
        return NULL;
    }
    else {
        struct queue * tmp = front;
        if (front==rear)
        {
            rear=NULL;
        }
        front= front ->next;
        struct treenode * tmp_i= tmp ->data;
        free(tmp);
        return tmp_i;
    }
}

void display()
{
    if (rear==NULL && front==NULL)
    {
        printf("%s\n","empty list");
        return ;
    }
    printf("elements are :-");
    struct queue * tmp=front;
    while(tmp!=NULL)
    {
        printf("%d ->",tmp ->data ->value);
        tmp=tmp ->next;
    }
}


// now to print the tree in BFS
//
void BFS_print(struct treenode* root)
{
    if (root != NULL)
    {
        if (front == NULL && rear == NULL)
        {
            printf("%d|",root->value);
            if (root->left != NULL)enqueue(root ->left);
            if (root->right != NULL) enqueue(root ->right);
        }
        while (!(front == NULL && rear == NULL))
        {
            struct treenode * tmp =deque();
            printf("%d|",tmp->value);
            if (root->left != NULL) enqueue(root->left);
            if (root->right != NULL) enqueue(root->right);
        }
    }
}

int main(int argc, char *argv[])
{
    struct treenode *n1= create_node(1);
    struct treenode *n2= create_node(2);
    struct treenode *n3= create_node(3);
    struct treenode *n4= create_node(4);
    struct treenode *n5= create_node(5);
    struct treenode *n6= create_node(6);
    struct treenode *n7= create_node(7);
    struct treenode *n8= create_node(8);
    
    n1->left = n2;
	n1->right= n3;
	n2->right= n4;
    n3->left = n5;
    n3->right= n6;
    n5->left = n7;
    n5->right= n8;

    print_tree(n1,0);
    BFS_print(n1);
    return EXIT_SUCCESS;
}
