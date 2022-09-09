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

link *rev_list(link *start)
{
	link *tmp=NULL;
	link *rev=NULL;
	while(start!=NULL)
	{
		tmp=start;
		start=start->next;
		tmp->next=rev;
		rev=tmp;
	}
	return rev;
}

void AddNode(link *start,link *node )
{
	while(start->next!= NULL)
	{

		start=start->next;

	}
	start->next=node;
}

//enable to input list from user
// int main()
// {
// 	int x;
// 	int s;
// 	std::cin>> s;

// 	printf("%s\n","first entry" );
// 	link *strtnode =new link();
// 	strtnode->value=s;
// 	strtnode->next=NULL;
	
// 	display(strtnode);
// 	printf("%s\n","" );
// 	while (x!=0)
// 	{
// 		std::cin>> x;
// 		link *node =new link();
// 		node->value=x;
// 		printf("%s\n","new entry" );
// 		node->next=NULL;
// 		AddNode(strtnode,node);
// 		display(strtnode);
// 		printf("%s\n","" );
// 	}
// }

int main()
{
	int a[]={1,2,3,4,5};
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

	display(rev_list(strtnode));	

}