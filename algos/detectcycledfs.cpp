#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld double
ll n, m;
bool dfs_checkforcycle(vector<ll> a[], ll vis[], ll node, ll par_node)
{
    // for (int i = 1; i < n+1; i++)
    // {
    vis[node] = 1;
    for (int i = 0; i < a[node].size(); i++)
    {
        if (vis[a[node][i]] == 0)
        {
            if (dfs_checkforcycle(a, vis, a[node][i], node) == true)
            {
                return true;
            }
        }
        else if (par_node != a[node][i] && vis[a[node][i]] == 1)
        {
            return true;
        }
    }
    // }
    return false;
}
ll recStack[100001];
bool dfs_cycledirected(vector<ll>a[], ll vis[], ll node, ll par_node){

    vis[node] = recStack[node] = 1;

    for(auto &to: a[node]){
        if(!vis[node]){
            if(dfs_cycledirected(a, vis, to, node)){
                return true;
            }
        }
        else if (recStack[node] == 1)
        {
            return true;
        }
    }
    recStack[node] = false;
    return false;
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
        a[y].push_back(x);
    }
    ll vis[n + 1] = {0}, cnt = 0;
    // cout<<dfs_checkforcycle(a)<<endl;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cnt++;
            cout << dfs_checkforcycle(a, vis, i, -1) << endl;
        }
    }
}