/*
if else statements collectively called branching statements
when there is a if else statement branching will occur
On some rare machines where branching is expensive, the below obvious
approach to find minimum can be slow as it uses branching.
*/
#include <iostream>
#include <cstdlib>
#include <thread>
using namespace std;
#define CHARBIT 8



/*
The obvious approach to find minimum (involves branching) */
int min0(int x, int y)
{
	return (x < y) ? x : y;
}
int max0(int x, int y)
{
	return (x > y) ? x : y;
}
//-----------------------------------------------------------------------------
/*METHOD - 1	(Use absolute value)
max val=(a+b+abs(a-b))/2
min val=(a+b-abs(a-b))/2
*/
int max1(int a, int b)
{
	return (a+b+abs(a-b))/2;
}
int min1(int a, int b)
{
	return (a+b-abs(a-b))/2;
}


//-----------------------------------------------------------------------------
/*METHOD - 2	(Using xor --> ^ and a comparission operator)
max val=x ^ ((x^y) & -(x<y))
if x<y=true, -(x<y)=0, x^((x^y)&0) = x^0 = x
or else if x<y=false, -(x<y)=1, x^((x^y)&1) = x^y^x = y^(x^x) = y^(0)=y
min val=y ^ ((x^y) & -(x<y))
*/
int max2(int x , int y)
{
	return x ^ ((x^y) & -(x<y));
}
int min2(int x , int y)
{
	return y ^ ((x^y) & -(x<y));
}


//-----------------------------------------------------------------------------
/*METHOD - 3	(Use subtraction and shift)
if the value of an integer is greater than or equal to zero then 
in 32 bit storage the front bit will be zero 
else if it is less than 1 fron bit will be 1
max val= x - ((x - y) & ((x - y) >>(sizeof(int) * CHAR_BIT - 1)))
if (x-y)>0 then [(x - y) >>(31) = 0] equation becomes x-(x-y)&0 = x
else, (x-y)<0 then [(x - y) >>(31) = 1] equation becomes x-(x-y)&1 = x-(x-y)=y
min val= y + ((x - y) & ((x - y) >>(sizeof(int) * CHAR_BIT - 1)))
*/
int max3(int x , int y)
{
	return x - ((x - y) & ((x - y) >> (sizeof(int) * CHARBIT - 1)));
}
int min3(int x , int y)
{
	return y + ((x - y) & ((x - y) >>(sizeof(int) * CHARBIT - 1)));
}


int main()
{
	int a=-1;
	int b=-3;
	cout<<min1(a,b)<<endl;
	cout<<max1(a,b)<<endl;
	cout<<ab;
}