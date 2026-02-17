#include<bits/stdc++.h>

using namespace std;

int par[1000];
vector<int> graph[1000]; // adjacency list of MST // array of vectors

void make_set(int x)
{
    par[x]=x;
}

int fr(int x)
{
    if(x==par[x]) return x; //base case
    return par[x]=fr(par[x]);
}

int union_(int a,int b)
{
    int pa=fr(a),pb=fr(b);
    if(pa==pb) return 0;
    graph[a].push_back(b);
    graph[b].push_back(a);
    par[pa]=pb;
    return 1;
}

int main()
{

    int ans = 0;
    int n,e; cin >> n >> e;

    for(int i=1;i<=n;i++)
    {
        make_set(i);
        graph[i].clear();
    };

    vector<pair<int,pair<int,int>>> edges;
    for(int i=0;i<e;i++)
    {
        int a,b,w;
        cin >> a >> b >> w;
        int ex = __builtin_ctzll(w);
        edges.push_back({ex,{a,b}});
    }
    sort(edges.begin(),edges.end());

    for(auto v:edges)
    {
        cout << v.first << " " << v.second.first << " " << v.second.second;
        cout << endl;
    }
    for(auto v:edges)
    {

        int ret=union_(v.second.first,v.second.second);
        if(ret==1) ans+=v.first;
    }
    for(int i=1;i<=n;i++)
    {
        cout << i << " has edges with: ";
        for(auto x:graph[i]) cout << x << " ";
        cout << endl;
    }

     cout << endl << ans+1 << endl;


    return 0;
}

/**

7 11
1 2 2
1 7 8
1 6 14
2 3 19
2 6 25
3 4 9
3 5 5
3 6 17
4 5 1
5 6 13
6 7 21

**/
