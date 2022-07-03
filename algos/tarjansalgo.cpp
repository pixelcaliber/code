#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, ans_cnt;
ll in[100001], low[100001], timer = 1, pres[100001];
stack<ll> s;
void dfs(vector<ll> a[], ll vis[], ll node, ll par)
{
    vis[node] = 1;
    in[node] = low[node] = timer++;
    s.push(node);
    pres[node] = 1;
    for (auto &&i : a[node])
    {
        if (vis[i] == 1 && (pres[i] == 1))
        {
            low[node] = min(low[node], in[i]);
        }
        else if (vis[i] == 0)
        {
            dfs(a, vis, i, node);
            if (pres[i] == 1)
                low[node] = min(low[node], low[i]);
        }
    }
            if (low[node] == in[node])
            {
                ans_cnt++;
                // cout << low[node] << " " << node << endl;
                while (true)
                {
                    ll t = s.top();
                    s.pop();
                    pres[t] = 0;
                    if (t == node)
                        break;
                }
            }
}
void tarjan(vector<ll> a[])
{
    ll vis[n + 1] = {0};
    for (int i = 1; i < n + 1; i++)
    {
        if (vis[i] == 0)
        {
            dfs(a, vis, i, -1);
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        cout << low[i] << " ";
    }
    // cout<<ans_cnt<<endl;
}
int main()
{
    cin >> n >> m;
    vector<ll> a[n + 1];
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }
    tarjan(a);
}