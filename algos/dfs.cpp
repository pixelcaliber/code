#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>dfs_array;
ll n,m;
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
int main(){

            cin>>n>>m;
            vector<ll>a[n+1];
            for (int i = 0; i < m; i++)
            {
                ll x, y;cin>>x>>y;
                a[x].push_back(y);
                a[y].push_back(x);
            }
          //   ll x; cin>>x;
            ll vis[n+1] = {0};
            for (int i = 0; i < n+1; i++)
            {
                if (vis[i] == 0)
                {
                     dfs(a, i, vis);
                }
             }
            for (int i = 0; i < dfs_array.size(); i++)
            // {
                 cout<<dfs_array[i]<<" ";
            // }
}