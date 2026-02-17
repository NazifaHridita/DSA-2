#include<bits/stdc++.h>
using namespace std;
#define pii pair<pair<int,int>,int>
 int n,e;
vector<int>dis(100000,INT_MAX);
vector<int>par(100000,-1);

bool bellman(vector<pii>&edge,int src)
{
    dis[src] = 0;
    for(int i=1;i<=n;i++)
    {
        for(auto x : edge)
        {
            int parent = x.first.first,child = x.first.second,weight = x.second;
            if(dis[child] > dis[parent]+weight)
            {
                dis[child] = dis[parent] + weight ;
                par[child] = parent;
            }
        }
    }
    for(auto x : edge)
    {
        int parent = x.first.first,child = x.first.second,weight = x.second;
        if(dis[child] > dis[parent]+weight)
        {
            return false;
        }
    }
     return true;
}

int main()
{
    cin >> n >> e;
    vector<pii>edge;
    for(int i=0;i<e;i++)
    {
        int a,b,w;
        cin >>a >> w;
        edge.push_back({{a,b},w});
    }

    if(bellman(edge,1))
    {
        for(int i=1;i<=n;i++)
        {
            cout << "node " << i << " is " << dis[i] << " distance away from node 1\n";
        }
    }
    else{
        cout << "No solution" <<endl;
    }

}


/**
5 5
1 2 12
2 4 -2
2 3 -7
4 3 -6
3 5 15

3 3
1 2 4
2 3 1
3 1 -6

**/

