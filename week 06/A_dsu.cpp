
#include<bits/stdc++.h>
using namespace std;
int par[1000000];

void make_set(int x)
{
    par[x] = x;
}
int find_root(int x)
{
    if(x==par[x]) return x;
    return par[x] = find_root(par[x]);
}
void dsu(int a,int b)
{
    int pa = find_root(a),pb = find_root(b);
    if(pa == pb) return ;
    par[pa] = pb;
}
int main()
{
    int n,q;
    cin >> n >> q;
    for(int i=1;i<n+1;i++)
    {
        make_set(i);
    }
    while(q--)
    {
        int t,u,v;
        cin >> t >> u >> v;
        if(t==0)
        {
           dsu(u,v);
        }
        else if(t==1)
        {
            if(find_root(u)==find_root(v)) cout << "1" << endl;
            else
            cout << "0" <<endl;

        }

    }

}
