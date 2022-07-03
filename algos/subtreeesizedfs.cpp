#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, mod = 1e9 + 7;
ll subsize[100001];
ll dfs(vector<ll> a[], ll node, ll vis[])
{
    vis[node] = 1;
    ll cnt = 1;
    for (auto &&i : a[node])
    {
        if (vis[i] == 0)
        {
            cnt += dfs(a, i, vis);
        }
    }
    subsize[node] = cnt;
    return cnt;
}
void solve()
{
    cin >> n >> m;
    vector<ll> a[n + 1];
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    ll vis[n + 1] = {0};

    dfs(a, 1, vis);
    for (int i = 1; i <= n; i++)
    {
        cout<<subsize[i]<<" ";
    }
    
}
int main()
{
    solve();
}