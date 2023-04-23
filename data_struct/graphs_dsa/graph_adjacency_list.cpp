#include<bits/stdc++.h>
using namespace std;


struct llist 
{
	int value;
	llist *next=NULL;
};

struct graph                                                                          
{                   
        int ar_len; 
        vector<llist> arr;
};

void dsp_llist( llist *st)
{
	if (st!= NULL) { cout<<st->value<<"->";dsp_llist(st->next);}
	else cout<<endl;
}

graph *crt_graph(int l)
{
        graph *g1=new graph();
        g1->ar_len=l;
        g1->arr=vector<llist>;
	return g1;
}

void dsp_matrix(bool **m)
{
        int l=6;//sizeof(m)/sizeof(m[0]);
        cout<<l<<endl;
        for(int i=0;i<l;i++)
        {
                for(int j=0;j<l;j++)
                {
                        if (m[i][j]==true) cout<<"X  ";
                        else cout<<"_  ";
                }
                cout<<endl;
        }
}

void add_edge(vector<llist> *G,int a,int b)
{
	int*

int main ()
{
        char arr[]={'a','b','c','d','e','f'};
        return 0;
}

