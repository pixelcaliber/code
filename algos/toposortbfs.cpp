#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> topo_sort;
ll n, m;
bool bfs(vector<ll> a[], ll in_degree[])
{
    ll cnt = 0;
    queue<ll> q;
    for (int i = 0; i <= n; i++)
    {
        if (in_degree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        ll node = q.front();
        topo_sort.push_back(node);
        q.pop();
        cnt++;
        for (int j = 0; j < a[node].size(); j++)
        {
            if (in_degree[a[node][j]] > 0)
                in_degree[a[node][j]]--;
            if (in_degree[a[node][j]] == 0)
                q.push(a[node][j]);
        }
    }
    //  cout<<cnt<<endl; //0 se n tk h isliye n+1
    if (cnt == n + 1)
        return false;
    return true;
}
int main()
{
    cin >> n >> m;
    ll in_degree[n + 1] = {0}; //1 3
    vector<ll> a[n + 1];
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        a[x].push_back(y);
        in_degree[y]++;
    }

    if (bfs(a, in_degree))
        cout << "YES CYLCLIC" << endl;
    else
        cout << "NOT CLYCLIC" << endl;
    for (int i = 0; i < topo_sort.size(); i++)
    {
        cout << topo_sort[i] << " ";
    }
}