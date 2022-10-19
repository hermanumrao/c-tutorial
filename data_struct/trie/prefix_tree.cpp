#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <queue>
#include <string.h>
#include <stdbool.h>
using namespace std ;

#define alpha_max 26 

struct root_node
{
	char value;
	struct root_node *word[alpha_max];
	bool word_end;
};


root_node *init_node(char ch,bool end)
{
	root_node *node = new root_node();
	node->value=ch;
	node->word_end=end;
	node->value=ch;
	for (int i=0; i<alpha_max; i++)
	{
		node->word[i]=NULL;
	}
	return node;
}

void display_root(root_node *node)
{
	cout<<node->value;
	if (node->word_end==true)
	{
		cout<<'*';
		cout<<endl;
	}
	for (int i=0;i<alpha_max;i++)
	{
		if (node->word[i]!= NULL)
		{
			display_root(node->word[i]);				
		}
	}
}

void AddNode(root_node *root,char ch,bool end)
{
	root_node *pnode= init_node(ch,end);
	root->word[(int(ch)-97)]=pnode;

}

void insert_word(root_node *root,const char *wr)
{
	for (int i=0; i<((strlen(wr))-1) ; i++)
	{
		if (root->word[int(wr[i])-97]==NULL)
		{
			AddNode(root,wr[i],false);
		}
		root=root->word[int(wr[i])-97];

	}
	char last=wr[strlen(wr)-1];
	if (root->word[int(last)-97]==NULL)
	{
		AddNode(root,wr[strlen(wr)-1],true);
	}
	else
	{
		root->word[int(last)-97]->word_end=true;
	}
}

int main()
{
	root_node *root=init_node('_',true);
	insert_word(root,"done");
	insert_word(root,"asd");
	insert_word(root,"do");
	insert_word(root,"dont");
	insert_word(root,"blast");
	insert_word(root,"win");
	insert_word(root,"won");

	display_root(root);

	return 0;
}
