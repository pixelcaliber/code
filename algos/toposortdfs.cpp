#include<bits/stdc++.h>
#define ll long long 
using namespace std;
stack<ll>topo_sort;
void dfs(vector<ll>a[], ll node, ll vis[]){

    vis[node] = 1;
    for (int i = 0; i < a[node].size(); i++)
    {
        if(vis[a[node][i]] == 0)
        {
            dfs(a, a[node][i], vis);
            // topo_sort.push(a[node][i]);// ....(1)  yato 1 aur 2 ko simul
        }
    }
        topo_sort.push(node);    //ya to isko kre akele..
}
int main(){
    ll n, m; cin>>n>>m;//1 3 
    vector<ll>a[n+1];
    for (int i = 0; i < m; i++)
    {
        ll x, y; cin>>x>>y;
        a[x].push_back(y);
    }
    ll vis[n+1] = {0};
    for (int i = 1; i < n+1; i++)
    {
        if (vis[i] == 0)
        {
            dfs(a, i, vis);
            // topo_sort.push(i); //....(2)  yato 1 aur 2 ko simul.
        }        
    }
    while (topo_sort.size()>0)
    {
       cout<<topo_sort.top();
       topo_sort.pop();
    } 
}