#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

int v,e;
void spanning_tree(vector<vector<pii>>&adj_list,int v)
{
    vector<bool>vis(v,false);
    vector<int>parent(v,-1);
    vector<int>dis(v,INT_MAX);
    dis[0] = 0;
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    pq.push({0,0}); //{dis,node}
    while(!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        int node = top.second;
        vis[node] = true;
        for(auto x : adj_list[node])
        {
            int child = x.first;
            int weight = x.second;
            if(!vis[child] && dis[child] > weight)
            {
                dis[child] = weight;
                parent[child] = node;
                pq.push({dis[child],child});
            }
        }
    }

    int total_weight = 0;
    for(int i=1;i<v;i++)
    {
        if(parent[i] != -1)
        {
            cout << parent[i] << " - " << i << " with weight " << dis[i] << endl;
            total_weight += dis[i];
        }
    }

    cout << "Total weight of Minimum Spanning Tree is: " << total_weight << endl;


}
int main()
{
    cin >> v >> e;
    vector<vector<pii>>adj_list(v);
    for(int i=0;i<e;i++)
    {
        int a,b,w;
        cin >> a >> b >> w;
        adj_list[a].push_back({b,w});
        adj_list[b].push_back({a,w});
    }
    spanning_tree(adj_list,v);
}
