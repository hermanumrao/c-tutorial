#include<iostream>
#include<vector>
#include<stdlib.h>
#include <string.h>

using namespace std ;
int display1(int *v, int s)
{
	printf("%s\n","display" );

	for (int i=0;i<s;++i)
	{
		printf("%d ", v[i] ); 

	}
	printf("\n" );
	return 0;
}
int display(vector<int> & v)
{
	std::cout << "display" << std::endl;

	for (int i=0;i<v.size();++i)
	{
		std::cout << v[i] << " ";
	}
	cout<<std::endl;
	return 0;
}
void merge(int *L , int l,int *R,int r, int *v,int Index)
{
	int k=Index;
	int i=0;
	int j=0;
	if (l<=0 || r<=0)
	{
		printf("%s\n","invalid values");
		return;
	}

	display1(L,l);
	printf("%s\n","--L");
	display1(R,r);
	printf("%s\n","--R");
	printf("%s\t","initial");
	display1(v,l+r);

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
	printf("%s\n","merge 2");
	display1(v,k);
}


void merge_sorted_vec(vector<int> & v1 , vector<int> & v2,vector<int> & v3 )
{
	int m=v1.size();
	int n=v2.size();
	int k=0;
	int i=0;
	int j=0;
	v3.resize(m+n);
	while(i<m && j<n)
	{
		if (v1[i]<v2[j])
		{
			v3[k]=v1[i];
			++i;
			++k;
		}
		else
		{
			v3[k]=v2[j];
			++j;
			++k;
		
		}
	}
	while (i<m || j<n)
	{
		if (m==i)
		{
			v3[k]=v2[j];
			++j;
			++k;
		}
		else
		{
			v3[k]=v1[i];
			++i;
			++k;
		}
	}
	std::cout<<"merging";
	display(v3);
}


vector<int> fill(vector<int> & v, int be , int end)
{
	vector<int> vec;
	while(be<=end)
	{
		vec.push_back(v[be]) ;
		be++;
	}
	cout<<"vec=";
	display(vec);
	return vec;
	

}

void partition(vector<int> &v, int s,int e,int a)
{
	int m=(s+e)/2;
	
	if (s<e)
	{

		partition(v,s,m,1);
		partition(v,m+1,e,2);
		vector<int> L=fill(v,s,m);
		vector<int> R=fill(v,m+1,e);
		cout<<"L=";
		display(L);
		cout<<"R=";
		display(R);
		merge(&L[0],L.size(),&R[0],R.size(),&v[0],s);
	}

}


int main ()
{
	
	vector<int> v={4,7,5,8,6,3,2,1};
	display(v);
	std::cout<< "__"<< std::endl<< std::flush;
	int m=v.size();
	cout<<m<<endl;
	// vector<int> L= fill(v,0,m/2);
	// vector<int> R= fill(v,m/2,m);
	// display(L);
	// display(R);
	partition(v,0,m-1,0);

	return 0;
}