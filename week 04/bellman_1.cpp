#include<bits/stdc++.h>
using namespace std;
#define pii pair<pair<int,int>,int>


void bellman(vector<pii>&edge,vector<int>adj_list[],vector<int>&dis,vector<bool>&neg,int src,int n)
{
    dis[src] = 0;
    for(int i=1;i<=n;i++)
    {
        for(auto x : edge)
        {
            int parent = x.first.first,child = x.first.second,weight = x.second;
            if(dis[parent] !=INT_MAX && dis[child] > dis[parent]+weight)
            {
                dis[child] = dis[parent] + weight ;
            }
        }
    }
    queue<int> q;
    for(auto x : edge)
    {
        int parent = x.first.first,child = x.first.second,weight = x.second;
        if(dis[parent]!=INT_MAX && dis[child] > dis[parent]+weight)
        {
            if(!neg[child])
            {
                q.push(child);
            }
        }
    }
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        for(auto x : adj_list[t])
        {
            if(!neg[x])
            {
                neg[x] = true;
                q.push(x);
            }
        }
    }

}

int main()
{
    while(1)
    {
        int n,e,q,s;
        cin >> n >> e >> q >>s;
        if (n == 0 && e == 0 && q == 0 && s == 0)
            break;
        vector<pii>edge;
        vector<int>adj_list[n+1];
        for(int i=0;i<e;i++)
        {
            int a,b,w;
            cin >> a >> b>> w;
            edge.push_back({{a,b},w});
            adj_list[a].push_back(b);
        }
        vector<int>dis(n,INT_MAX);
        vector<bool>neg(n,false);
        bellman(edge,adj_list,dis,neg,s,n);

        while(q--)
        {
            int t;
            cin >> t;
            if(dis[t]==INT_MAX)
                cout << "Impossible"<<endl;
            else if(neg[t])
                cout << "-infinity" <<endl;
            else
                cout << dis[t]<<endl;

        }





    }
}
