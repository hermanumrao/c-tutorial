#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct node
{
	int data;
	struct node *next;
} NODE ;

void display_bucket (NODE * list[])
{
	for (int i=0;i<10;i++)
	{
		NODE *l=list[i];
		while (l!=NULL)
		{
			printf("-> %d",l->data);
			l=l->next;
		}
		printf("\n");
	}
}

void free_list (NODE *l)
{
	if (l->next != NULL) free_list(l->next);
	free(l);
}
void free_bucket (NODE * list[])
{
	for (int i=0;i<10;i++)
	{
		free_list(list[i]);
	}
}


int inputele(int *ar,int n)
{
	int item,max;
	for (int i=0;i<n;i++)
	{
		scanf("%d",&item);
		ar[i]=item;
		if (item>max) max = item;
	}
	int l=log10(max);
	return (l+1);
}

void display(int * ar,int n)
{
	//int s=(sizeof(ar)/sizeof(ar[0]));
	for (int i=0; i<n;i++) printf("->%d ",ar[i]);
	printf("\n"); 
}



void RadixSort(int *ar, int l)
{
	NODE * list[10]; 
	for (int i=0;i<10;i++) list[i]=NULL;// initializing the list
	int pos;
	for (int i=0;i<10;i++)				// to make the first bucket
	{
		pos=((ar[i])%10);
		if (!list[pos]){ list[pos]= malloc(sizeof(NODE)); 
		list[pos]->data=ar[i];
		list[pos]->next=NULL;
	}
		else 
		{
			NODE *tmp= list[pos];
			while (tmp->next != NULL) tmp=tmp->next;
			tmp->next= malloc(sizeof(NODE));
			tmp=tmp->next;
			tmp->data=ar[i];
			tmp->next=NULL;
		}
	}
	display_bucket(list);
	//free_bucket(list);
	// NODE *tmp,*tmp1;
	// for (int i=1;i<l;i++)
	// {
	// 	NODE * list1[10];
	// 	for (int i=0;i<10;i++) list1[i]=NULL;// initializing the list
	// 	for (int i=0;i<10;i++)
	// 	{
	// 		while (list[i]!=NULL)
	// 		{
	// 			tmp=list[i];
	// 			tmp1=list1[pos];
	// 			if (tmp1 == NULL) tmp1=malloc(sizeof(NODE));
	// 			else 
	// 			{
	// 				while(tmp1->next!=NULL)(tmp1=tmp1->next);
	// 				tmp1->next=malloc(sizeof(NODE));		//insert to right pos in list1
	// 				tmp1=tmp1->next;
	// 			}
	// 			tmp1->data=list[i]->data;
	// 			tmp1->next=NULL;
	// 			free(tmp);
	// 		}
	// 	}
	// 	//cp(list,list1);
	// }
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	int ar[n];
	int l=inputele(ar,n);
	display(ar,n);
	RadixSort(ar,1);
	return 0;
}