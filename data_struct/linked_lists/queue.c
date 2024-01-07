#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
};

struct node * front =NULL ;
struct node * rear =NULL ;

void enqueue (int value)
{
    struct node * ptr;
    ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = value;
    ptr->next = NULL;
    if (front==NULL && rear==NULL) front=rear=ptr;
    else 
    {
        rear->next=ptr;
        rear= ptr;
    }
    printf("I just inserted a value\n");
}

int deque ()
{
    if (front==NULL && rear==NULL) 
    {
        printf("underflow \n");
        return 0;
    }
    else {
        struct node * tmp = front;
        if (front==rear)
        {
            rear=NULL;
        }
        front= front->next;
        int tmp_i= tmp->data;
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
    struct node * tmp=front;
    while(tmp!=NULL)
    {
        printf("%d ->",tmp->data);
        tmp=tmp->next;
    }
}

int main(int argc, char *argv[])
{
    display ();
    enqueue (3);
    display ();
    enqueue (4);
    display();
    int a=deque ();
    printf("\n\n%d\n",a);
    a=deque ();
    printf("%d\n",a);
    display ();
    return EXIT_SUCCESS;
}
