#include<bits/stdc++.h>
using namespace std;
#define ll long long
int adj[1000][1000];
int main(){
    // adj matrix..
    ll n,m;cin>>n>>m;
    // for (int i = 0; i < m; i++)
    // {
    //     ll x,y;cin>>x>>y;
    //     adj[x][y] = 1;
    //     adj[y][x] = 1;
    // }
    // for (int i = 1; i < n+1; i++)
    // {
    //     for (int j = 1; j < n+1; j++)
    //     {
    //         cout<<adj[i][j]<<" ";
    //     }
    //       cout<<endl;
    // }
    // adj list..
    vector<int> a[n+1]; 
	 
	for(int i = 0;i<m;i++) {
	    ll u, v; 
	    cin >> u >> v;
	    a[u].push_back(v); 
	    a[v].push_back(u); 
	}
    for (int i = 0; i < m; i++)
    {
     //     cout<<i<<" ";
        for (int j = 0; j < a[i].size(); j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    } 
     
return 0;
}