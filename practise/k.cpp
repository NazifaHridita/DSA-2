#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,pair<int,int>>
int par[1000000];
int ans =0;
vector<int>adj_list[1000000];
int fr(int a)
{
    if(par[a]==a) return a;
    return par[a]=fr(par[a]);
}
int dsu(int a,int b)
{
    int pa = fr(a),pb = fr(b);
    if(pa==pb) return 0;
    adj_list[a].push_back(b);
    adj_list[b].push_back(a);
    par[pa]=pb;
    return 1;

}
int main()
{
    int n,e;
    cin >> n >>e;
    vector<pii>edge;
    for(int i=0;i<=n;i++)
    {
        par[i]=i; //make set()
    }
    for(int i=0;i<e;i++)
    {
        int a,b,c;
        cin >> a>>b>>c;
        edge.push_back({c,{a,b}});
    }
    sort(edge.begin(),edge.end());
    for(auto x : edge)
    {
        int res = dsu(x.second.first,x.second.second);
        if(res == 1) ans+=x.first;
    }
    for(int i=1;i<=n;i++)
    {
        cout << i << "has edge with ";
        for(auto x : adj_list[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
    cout << ans << endl;

}
