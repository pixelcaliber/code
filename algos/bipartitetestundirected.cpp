#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m;
ll col[100001];//O(e+n) o(n)
bool bpt_dfs_using(ll node, vector<ll> a[], ll vis[], ll c)
{
    vis[node] = 1;
    col[node] = c;
    for (auto &&i : a[node])
    {
        if (vis[i] == 0)
            return (bpt_dfs_using(i, a, vis, c ^ 1));
        
        else if (col[node] == col[i])
            return false;
    }
    return true;
}
int main()
{
    cin >> n >> m;
    vector<ll> a[n + 1];
    ll vis[n + 1] = {0};
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    //make it appl for all components.. using loop..
    for (int i = 1; i < n+1; i++)
    {
        if (vis[i] == 0)
        {
             cout << bpt_dfs_using(i, a, vis, 0);
        }
    }
    
   
}