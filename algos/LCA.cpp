#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m;
vector<ll> bfs_array;
ll level[100001];
vector<pair<ll, ll>>ap;
void bfs(vector<ll> a[])
{
    ll vis[n + 1] = {0};
    queue<ll> q;
    for (int i = 1; i < n + 1; i++)
    {
        if (vis[i] == 0)
        {
            q.push(i);
            ll par;
            ap.push_back({i, -1});
            vis[i] = 1;
            level[i] = 0;
            while (!q.empty())
            {
                ll node = q.front();
                par = node;
                bfs_array.push_back(node);
                q.pop();
                for (int j = 0; j < a[node].size(); j++)
                {
                    if (vis[a[node][j]] == 0)
                    {
                        ap.push_back({a[node][j], par});
                        level[a[node][j]] = level[node] + 1;
                        q.push(a[node][j]);
                        vis[a[node][j]] = 1;
                    }
                }
            }
        }
    }
}
void lca(ll x, ll y){
    if (level[y]<level[x])
    {
        swap(x, y);
    }
    ll d = level[y] - level[x];
    // cout<<d<<endl;
    // cout<<ap[y].second<<endl<<ap[x].second<<endl;
    while (d>0)
    {
        y = ap[y].second;
        d--;
    }
    if (x == y)
    {
        cout<<x<<endl;
        return;
    }
    while (ap[x].second != ap[y].second)
    {
        x = ap[x].second, y = ap[y].second;
    }
    cout<< ap[x].second;
}
int main()
{
    cin >> n >> m;
    vector<ll> a[n + 1];
    for (int i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    bfs(a);
    // for (int i = 0; i < bfs_array.size(); i++)
    // {
    //     cout << bfs_array[i] << " " << level[bfs_array[i]] << endl;
    // }
    ap.push_back({0, 0});
    sort(ap.begin(), ap.end());
    // for (int i = 0; i < ap.size(); i++)
    // {
    //     cout<<ap[i].first<<" "<<ap[i].second<<endl;
    // }
    lca(6, 4);
    
}