#include<bits/stdc++.h>
using namespace std;

const int xrow=4;
const int xcol=5;


int main()
{
	int it=1;
	int matrix1[xrow][xcol];
	for(int i=0;i<xrow;i++)
	{
		for(int j=0;j<xcol;j++)
		{
			matrix1[i][j]=it;
			it++;
		}
	}
	for(int i=0;i<xrow;i++)
        {       
                for(int j=0;j<xcol;j++)
                {       
                        cout<<matrix1[i][j]<<"\t";
                }       
                cout<<endl;
        }
}

