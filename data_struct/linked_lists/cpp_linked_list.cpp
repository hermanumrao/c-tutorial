#include<bits/stdc++.h>

using namespace std;

class Node
{	public:
		Node(int d,Node *p=0) : data(d),next(p) {}
		int data;
		Node *next;
};

int main()
{	int n;
	Node *p;Node *q;
	while (cin>>n)
	{	p=new Node(n,q);
		q=p;
	}
	for (;p->next;p=p->next)
		cout<<p->data<<"-->";
	cout<<"*\n";
}
