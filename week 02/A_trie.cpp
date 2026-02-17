
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int eow;
    node* child[26];
    int cnt;
};

node *root;

node* createnode()
{
    node* newnode = new node();
    for(int i=0;i<26;i++)
    {
        newnode->child[i]=NULL;
    }
    newnode->eow = false;
    return newnode;
}

void insert_node(string s)
{
    node *cur = root;
    for(int i=0;i<s.size();i++)
    {
        int j = s[i] - 'a';
        if(cur->child[j] == NULL)
        {
            cur->child[j] = createnode();
        }
        cur = cur->child[j];
        cur->cnt++;
    }
    cur->eow = true;
}

void print(node *cur=root,string s=" ")
{
    if(cur->eow == true) cout << s << endl;
    for(int i=0;i<26;i++)
    {
        if(cur->child[i]==NULL) continue;
        char j = i+'a';
        print(cur->child[i],s+j);
    }
}

int find_node(string s)
{
    node *cur = root;
    for(int i=0;i<s.size();i++)
    {
        int j = s[i]-'a';
        if(cur->child[j]==NULL) return 0;
        cur = cur->child[j];
    }
    return cur->cnt;
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
    int j = c - 'a';
    node *del = cur->child[j];
    cur->child[j] = NULL;
    free(del);
}
int delete_node(string s,node* cur=root,int i=0)
{
    if(cur==NULL) return 0;
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
    int j = s[i]-'a' ;
    int d = delete_node( s,cur->child[j],i+1);
    remove_edge(cur,s[i],d);
    if(is_junction(cur)) d=0;
    return d;
}
int main()
{
    root = createnode();
    int n,q;
    cin >> n>>q;
    for(int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        insert_node(s);
    }
    while(q--)
    {
        string s;
        cin >> s;
        int a = find_node(s);
        cout << a <<endl;
    }
}
