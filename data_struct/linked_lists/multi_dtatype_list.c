#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct link   
{                      
        int value;     
        struct link *next;    
};    
    
void display(struct link* start)    
{    
        while(start != NULL)    
        {    
                printf("->%d", start.value);    
                start=start.next;    
        }    
        printf("\n");    
}    
    

int main()
{
        int a[]={4,7,6,5,3,8,2,1};
        int b=sizeof(a)/sizeof(a[1]);
        struct link strtnode;
	struct link* strt=&strtnode;
	strtnode.value =a[0];
	printf("\n");
	for (int i = 1; i < b; ++i)
        {
                struct link node;
		node.value=a[i];
		strtnode.next=&node;
		strtnode=strtnode.next;
        }
        display(&strt);

}
