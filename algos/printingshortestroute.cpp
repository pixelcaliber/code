#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ld double
#define pb push_back
#define ll long long
#define ALL(x) x.begin(), x.end()
#define ALLR(x) x.rbegin(), x.rend()
#define vin(a) \
    int x;     \
    cin >> x;  \
    a.pb(x);
#define tests \
    int t;    \
    cin >> t; \
    while (t--)
#define bhaag                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef vector<ll> vll;
typedef map<ll, ll> mll;
typedef vector<vector<ll>> vvl;
typedef vector<pair<ll, ll>> vpp;
ll mod = 1e9 + 7;
ll n, cnt, m;
vll bfs_array;
void find_paths(vector<vector<int>> &paths, vector<int> &path, vector<int> parent[], int u)  //finds path...
{
    if (u == -1)
    {
        paths.push_back(path);
        return;
    }
    for (int par : parent[u])
    {

        path.push_back(u);

        find_paths(paths, path, parent, par);

        path.pop_back();
    }
}
void bfs(vector<ll> a[], vector<int> parent[], ll source, ll dist[])
{
    queue<ll> q;
    q.push(source);
    dist[source] = 0;
    parent[source] = {-1};

    while (!q.empty())
    {
        ll node = q.front();
        q.pop();
        ll d = dist[node];
        for (auto it : a[node])
        {
            if (dist[it] > d + 1)
            {
                q.push(it);
                parent[it].clear();
                parent[it].push_back(node);
                dist[it] = d + 1;
            }
            else if (dist[it] == dist[node] + 1)
            {
                parent[it].push_back(node);
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    vector<ll> a[20003]; ///increase n to 1e5
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    ll vis[20005] = {0}; /////increase n to 1e5
    ll dist[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dist[i] = INT32_MAX;
    }
    vector<vector<int>> paths;
    vector<int> path;
    vector<int> parent[n + 1];
    bfs(a, parent, 1, dist);

    if (dist[n] != INT32_MAX)
    {
        cout << dist[n] + 1 << '\n';      //prints distance...
    }
    else
    {
        cout << "IMPOSSIBLE";
        return;
    }
    // for (auto &&i : parent)
    // {
    //     for (int j : i)
    //     {
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    
    find_paths(paths, path, parent, n);
    for (auto v : paths) {
 
        // Since paths contain each
        // path in reverse order,
        // so reverse it
        reverse(v.begin(), v.end());
 
        // Print node for the current path
        for (int u : v)
            cout << u << " ";
        cout << endl;
    }
}
int main()
{
    bhaag;
    // tests
    solve();
}