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

void insert_list(link *sortd , link *a)
{
	link *temp=sortd->next;
	while (temp!=NULL)
	{
		if ((a->value)>(temp->value))
		{
			temp=temp->next;
			sortd=sortd->next;
		}
		else
		{
			sortd->next=a;
			sortd=sortd->next;

			sortd->next=temp;
			return;
		}
	}
	sortd->next=a;
	return;

}

void sort_list(link *node)
{
	link *tmp=NULL;
	link *sortd=NULL;
	while(node!=NULL)
	{
		tmp=node;
		node=node->next;
		tmp->next=NULL;
		if (sortd==NULL)
		{
			sortd=tmp;
		}
		else
		{
			if ((sortd->value)<(tmp->value))
			{
				if(sortd->next==NULL)
				{
					sortd->next=tmp;
				}
				else
				{
					insert_list(sortd,tmp);
				}
			}
			else
			{
				tmp->next=sortd;
				sortd=tmp;
			}
		}		
	}
	display(sortd);
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

	sort_list(strtnode);	

}
