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
	// int x=(l+r)* (sizeof (int));
	// int *a =(int*) malloc(x);
	// memcpy(a,v,x);
	display(L,l);
	printf("%s\n","--L");
	display(R,r);
	printf("%s\n","--R");
	printf("%s\t","initial");
	display(v,l+r);

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
	//printf("%s\t","merge 1");
	//display(v,k);
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
	printf("%s\n","merge 2");
	display(v,k);
	//memcpy(v,a,x);
	//free(a);
}


void partition(int *v,int s)
{
	int k=0;
	int *L = &v[0];
	int *R = &v[s/2];
	int cl[s];
	int cr[s-s/2];
	
	// display(cl,s/2);
	// display(cr,s-s/2);
	if (s>1)
	{
		partition(L,s/2);
		partition(R,(s-s/2));
		memcpy(cl,L,(s/2* sizeof(int)));
		memcpy(cr,R, (s-s/2)* sizeof(int));
		// printf("%s","L ");
		// display(L,s/2);
		// display(cl,s/2);
		// printf("%s","R ");
		// display(R,(s-s/2));
		// display(cr,s-s/2);
		merge(cl,s/2,cr,(s-s/2),v);
	}

	// printf("%s\t","   " );
	// printf("%d\n",*L );
	// printf("%s\t","   " );
	// printf("%d\n",*R );
	
	
}


int main ()
{
	int l=0;
	int v[]={2,3,1};
	int m=sizeof(v)/sizeof(v[0]);
	//display(v,m);
	// int a=m/2;
	// int b=m-m/2;
	// printf("%d\n",m);
	// printf("%d\n",a);
	// printf("%d\n",b);

	partition(v,m);
	// int L[]={4};
	// int R[]={2};
	// merge(L,1,R,1,v);
	printf("%s\n","---" );
	//display(v,m);
	return 0;
}
