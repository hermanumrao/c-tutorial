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
    bool leaf;
    struct stnode *children[alpha_max];
    char chr[str_len];
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


/*displying the list one of the most impotrant jobs*/
void display_st(stnode *root,const char *st)
{
    for (int i=0;i<(root->end-root->start);i++)
    {
        cout<<"suffix-"<<root->start<<" "<<root->end<<root->leaf;

    }
}



/*the biggest challange is over write function
    we need to first check till which charecter of string is the function repeated
    then we rewrite node->end till that point and add two new nodes
        1>has the original node->end point and same node->suffixIndex
        2>has new stuff */
void over_write(const char *st ,stnode *root)
{
    return;
}


void ins_strie(const char *st ,stnode *root)
{
    int l=strlen(st)-1;
    for (int i=(l);i>0;i--)
    {
        cout<<i<<st[l-i]<<int(st[l-i]);
        if (root->children[int(st[l-i])]==NULL)
        {
            cout<<"suffix->";
            int tmp=i;
            while (tmp>0)
            {
                cout<<st[l-tmp];
                tmp=tmp-1;
            }
            cout<<endl;
            stnode *node=init_node();
            node->start=l-i+1;
            node->end=l+1;
            node->suffixIndex=l-i+1;
            root->children[int(st[l-i])]=node;
        }
        else
        {
            //insert other stuff using the over_write function
            cout<<"over write"<<endl;
            over_write(st,root);
        }
    }
    return;
}

int main()
{
    cout<<"main---"<<endl;
    //first create a root node
    stnode *root=init_node();
    //input string we want to insert 
    char st[str_len]="aba";
    int tmp = strlen(st);
    st[tmp]='#';
    cout<<st<<endl;
/*-->next we use a function to insert into root node*/

    ins_strie(st,root);
    // for (int i=0;i<127;i++)
    // {
    //     char a=char(i);
    //     cout<<a<<i<<int( )<<endl;
    // }


}
