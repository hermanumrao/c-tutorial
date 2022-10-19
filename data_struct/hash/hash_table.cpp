#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <queue>
#include <string.h>
#include <stdbool.h>
using namespace std ;
#define MAX_LEN 10
#define TABLE_LEN 26


struct person
{
   char name[MAX_LEN];
   int age;
   person (char *p, int a)
   {
      strcpy (name,p);
      age= a;
   }
};

int myhash(char *name)
{
   int c=int(name[0])-97;
   return c;
}

person *hash_table[TABLE_LEN];

void init_table()
{
   int i=0;
   while(i<TABLE_LEN)
   {
      i=i+1;
      hash_table[i]=NULL;
   }
}

void print_table()
{
   for( int i=0 ; i<TABLE_LEN;i++)
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
   int index=myhash(p->name);
   if (hash_table[index]!= NULL) return false;
   hash_table[index]=p;
   return true;
}

int main()
{
   init_table();
   
   print_table();
   person *ar1=new person("name",25);
   insert_table(ar1);
   person *ar2=new person("ali",25);
   insert_table(ar2);
   person *ar3=new person("dgb",25);
   insert_table(ar3);
   person *ar4=new person("brtb",25);
   insert_table(ar4);
   person *ar5=new person("rhbt",25);
   insert_table(ar5);
   person *ar6=new person("pbgnh",25);
   insert_table(ar6);
   cout<<"---------------------"<<endl;
   print_table();
   return 0;
}
