#include <stdio.h>
#include <stdlib.h>

// tutorial for bitfeilds


struct flag
{	unsigned int is_keyword :1;
	unsigned int is_extern :1;
	unsigned int is_static :1;
	unsigned int is_int :1;
	unsigned int is_char :1;
	unsigned int is_ptr :1;
	unsigned int test2 :23;
	unsigned int test1 :3;
	//unsigned int test2 :23;
};

int main()
{	struct flag a;
	a.is_keyword=1;
	a.test1=9;  //max value that test1 can store is 7 (111) 
	//this causes over flow only (001) is stored out of (1001) 
	//the bits assigned to others are not affected in any way by the overflow.
	printf("%d %d \n",a.is_keyword,sizeof(a));
	printf("%d %d", a.test1 , a.test2);

	return 0;
}
