#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll n, m;
ll in[10001], low[10001], timer;
set<ll> artcp;
void dfs(vector<ll> a[], ll node, ll vis[], ll par)
{
    vis[node] = 1;
    in[node] = low[node] = timer++;
    int cnt = 0;
    for (auto &&i : a[node])
    {
        if (i == par)
            continue;
        if (vis[i] == 1)
        {
            low[node] = min(low[node], in[i]);
        }
        else
        {
            dfs(a, i, vis, node);
            cnt++;
            low[node] = min(low[i], low[node]);
            if (low[i] >= in[node] && par != -1)
            {
                artcp.insert(node);
            }
        }
    }
    if (par == -1 && cnt > 1)
    {
        artcp.insert(node);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (true)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        vector<ll> a[n + 1];
        for (int i = 0; i < m; i++)
        {
            ll x, y;
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        ll vis[n + 1] = {0};
        for (int i = 1; i < n + 1; i++)
        {
            if (vis[i] == 0)
            {
                dfs(a, i, vis, -1);
            }
        }
        cout << artcp.size() << endl;
        artcp.clear();
        timer = 0;
        for (int i = 0; i <= n; i++)
        {
            in[i] = 0;
            low[i] = 0;
        }
    }
}