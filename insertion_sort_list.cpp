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



void sort_list(link *start)
{
	link *tmp1;
	link *tmp2;
	link *sortd=NULL;
	// while(start!=NULL)
	// {
	tmp1=start;
	tmp2=sortd;
	if (tmp1->value<tmp2->value || tmp2==NULL)
	{
		start=start->next;
		tmp1->next=sortd;
		sortd=tmp1;
	}
	display(sortd);
		// else
		// {
		// 	while(sortd!=NULL)
		// 	{
		// 		if (tmp2>tmp1)
		// 		{
		// 			tmp1=tmp2->next;
		// 			sortd=sortd->next;
		// 		}
		// 		tmp2=sortd->next;
		// 		sortd->next=tmp1;
		// 		sortd=sortd->next;
		// 		sortd->next=tmp2;
		// 	}
		// }
	//}
	return ;
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
	int a[]={3,2,1};//4,7,6,5,3,8,2,1
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

	sort_list(strtnode);	

}