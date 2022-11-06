#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
struct link
{
	int value;
	link *next;
};

void display(link *start)
{
	while(start != NULL)
	{
		printf("->%d", start->value);
		start=start->next;
	}
	cout<<endl;
}

bool search_list(link *node,int item)
{
	if (node==NULL) return false;
	if (node->value==item) return true;
	else return search_list(node->next,item);
}

void AddNode(link *start,link *node )
{
	while(start->next!= NULL)
	{
		start=start->next;
	}
	start->next=node;
}

int main()
{
	int a[]={4,7,6,5,3,8,2,1};//
	int b=sizeof(a)/4;
	link *strtnode =new link();
	strtnode->value=a[0];
	strtnode->next=NULL;
	
	printf("%s\n","" );
	for (int i = 1; i < b; ++i)
	{
		link *node =new link();
		node->value=a[i];
		node->next=NULL;
		AddNode(strtnode,node);
		//display(strtnode);
	}
	display(strtnode);
	cout<<"________"<< endl;
	int item=4;
	cout<<"item to search"<<endl;
	//cin>>item;
	bool tmp=search_list(strtnode,item);
	if (tmp==true) cout<<"item found";
	else cout<<"missing";

}