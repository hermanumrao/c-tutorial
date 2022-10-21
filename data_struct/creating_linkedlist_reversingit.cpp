#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
//constructing the structure for linked list
struct link
{
	int value;
	link *next;
};
//displaying the list using while loop
void display(link *start)
{
	while(start != NULL)
	{
		printf("->%d", start->value);
		start=start->next;
	}
	cout<<endl;
}
//this function returns the reversed list after using a while loop to do reversal process
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
//function add new node to the existing root node which has the original linked list
//enable to input list from user
/*void AddNode(link *start,link *node )
{
	while(start->next!= NULL)
	{

		start=start->next;

	}
	start->next=node;
}


int main()
{
	int x;
	int s;
	std::cin>> s;

	printf("%s\n","first entry" );
	link *strtnode =new link();
	strtnode->value=s;
	strtnode->next=NULL;
	
	display(strtnode);
	printf("%s\n","" );
	while (x!=0)
	{
		std::cin>> x;
		link *node =new link();
		node->value=x;
		printf("%s\n","new entry" );
		node->next=NULL;
		AddNode(strtnode,node);
		display(strtnode);
		printf("%s\n","" );
	}
}*/

// initialising and calling the functions
int main()
{
	int a[]={1,2,3,4,5};// edit this list if u want to edit the contents of the list
	int b=sizeof(a)/4;// finds the number of elements to be inserted into the list from the array
	//->4 is the size of each int inserted in the array
	link *strtnode =new link();//creating a new node
	strtnode->value=a[0];// insert value of 1st node
	strtnode->next=NULL;// initialise the next pointer to null
	
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
	//displaying the reversed list
	display(rev_list(strtnode));	

}
