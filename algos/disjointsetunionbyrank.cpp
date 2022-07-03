#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll parent[100000];
ll rankk[100000];
void makeSet(ll n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
}
ll findPar(ll node)
{
    if (parent[node] == node)
    {
        return node;
    }
    return parent[node] = findPar(parent[node]);
}
void union_set(ll u, ll v)
{
    u = findPar(u);
    v = findPar(v);
    if (rankk[u] > rankk[v])
    {
        parent[v] = u;
    }
    else if (rankk[u] < rankk[v])
    {
        parent[u] = v;
    }
    else
    {
        parent[u] = v;
        rankk[v]++;
    }
}
int main()
{
    int m, n;
    cin>>n;
    cin >> m;
    makeSet(n);
    while (m--)
    {
        ll u, v;
        cin >> u >> v;
        union_set(u, v);
    }
    if (findPar(1) == findPar(2))
    {
        cout << "same" << endl;
    }
    else
        cout << "not same" << endl;
}