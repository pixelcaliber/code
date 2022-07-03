//diff weights.. undirected graph..
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m;
void bfs(vector<pair<ll, ll>> ap[], ll source, ll dist[])
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    dist[source] = 0;
    pq.push({0, source});
    while (!pq.empty())
    {
        ll d_v = pq.top().first;
        ll v = pq.top().second;
        pq.pop();
        // for (auto it = ap[v].begin(); it != ap[v].end() ; it++)
        // {
        //         ll next = it->first;
        //         ll nextDist = it->second;
        //         if (dist[next] > dist[v] + nextDist)
        //         {
        //             dist[next] = dist[v] + nextDist;
        //             pq.push({dist[next], next});                    
        //         }
        // }
        if (d_v != dist[v])
            continue;

        for (auto edge : ap[v]) {
            int to = edge.first;
            int len = edge.second;

            if (dist[v] + len < dist[to]) {
                dist[to] = dist[v] + len;
                pq.push({dist[to], to});
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    vector<pair<ll, ll>> ap[n+1];
    for (int i = 0; i < m; i++)
    {
        ll x, y, w; cin >> x >> y >> w;
        ap[x].push_back({y, w});
        ap[y].push_back({x, w});
    }
    ll source;
    cin >> source;
    ll dist[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dist[i] = INT32_MAX;
    }
    bfs(ap, source, dist);
    for (int i = 1; i < n + 1; i++)
    {
        cout << dist[i] << endl;
    }
}