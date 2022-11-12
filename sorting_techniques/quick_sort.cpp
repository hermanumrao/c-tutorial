//quick sort
//4,10,8,7,6,5,3,12,14,2
#include <stdio.h>//to compile in c
#include <stdlib.h>// to compile in c
#include<iostream>
#include <string>// used for concatenation of the arrays
using namespace std ;

void disp_arr(int *arr, int l)
{
    cout<<"array=";
    for (int b=0;b<l;b++)
    {
        cout<<arr[b]<<' ';
    }
    cout<<endl;
}

void qsort(int *arr,int st, int end, int *narr)
{
	if ((end-st)<1 ) return ;
	int mid= (st+end)/2;
	int L[mid-st];
	int R[end-mid];
	int l=0;
	int r=0;
	for (int i=st;i<(end+1);i++)
	{
		if (arr[i]<arr[mid]) 
		{
			L[l]=arr[i];
			l++;
		}
		else if (arr[i]>arr[mid])
		{
			R[r]=arr[i];
			r++;
		}
	}
	qsort(L,st,mid,narr);
	if (l>1) for (int it3=0;it3<l;it3++) L[it3]=narr[it3];
	qsort(R,0,r-1,narr);
	if (r>1) for (int it4=0;it4<r;it4++) R[it4]=narr[it4];

	for (int it1=0; it1<(end-st+1);it1++)
	{
		for (int it2=0; it2<(l);it2++)
		{
			narr[it1]=L[it2];
			it1++;
		}
		narr[it1]=arr[mid];
		it1++;
		for (int it2=0; it2<(r);it2++)
		{
			narr[it1]=R[it2];
			it1++;
		}
	}
	return ;

}
 
int main()
{
	int arr[]={4,7,6,5,3,1,2};
	int l=sizeof(arr)/sizeof(arr[0]);
	int narr[l];
	qsort(arr,0,l-1,narr);
	disp_arr(narr,l);
	return 0;
}