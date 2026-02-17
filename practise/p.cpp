#include<bits/stdc++.h>
using namespace std;

void prim(vector<pair<int,int>>adj_list[],int v)
{
    vector<bool>vis(v+1,false);
    vector<int>par(v+1,-1);
    vector<int>dis(v+1,INT_MAX);
    dis[1]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({dis[1],1});
    while(!pq.empty())
    {
        auto top =pq.top();pq.pop();//nit front top
        int u = top.second;
        vis[u] = true;
        for(auto x : adj_list[u])
        {
            int v = x.first,w = x.second;
            if(vis[v])continue;
            if(dis[v] > w)
            {
                dis[v] = w;
                par[v]= u;
                pq.push({dis[v],v});
            }
        }
    }
    int t_c=0;
    for(int i=1;i<=v;i++)
    {
        if(par[i]!=-1)
        {
            cout << par[i] << " -> " << i << "with cost" << dis[i] << endl;
            t_c+=dis[i];
        }
    }
    cout << "total cost: " <<t_c <<endl;
}

int main()
{
    int n,e;
    cin >> n >>e;
    vector<pair<int,int>>adj_list[n+1];
    for(int i=0;i<e;i++)
    {
        int a,b,c;
        cin >> a >>b >>c;
        adj_list[a].push_back({b,c});
        adj_list[b].push_back({a,c});
    }
    prim(adj_list,n);
}
