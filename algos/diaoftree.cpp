#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, mod = 1e9 + 7, maxD, maxnode;
void dfs(vector<ll> a[], ll node, ll vis[], ll d)
{
    vis[node] = 1;
    if (d > maxD)
    {
        maxD = d;
        maxnode = node;
    }
    for (auto &&i : a[node])
    {
        if (vis[i] == 0)
        {
            dfs(a, i, vis, d + 1);
        }
    }
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
    maxD = INT64_MIN;
    maxnode = 0;
    dfs(a, 1, vis, 0);

    for (int i = 0; i < n+1; i++)
    {
        vis[i] = 0;
    }
    maxD = INT64_MIN;
    dfs(a, maxnode, vis, 0);
    cout << maxD << endl;
}
int main()
{
    solve();
}