#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld double
vector<ll> bfs_array;
ll n, m;
queue<pair<ll, ll>> q;
ll par_node;
bool cycle(vector<ll> a[], ll vis[], ll i)
{
     // for (int i = 1; i < n+1; i++)
     // {
     q.push({i, -1});
     vis[i] = 1;
     while (!q.empty())
     {
          ll node = q.front().first;
          par_node = q.front().second;
          bfs_array.push_back(node);
          q.pop();
          for (int j = 0; j < a[node].size(); j++)
          {
               if (vis[a[node][j]] == 0)
               {
                    // par_node = node;
                    vis[a[node][j]] = 1;
                    q.push({a[node][j], node}); //or here we can write par_node in place of node.. and uncmmt abv line
               }
               else if (vis[a[node][j]] == 1 && a[node][j] != par_node)
               {
                    return true;
               }
          }
     }
     // }
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
     ll vis[n + 1] = {0};
     // cout<<cycle(a)<<endl;
     for (int i = 1; i <= n; i++)
     {
          if (!vis[i])
          {
               cout << cycle(a, vis, i) << endl;
          }
     }
     //   for (int i = 0; i < bfs_array.size(); i++)
     //   {
     //       cout<<bfs_array[i]<<" ";
     //   }
}