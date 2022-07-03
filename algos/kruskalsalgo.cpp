#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll parent[100000];
ll rankk[100000];
vector<vector<ll>> a;
void makeSet(ll n)
{
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }
}
ll findPar(ll node)
{
    if (parent[node] == node)
    {
        return node;
    }
    return parent[node] = findPar(parent[node]);
}
void union_set(ll u, ll v)
{
    u = findPar(u);
    v = findPar(v);
    if (rankk[u] > rankk[v])
    {
        parent[v] = u;
    }
    else if (rankk[u] < rankk[v])
    {
        parent[u] = v;
    }
    else
    {
        parent[u] = v;
        rankk[v]++;
    }
}
int main()
{
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        vector<ll> temp;
        temp.push_back(w);
        temp.push_back(u);
        temp.push_back(v);
        a.push_back(temp);
    }
    sort(a.begin(), a.end());
    makeSet(n + 1);
    ll cost = 0;
    vector<pair<ll, ll>> mst;
    for (int i = 0; i < m; i++)
    {
        if (findPar(a[i][1]) != findPar(a[i][2]))
        {
            cost += a[i][0];
            mst.push_back({a[i][1], a[i][2]});
            union_set(a[i][1], a[i][2]);
        }
    }
    cout << cost << endl;
    for (auto &&i : mst)
    {
        cout << i.first << "->" << i.second << endl;
    }
}