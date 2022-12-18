
#include <stdio.h>

typedef  int(*AB)(int,int) ;//  creates a new variable type which is complex and has structure (int,int) and name AB


/*  	CALLBACK
a callback is a function that is passed to another function as an argument
two types of callback functions
	-Synchronous  : executed instantly 
	-Asynchronous : executed later (more prefered)
in C it is implemented using function pointers.


 Just like the data pointer (ex- int* char* etc) we also have function pointers
example for function pointers:-
*/

int add(int a,int b)
{
	printf("sum=%d\n",a+b);
	return a+b ;
}

int mul(int a,int b)
{
	printf("mul=%d\n",a*b);
	return a*b ;
}

int do_op(AB ab, int x, int y)
{
	return ab(x,y);
}


int main()
{
	AB ab=&add;

	int ret= do_op(ab,5,2);
	printf("%d\n",ret );

}

/* this is very helpful because the function (over here 'add') gets executed at a completely 
different location i.e. it cld have been executed in a different device itself.


*/
