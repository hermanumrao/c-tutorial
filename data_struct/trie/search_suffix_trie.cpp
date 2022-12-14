#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <string.h>
#include <stdbool.h>
#include <typeinfo>
using namespace std ;

#define alpha_max 27
#define str_len 256 
//constructing the structure for each node of the suffix tree
struct stnode
{
    int start;
    int end;
    struct stnode *children[alpha_max];  //using an array of the same node to keep the other
};

int pos(char a)
{
    if (a=='#') return 26;
    else return (int(a)-97);
}

stnode *init_node(int start1,int end1)
{
    stnode *node = new stnode();
    node->start=start1;
    node->end=end1;
    // node->suffixIndex=0;
    for (int i=0; i<alpha_max; i++)
    {
        node->children[i]=NULL;
    }
    return node;
}



void stdisplay(stnode *root,const char *st)
{
    for (int itt=0;itt<alpha_max;itt++) if(root->children[itt]!=NULL) 
    {
        cout<<"#"<<typeid(root->children[itt]).name()<<root->children[itt]->start<<root->children[itt]->end;
    }
    cout<<endl;
    for (int it2=0;it2<alpha_max;it2++)
    {
        if(root->children[it2]!=NULL)
        {
            for(int it3=(root->children[it2]->start-1);it3<root->children[it2]->end;it3++)
            {
                cout<<st[it3];
            }
            cout<<":";
            if (root->children[it2]->end==strlen(st)) cout<<"^"<<endl;
            else 
            {
                
                cout<<"#"<<typeid(root->children[it2]).name()<<root->children[it2]->start<<root->children[it2]->end;
                stdisplay(root->children[it2],st);
            }

        }
    }
}

int check_similar(int start,int start2,int end,const char *st)
{
    int x;
    int tmp;
    if ((start-start2)>(end-start))
    {
        tmp=end-start;
    }
    else 
    tmp=start-start2;
    for (int it4=0;it4<tmp;it4++)
    {
        if(st[start+it4]==st[start2+it4]) x=x+1;        
    }
    
    return x;
}

stnode *overwrite(stnode *root,const char *st,int start2)
{
    int start=root->start;
    int end=root->end;
    int x =check_similar(start,start2,end,st);
    if(start2<start)
    {
        root->end=(start+x);
        if (x<=(end-start))
        {
            stnode *newNode1=init_node(start2+x+1,end);
            stnode *newNode2=init_node(start+x+1,end);
            root->children[pos(st[start2+x])]=newNode1;
            root->children[pos(st[start+x])]=newNode2;
            
        }
    }
    stdisplay(root,st);
    return root;
}

int search_similar(stnode *root,int start2,int end,const char *st,const char *st1)
{
    int start=root->start;
    int x=0;
    int tmp;
    if ((end-start+1)==strlen(st1))
    {
        cout<<"if1|";
        tmp=end-start;
    }
    else
    {
        tmp=end-start2;
        if((end-start2)>((root->end)-start))
        {
            if (root->children[pos(st[(root->end)-start+start2])]!=NULL) 
            {
                x=x+1;
                x=x+search_similar(root->children[pos(st[(root->end)-start+start2])],(root->end)-start+start2+1,end,st,st1);
            }
            else return x;
        }
    }
    for (int it4=0;it4<tmp;it4++)
    {
        if(st[start+it4]==st1[start2+it4])
        {
            x=x+1;        
        }

    }
    
    return x;
}

bool search(stnode *root, const char *st,const char *st1)
{
    if (root->children[pos(st1[0])] != NULL)
    {
        root=root->children[pos(st1[0])];
        int x=0;
        if (strlen(st1)>1) x =search_similar(root,1,strlen(st1),st,st1);
        x=x+1;
        if (x>=strlen(st1)) return true;
        else
        {
            return false;
        }
    }
    else return false;
}

int main()
{
    char st[str_len] ="abacad";
    int tmp = strlen(st);
    st[tmp]='#';
    cout<<st<<tmp<<endl;
    stnode *root=init_node(1,tmp);
    for (int it=strlen(st)-1; (it+1)>0;it--)
    {
        if (root->children[pos(st[it])]==NULL)
        {
            cout<<"written"<<endl;
            stnode *node = init_node(it+1,strlen(st));
            root->children[pos(st[it])]=node;
        }
        else
        {
            cout<<"over_written"<<it<<endl;
            root->children[pos(st[it])]=overwrite(root->children[pos(st[it])],st,it+1);

        }
    }
    cout<<"--------"<<endl;
    stdisplay(root,st);
    cout<<"--------"<<endl;
    bool found=search(root,st,"ad");
    if (found==true) cout<<"found it";
    else cout<<"not found";
}
