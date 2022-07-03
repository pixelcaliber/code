#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m;
void bfs(vector<pair<ll, ll>> a[], ll parent[])
{
    ll key[n + 1];
    bool mst[n + 1];
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    for (int i = 0; i < n + 1; i++)
    {
        key[i] = INT32_MAX;
        mst[i] = false;
    }
    key[0] = 0;
    pq.push({0, 0});

    for (int count = 0; count < n; count++)
    {
        ll ind = pq.top().second;
        pq.pop();
        mst[ind] = true;
        for (auto &&i : a[ind])
        {
            if (key[i.first] > i.second && mst[i.first] == false)
            {
                key[i.first] = i.second;
                pq.push({i.second, i.first});
                parent[i.first] = ind;
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
        a[y].push_back({x, w});
    }
    ll parent[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        parent[i] = -1;
    }
    bfs(a, parent);
    for (int i = 1; i < n; i++)
    {
        cout << parent[i] << endl;
    }
}