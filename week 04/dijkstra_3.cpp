#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int n,e;
vector<int>dis(100005,INT_MAX);
vector<int>par(100005,-1);
vector<bool>vis(100005,false);

void dijsktra(vector<pii> adj_list[],int src)
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
               par[child] = parent;
               pq.push({dis[child],child});
           }
       }
    }
}

int main()
{

    cin >> n >> e;
    vector<pii> adj_list[n+1];
    for(int i=0;i<e;i++)
    {
        int a,b,w;
        cin >> a >> b >>w ;
        adj_list[a].push_back({b,w});
        adj_list[b].push_back({a,w});
    }

    dijsktra(adj_list,1);

//    for(int i=1;i<=n;i++)
//    {
//        cout << "node " << i << " is " << dis[i] << " distance away from node 1\n";
//    }
    vector<int>ans;
    int node = n ;
    if(dis[n]==INT_MAX)
    {
        cout << -1 <<endl;
    }
    else
    {
         while(node!=-1)
    {
        ans.push_back(node);
        node = par[node];
    }
    reverse(ans.begin(),ans.end());
    for(int x:ans)
    {
        cout << x << " ";
    }
    }

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
