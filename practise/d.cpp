#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
vector<int>dis(100000,INT_MAX);
vector<int>par(100000,-1);
vector<bool>vis(100000,false);
void dijkstra(vector<pii>adj_list[],int src)
{
    dis[src]=0;
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    pq.push({dis[src],src});
    while(!pq.empty())
    {
        auto top = pq.top();pq.pop();
        int u = top.second;
        vis[u]=true;
        for(auto x : adj_list[u])
        {
            int v = x.first,w = x.second;
            if(vis[v]) continue;
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                par[v]=u;
                pq.push({dis[v],v});
            }
        }
    }
}
int main()
{
    int n,e;
    cin >> n >> e;
    vector<pii>adj_list[n+1];
    for(int i=0;i<e;i++)
    {
        int a,b,c;
        cin >> a >> b >>c;
        adj_list[a].push_back({b,c});
    }
    dijkstra(adj_list,1);
    for(int i=1;i<n+1;i++)
    {
        cout << i << " is " << dis[i] << " from node 1 "<<endl;
    }
}
