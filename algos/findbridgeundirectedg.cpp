//unit weight..
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll n,m;
ll in[1000001], low[1000001], timer;
vector<pair<ll, ll>>bridges;
void dfs(vector<ll>a[], ll node, ll vis[], ll par){
   
    vis[node] = 1;
    in[node] = low[node] = timer++;
    for (auto &i : a[node])
    {
        if (i == par)
        continue;
        if (vis[i] == 1)
        {
            low[node] = min(low[node], in[i]);
        }
        else{
            dfs(a, i, vis, node);
            if (low[i] > in[node])
            {
                bridges.push_back({node, i});
                cout<<node<<" - "<<i<<endl;
            }
            low[node] = min(low[i], low[node]);
        }
    }
    
}
int main()
{
    cin>>n>>m;
    vector<ll>a[n+1];
    for (int i = 0; i < m; i++)
    {
        ll x,y; cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    ll vis[n+1] = {0};
    dfs(a, 1, vis, -1);
    
}