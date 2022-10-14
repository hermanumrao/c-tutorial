#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <string.h>
#include <stdbool.h>
#include <typeinfo>
using namespace std ;

#define alpha_max 27
#define str_len 256 

struct stnode
{
    bool leaf;
    struct stnode *children[alpha_max];
    char chr[str_len];
    int start;
    int end;
    // int suffixIndex;
};

stnode *init_node(int start1,int end1,bool leaf1)
{
    stnode *node = new stnode();
    node->start=start1;
    node->end=end1;
    // node->suffixIndex=0;
    node->leaf=leaf1;
    for (int i=0; i<alpha_max; i++)
    {
        node->children[i]=NULL;
    }
    return node;
}



void stdisplay(stnode *root,const char *st)
{
    for (int it2=0;it2<alpha_max;it2++)
    {
        if(root->children[it2]!=NULL)
        {
            for(int it3=(root->children[it2]->start-1);it3<root->children[it2]->end;it3++)
            {
                cout<<st[it3];
            }
            cout<<":";
            if (root->children[it2]->leaf==true) cout<<"^"<<endl;
            else stdisplay(root->children[it2],st);

        }
    }
}

int main()
{
    char st[str_len] ="abcdaef";
    int tmp = strlen(st);
    st[tmp]='#';
    cout<<st<<tmp<<endl;
    stnode *root=init_node(1,tmp,false);
    for (int it=0; (it+1)<strlen(st);it++)
    {
        if (root->children[int(st[it])-97]==NULL)
        {
            cout<<"yes"<<endl;
            stnode *node = init_node(it+1,strlen(st),true);
            root->children[int(st[it])-97]=node;
        }
        else
        {
            cout<<"over_write"<<endl;
        }

    }
    for (int itt=0;itt<alpha_max;itt++) if(root->children[itt]!=NULL) 
    {
        cout<<"#"<<typeid(root->children[itt]).name()<<root->children[itt]->start<<root->children[itt]->end;}
    cout<<endl;

    cout<<"--------"<<endl;
    stdisplay(root,st);

}
