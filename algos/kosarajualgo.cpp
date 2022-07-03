#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m;
stack<ll>topo_sort;
vector<ll>dfs_array;
void dfs_toposort(vector<ll>a[], ll node, ll vis[]){

    vis[node] = 1;
    for (int i = 0; i < a[node].size(); i++)
    {
        if(vis[a[node][i]] == 0)
        {
            dfs_toposort(a, a[node][i], vis);
        }
    }
        topo_sort.push(node);
}
void dfs(vector<ll>a[], ll node, ll vis[]){

      vis[node] = 1;
      dfs_array.push_back(node);
      for (int i = 0; i < a[node].size(); i++)
      { 
           if (vis[a[node][i]] == 0)
           {
                 dfs(a, a[node][i], vis);
           }
      }      
}
void kosaraju_dfs(vector<ll> a[]){

    ll vis[n+1] = {0};
    for (int i = 1; i < n+1; i++)
    {
        if (vis[i] == 0)
        {
            dfs_toposort(a, i, vis);
        }        
    }
    vector<ll>b[n+1];
    for (int i = 0; i < n+1; i++)
    {
         vis[i] = 0;
         for (int j = 0; j < a[i].size(); j++)
         {
              b[a[i][j]].push_back(i);
         }
    }
    vector<vector<ll>>res;
    while(!topo_sort.empty())
    {
        if (vis[topo_sort.top()] == 0)
        {
            dfs(b, topo_sort.top(), vis);
        }  
        res.push_back(dfs_array);
        dfs_array.clear();
        topo_sort.pop();
    }

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
    kosaraju_dfs(a);
}