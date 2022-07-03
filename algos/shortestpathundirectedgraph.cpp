//unit weight..
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll n,m;
void bfs(vector<ll>a[], ll source, ll dist[]){
    queue<ll>q;
    q.push(source);
    dist[source] = 0;
        while (!q.empty())
        {
            ll node = q.front();
            q.pop();
            ll d = dist[node];
            for (auto it: a[node])
            {
                if (dist[it] > d+1)
                {
                    q.push(it);
                    dist[it] = d+1;
                }            
            }
        }
}   
int main()
{
    cin>>n>>m;
    vector<ll>a[n+1];
    for (int i = 0; i < m; i++)
    {
        ll x,y; cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    ll source;cin>>source;
    ll dist[n+1];
    for (int i = 0; i < n+1; i++)
    {
        dist[i] = INT32_MAX;
    }
    
    bfs(a, source, dist);
    for (int i = 0; i < n+1; i++)
    {
        cout<<dist[i]<<endl;
    }
    
    
}