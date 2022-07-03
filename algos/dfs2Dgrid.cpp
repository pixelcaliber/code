#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m;
ll vis[1001][1001];
ll adj[1001][1001];
bool isvalid(ll x, ll y)
{
     if (x < 0 || y < 0 || x >= n || y >= m)
    {
        return false;
    }
    if (vis[x][y])
    {
        return false;
    }
    return true;
}
ll dx[] = {-1, 0, 1, 0};
ll dy[] = {0, 1, 0, -1};
void dfs(ll x, ll y)
{
    vis[x][y] = 1;
    if (isvalid(x - 1, y))
    {
        dfs(x - 1, y);
    }
    if (isvalid(x, y + 1))
    {
        dfs(x, y + 1);
    }
    if (isvalid(x + 1, y))
    {
        dfs(x + 1, y);
    }
    if (isvalid(x, y - 1))
    {
        dfs(x, y - 1);
    }
    // for (int i = 0; i < 4; i++)
    // {
    //     if (isvalid(x + dx[i], y + dy[i]))
    //     {
    //         dfs(x + dx[i], y + dy[i]);
    //     }
    // }
}
int main()
{
    cin>>n>>m;
    for (int i = 0; i < n ; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> adj[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m ; j++)
        {
            if (vis[i][j] == 0)
            {
                dfs(i, j);
            }
        }
    }
    // dfs(1, 1);
}