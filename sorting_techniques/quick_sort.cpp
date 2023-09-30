//quick sort
//4,10,8,7,6,5,3,12,14,2
#include <stdio.h>//to compile in c
#include <stdlib.h>// to compile in c
#include<iostream>
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

void swap(int *x,int *y)
{
	int tmp=*x;
	*x=*y;
	*y=tmp;
}

void qsort(int *arr,int st, int end)
{
	if ((end-st)<1 ) return ;
	int mid= (st+end)/2;
	int l=0;
	int r=mid;
	while (l< mid && r<end)
	{
		while(l<mid) 
		{
			if (arr[l]>arr[mid]) break;
			else l++;
 		}
 		while(r<(end+1))
 		{
 			if (arr[r]<arr[mid]) break;
			else r++;
 		}
		if (r<(end+1) && l<mid) swap(arr[l],arr[r]);
		else
		{
			if (r<(end+1))
			{
				if((r-mid)>1)
				{
					swap(arr[mid],arr[mid+1]);
					swap(arr[mid],arr[r]);
					mid=mid+1;
					l++;

				}
				else swap(arr[r],arr[mid]);
			}
			if (l<mid)
			{
				swap(arr[l],arr[mid]);
				mid=l;
			}
		}
	}
	qsort(arr,st,mid-1);
	qsort(arr,mid+1,end);
}
 
int main()
{
	int arr[]={6,5,8,9,7};
	int l=sizeof(arr)/sizeof(arr[0]);
	disp_arr(arr,l);
	qsort(arr,0,l-1);
	disp_arr(arr,l);
	return 0;
}