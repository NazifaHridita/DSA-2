#include<bits/stdc++h>
using namespace std;
map<string,int>mp;
struct node
{
    bool eow;
    int cnt;
    node *child[26];

};
node *root;
node *createnode()
{
    node *newnode = new node();
    for(int i=0;i<26;i++)
    {
        newnode->child[i]=NULL;
    }
    newnode->eow=false;
    newnode->cnt =0;
    return newnode;
}

void insert_node(string s)
{
    node *cur = root;
    for(int i=0;i<s.size();i++)
    {
        int j = s[i]-'a';
        if(cur->child[i]==NULL) cur->child[j]=createnode();
        cur = cur->child[j];

    }

}
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        mp[s]++;
    }
}
