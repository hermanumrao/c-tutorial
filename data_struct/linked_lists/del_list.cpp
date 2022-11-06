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

bool del_list(link *node,int item)
{
	if (node==NULL) return false;
	//if (node->next==NULL) return false;
	if (node->next->value==item) 
	{
		if (node->next->next==NULL)
		{
			delete(node->next);
			node->next=NULL;
		}
		else
		{
			link *tmp=node->next->next;
			delete(node->next);
			node->next=tmp;
		}
		return true;
	}
	else return del_list(node->next,item);
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
	int a[]={4,7,6,5,3,8,2,1};
	int b=sizeof(a)/sizeof(a[1]);
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
	int item=7;
	// cout<<"item to search";
	// cin>>item;
	bool tmp=del_list(strtnode,item);
	if (tmp==true) cout<<"item found";
	else cout<<"missing"<<endl;
	display(strtnode);

}