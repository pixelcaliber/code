#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, timer = 1;
void dfs(vector<ll> a[], ll node, ll inn[], ll out[], ll vis[])
{
    vis[node] = 1;
    inn[node] = timer;
    timer++;
    for (auto &&i : a[node])
    {
        if (vis[i] == 0)
        {
            dfs(a, i, inn, out, vis);
        }
    }
    out[node] = timer;
    timer++;
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
    ll vis[n + 1] = {0}, inn[n + 1], out[n + 1];
    dfs(a, 1, inn, out, vis);

    for (int i = 1; i < n + 1; i++)
    {
        cout << "node "<<i<< " "<< inn[i] << " " << out[i] << endl;
    }

    //make it appl for all components.. using loop..
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}