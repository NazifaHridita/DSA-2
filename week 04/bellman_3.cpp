#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,pair<int,int>>
  vector<int>dis(1000000,INT_MAX);
bool bellman(vector<pii>&edge,int n)
{

    vector<int>par(n+1,-1);
    dis[1]=0;
    for(int i=0;i<n;i++)
    {
        for(auto x : edge)
        {
            int u = x.second.first,v=x.second.second,w=x.first;
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                par[v]=u;
            }
        }
    }
    for(auto x : edge)
    {
        int u = x.second.first,v=x.second.second,w=x.first;
        if(dis[v] > dis[u]+w)
            return false;
    }
    return true;
}
int main()
{
    int n,e;
    cin >> n >> e;
    vector<pii>edge;
    for(int i=0;i<e;i++)
    {
        int a,b,c;
        cin >> a>>b>>c;
        edge.push_back({(-1)*c,{a,b}});
    }
    if(bellman(edge,n))
    {
        for(int i=1;i<=n;i++)
        {
             cout << "node " << i << " is " << (-1)*dis[i] << " distance away from node 1\n";
        }
    }
    else{
        cout << "no solution" <<endl;
    }

}
