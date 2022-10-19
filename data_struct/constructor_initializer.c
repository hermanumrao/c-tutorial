#include<iostream>
#include<vector>
#include<stdlib.h>
#include <string.h>
using namespace std ;

struct Node
{
	int x;
	Node(int t)
	{
		cout<<"me1"<<endl;
		x=t;
	} 
	Node()  //default constructor
	{
		cout<<"me2"<<endl;
		x=2;
	}
};

int main()
{
	Node x;
	Node *a= new Node();

	Node b(1);
	Node *c= new Node(1);
	Node xx{1};
	Node e={.x=1};
	return 0;
}
