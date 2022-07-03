#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m;
stack<ll> st;
void toposort_dfs(vector<pair<ll, ll>> a[], ll node, ll vis[])
{
    vis[node] = 1;
    for (auto &&i : a[node])
    {
        if (vis[i.first] == 0)
        {
            toposort_dfs(a, i.first, vis);
        }
    }
    st.push(node);
}
void short_dist(ll source, vector<pair<ll, ll>> a[], ll dist[])
{
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT32_MAX;
    }
    ll vis[n + 1] = {0};
    for (int i = 0; i < n + 1; i++)
    {
        if (vis[i] == 0)
        {
            toposort_dfs(a, i, vis);
        }
    }
    dist[source] = 0;
    while (!st.empty())
    {
        ll node = st.top();
        st.pop();
        if (dist[node] != INT32_MAX)
        {
            for (auto &&i : a[node])
            {
                if (i.second + dist[node] < dist[i.first])
                {
                    dist[i.first] = i.second + dist[node];
                }
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    vector<pair<ll, ll>> a[n + 1];
    for (int i = 0; i < m; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        a[x].push_back({y, w});
    }
    ll source;
    cin >> source;
    ll dist[n + 1];
    short_dist(source, a, dist);
    for (int i = 0; i <  n+1; i++)
    {
            cout<<dist[i]<<endl;
    }
    
}