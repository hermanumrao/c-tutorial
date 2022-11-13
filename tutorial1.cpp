#include<iostream>

using namespace std ;

void swap(int *x,int *y)
{
	int tmp=*x;
	*x=*y;
	*y=tmp;
}

int main()
{
	int arr[]={3,1,2};
	cout<<"old arary "<<arr[0]<<arr[1]<<arr[2]<<endl;
	swap(arr[0],arr[2]);
	cout<<"new arary "<<arr[0]<<arr[1]<<arr[2]<<endl;
	return 0;
}