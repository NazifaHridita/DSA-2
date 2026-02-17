
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int n,e;

//vector<int>par(100000,-1);


void dijsktra(vector<pii> adj_list[],vector<int>&dis,vector<bool>&vis,int src)
{
    dis[src] = 0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({dis[src],src});
    while(!pq.empty())
    {
       auto top = pq.top();
       pq.pop();
       int parent = top.second;
       vis[parent]=true;
       for(auto  x : adj_list[parent] )
       {
           int child = x.first , weight = x.second;
           if(!vis[child] && dis[child] > dis[parent] + weight)
           {
               dis[child] = dis[parent]+weight;
               //par[child] = parent;
               pq.push({dis[child],child});
           }
       }
    }
}

int main()
{

    cin >> n >> e;
    vector<pii> adj_list[n+1];
    vector<pii> adj_list2[n+1];
    vector<pair<int,pair<int,int>>>edge;
    for(int i=0;i<e;i++)
    {
        int a,b,w;
        cin >> a >> b >>w ;
        adj_list[a].push_back({b,w});
        adj_list2[b].push_back({a,w});
        edge.push_back({w,{a,b}});
    }
    vector<int>dis(100000,INT_MAX);
    vector<int>dis2(100000,INT_MAX);

    vector<bool>vis(100000,false);
    vector<bool>vis2(100000,false);
    dijsktra(adj_list,dis,vis,1);
    dijsktra(adj_list2,dis2,vis2,n);


//    for(int i=1;i<=n;i++)
//    {
//        cout << "node " << i << " is " << dis[i] << " distance away from node 1\n";
//    }
      int ans = INT_MAX;
      for(auto x : edge)
      {
          ans = min(ans,dis[x.second.first]+dis2[x.second.second]+x.first/2);
      }
      cout <<ans << endl;

}

/**
6 10
1 2 50
1 4 10
2 4 15
1 3 45
2 3 10
4 5 15
6 5 3
5 3 35
3 5 30
5 2 20

**/
