#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
vector<ll>bfs_array;
ll level[100001];

void bfs(vector<ll>a[], ll i){
   
     ll vis[n+1] = {0};
     queue<ll>q;
     vis[0] = 1;
            
        // for (int i = 1; i < n+1; i++)
        // {
            if (vis[i] == 0)
            {
                 q.push(i);
                 vis[i] = 1;
                 level[i] = 1;
                 while (!q.empty())
                {
                    ll node = q.front();
                    bfs_array.push_back(node);
                    q.pop();
                    for (int j = 0; j < a[node].size(); j++)
                    {
                        if (vis[a[node][j]] == 0)
                        {
                             level[a[node][j]] = level[node] + 1;
                             q.push(a[node][j]);
                             vis[a[node][j]] = 1;
                        }
                    }
                }
            }
        // }
}
int main(){

            cin>>n;
            m = n-1;
            vector<ll> a[n+1]; 
            for(int i = 0;i<m;i++) {
                ll u, v; 
                cin >> u >> v;
                a[u].push_back(v); 
                a[v].push_back(u); 
            }
            ll x;cin>>x;
            bfs(a, 1);
            // for (int i = 0; i < bfs_array.size(); i++)
            // {
            //     cout<<bfs_array[i]<<" "<<level[i]<<endl;;
            // }
            ll cnt = 0;
          for (int i = 0; i < 100001; i++)
          {
              if (level[i] == x)
              {
                  cnt++;
              }
          }
          cout<<cnt<<endl;
}