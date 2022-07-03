#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl '\n'
ll n, m;
ll adj[1001][1001];
ll vis[1001][1001];
ll dist[1001][1001];
vector<pair<ll, ll>>bfs_array;
ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, 1, 0, -1};
bool isvalid(ll x, ll y)
{
    if (x < 0 || y < 0 || x >= n || y >= m)
    {
        return false;
    }
    if (vis[x][y] == 1)
    {
        return false;
    }
    return true;
}
void bfs(ll crrx, ll crry){

    vis[crrx][crry] = 1;
    queue<pair<ll, ll>>q;
    q.push({crrx, crry});
    dist[crrx][crry] = 0; 
    while(!q.empty()){

        ll x = q.front().first;
        ll y = q.front().second;
        bfs_array.push_back({x, y});
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (isvalid(x+dx[i], y+dy[i]))
            {
                ll newx = x+dx[i];
                ll newy = y+dy[i];
                q.push({newx, newy});
                vis[newx][newy] = 1;
                dist[newx][newy] = dist[x][y] + 1;
            }
        }        
    }

}
int main(){
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>adj[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
             if (vis[i][j] == 0)
             {
                 bfs(i, j);
             }
        }        
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    
    // for (int i = 0; i < bfs_array.size(); i++)
    // {
    //     cout<<bfs_array[i].first<<" "<<bfs_array[i].second<<endl;
    // }
    
}