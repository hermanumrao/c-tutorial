#include<bits/stdc++.h>
using namespace std;

const int xrow=4;
const int xcol=5;
void dsp_matrix(int **m)
{
	for(int i=0;i<xrow;i++)
        {
                for(int j=0;j<xcol;j++)
                {       
                	cout<<m[i][j]<<"\t";
                }       
                cout<<endl;
        }
}
int main()
{
	int it=1;
	int **mt=new int *[xrow];
	for (int i=0;i<xrow;i++)
	{
		mt[i]=new int[xcol];
	}
	for(int i=0;i<xrow;i++)
	{	mt[i]= new int[xcol];
		for(int j=0;j<xcol;j++)
		{
			mt[i][j]=it;
			it++;
		}
	}
	dsp_matrix(mt);
}
