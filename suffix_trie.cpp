#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <string.h>
#include <stdbool.h>
using namespace std ;

#define alpha_max 27
#define str_len 256 

struct stnode
{
    
    struct stnode *children[alpha_max];
    int start;
    int end;
    int suffixIndex;
};

stnode *init_node()
{
    stnode *node = new stnode();
    node->start=0;
    node->end=0;
    node->suffixIndex=0;
    
    for (int i=0; i<alpha_max; i++)
    {
        node->children[i]=NULL;
    }
    return node;
}

void ins_strie(const char *st ,stnode *root)
{

}

int main()
{
    cout<<"main---"<<endl;
    //first create a root node
    stnode *root=init_node();
    //input string we want to insert 
    char st[str_len]="jjbcjbcjbcjb";
    cout<<st[1];
    //next we use a function to insert into root node



}