//this program prins series of fabonaaci
#include<stdio.h>
// function to find next term of series
int fn(int a,int b)
{
	int c=b+a;
	return c ;
}
void main()
{
	int a=1;
	int b=1;
	int n;
	scanf("%d",&n) ;
	while(n>1){
		int x=fn(a,b);
		n=n-1;
		a=b;
		b=x;
		printf("%d\n",b );
	}
	return ;
}