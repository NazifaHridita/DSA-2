
#include<bits/stdc++.h>
using namespace std;
#define pii pair<long long,long long>
#define ll long long
vector<ll>dis(500005,1e18);
vector<ll>par(500005,-1);
vector<bool>vis(500005,false);

void dijsktra(vector<pii> adj_list[],ll src)
{
    dis[src] = 0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({dis[src],src});
    while(!pq.empty())
    {
       auto top = pq.top();
       pq.pop();
      ll parent = top.second;
      if(vis[parent]) continue;
       vis[parent]=true;
       for(auto  x : adj_list[parent] )
       {
           ll child = x.first , weight = x.second;
           if(vis[child])continue;
           if( dis[child] > dis[parent] + weight)
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,e,s,t;
    cin >> n >> e >> s >> t;
    vector<pii>adj_list[n+1];

    for(int i=0;i<e;i++)
    {
        ll a,b,w;
        cin >> a>>b>>w;
        adj_list[a].push_back({b,w});
    }
     dijsktra(adj_list,s);
    ll node = t;
    int cnt=0;
    vector<pii>ans;
    while(par[node]!=-1)
    {
        ans.push_back({par[node],node});
        node = par[node];
        cnt++;
    }
    reverse(ans.begin(),ans.end());
     if(dis[t]==1e18)
     {
         cout << -1 << endl;
     }
     else{
        cout << dis[t]<<" " << cnt << endl;
     for(auto x : ans)
     {
         cout << x.first << " " <<x.second <<endl;
     }
     }


}
