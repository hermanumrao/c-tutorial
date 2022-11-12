#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int display(int *v, int s)
{
	printf("%s\n","display" );

	for (int i=0;i<s;++i)
	{
		printf("%d ", v[i] ); 

	}
	printf("\n" );
	return 0;
}


void merge(int *L , int l,int *R,int r, int *v)
{
	int k=0;
	int i=0;
	int j=0;
	if (l<=0 || r<=0)
	{
		printf("%s\n","invalid values");
		return;
	}
	

	while(i<l && j<r)
	{
		
		
		if (L[i]<R[j])
		{
			*(v+k)=*(L+i);
			++i;
			++k;
		}
		else
		{
			*(v+k)=*(R+j);
			++j;
			++k;
		
		}
		
	}
	while (i<l || j<r)
	{
		if (l==i)
		{
			*(v+k)=*(R+j);
			++j;
			++k;
		}
		else
		{
			*(v+k)=*(L+i);
			++i;
			++k;
		}
	}
	
}


void partition(int *v,int s)
{
	int k=0;
	int *L = &v[0];
	int *R = &v[s/2];
	int cl[s];
	int cr[s-s/2];
	
	
	if (s>1)
	{
		partition(L,s/2);
		partition(R,(s-s/2));
		memcpy(cl,L,(s/2* sizeof(int)));
		memcpy(cr,R, (s-s/2)* sizeof(int));
	
		merge(cl,s/2,cr,(s-s/2),v);
	}

	
	
}


int main ()
{
	int l=0;
	int v[]={4,7,6,5,3,8,2,9,1};
	int m=sizeof(v)/sizeof(v[0]);
	partition(v,m);
	display(v,m);
	return 0;
}
