#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <queue>
#include <stdbool.h>
using namespace std ;
#define [MAX_LEN 10];
#define TABLE_LEN 26;


struct person
{
	int age;
   char name[MAX_LEN];

};

unsigned int hash(char *name)
{
   return (97-int name[0]);
}

person *hash_table[TABLE_LEN];

void init_table()
{
   for int (i=0;i<TABLE_LEN;i++)
   {
      hash_table[i]=NULL
   }
}

void print_table()
{
   for( int =0 ; i<TABLE_LEN;i++)
   {
      if (hash_table[i]==NULL)
      {
         cout<<i<<"\t null "<<endl;
      }
      else
      {
         cout<<i<<"\t"<<hash_table[i]->name<<endl;
      }
   }
}

bool insert_table(person *p)
{
   if (p==NULL) return false;
   int index=hash(p->name);
   if (hash_table[index]!= NULL) return false;
   hash_table[index]=p;
   return true;
}

int main()
{
   init_table();
   print_table;
   person ass={ .name="ass",age=255}
   insert_table(&ass);
   print_table;
   return 0;
}