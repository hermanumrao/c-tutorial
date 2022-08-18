//this program gives sum of two numbers
//all the lines commented below this are used for c

//#include <stdio.h>
#include<iostream>

int fn(int x,int y)
{
	int z=x+y;
	return z;
}
//void main()
int main ()
{
	int a=fn(2,3);
	//printf("%d\n",a );
	std::cout<<a;
	//return ;
	return 0;

}
