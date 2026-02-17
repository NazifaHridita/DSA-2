#include<bits/stdc++.h>
using namespace std;

struct node
{
    bool eof;
    node* child[26];
};

node *root;

node* createnode()
{
    node* newnode = new node[sizeof(node)];
    for(int i=0;i<26;i++)
    {
        newnode->child[i]=NULL;
    }
    newnode->eof = false;
    return newnode;
}

void insert_node(string s)
{
    node *cur = root;
    for(int i=0;i<s.size(),i++)
    {
        int j = s[i] - 'A';
        if(cur[j]->child == NULL)
        {
            cur[j]->child = createnode();
        }
        cur = cur->child[j];
    }
    cur->eow = true;
}

void print(node *cur=root,string s=" ")
{
    if(cur->eof == true) cout << s << endl;
    for(int i=0;i<26;i++)
    {
        if(cur->child[i]==NULL) continue;
        char j = i+'A';
        print(cur->child[i],s+j);
    }
}

bool find_node(string s)
{
    node *cur = root;
    for(int i=0;i<s.size();i++)
    {
        if(cur->child[i]==NULL) return false;
        cur = cur->child[i];
    }
    return cur->eof;
}

bool is_leaf(node *cur)
{
    for(int i=0;i<26;i++)
    {
        if(cur->child[i]!=NULL) return false;
    }
    return true;
}

bool is_junction(node *cur)
{
    if(cur->eow) return true;
    if(is_leaf(cur)) return false;
    return true;
}
void remove_edge(node *cur,char c,int d)
{
    if(d==0) return;
    int j = c - 'A';
    node *del = cur->child[j];
    cur->child[j] = NULL;
    free(del);
}
int delete_node(string s,node* cur=root,int i=0)
{
    if(cur==NULL) return 0
    if(i==s.size())
    {
        if(!cur->eow) return 0; //nothing to delete
        if(!is_leaf(cur)) //leaf node na hole delte korbo na
        {
            cur->eow = false;
            return 0;
        }
        return 1;
    }
    int j = s[i]-'A' ;
    int d = delete_node( s,cur->child[j],i+1);
    remove_edge(cur,s[i],d);
    if(is_junction(cur)) d=0;
    return d;
}
