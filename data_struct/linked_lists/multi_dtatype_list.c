#include <stdio.h>
#include <stdlib.h>
// i am trying to create a linked list which can store heterogenous datatypes using:
// conversion is easy like int to float
// used to make DB with multiple datatype
// union in combination with struct

typedef struct l
{	union  
	{      	int d;
        	char c;
        	char s[20];
	        float f;
	};
	struct l *ptr;
}link;


int main ()
{	link *a=( link *)malloc(sizeof(link));
	a->d=1;
	a->ptr=NULL;
	link *b= (link *)malloc(sizeof(link));
	b->c='a';
	a->ptr=b;
	printf("%d %c",a->d,a->ptr->c);
	return 0;
}
