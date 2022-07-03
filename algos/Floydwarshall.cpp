#include <bits/stdc++.h>
using namespace std;
#define endl        '\n'
#define F           first
#define S           second
#define ld          double
#define sz(x)       x.size()
#define ll          long long
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define maxe(a)     max_element(all(a))
#define mine(a)     min_element(all(a))
#define vin(a)      ll x; cin >> x; a.pb(x);
#define loop(i,x,y) for(int i = x; i < y; i++)

typedef vector<ll> vll;           typedef map<ll, ll> mapl;
typedef vector<pair<ll, ll>> vpl;

const ll mod = 1e9 + 7, N = 2e5 + 2;
#define allr(x)     x.rbegin(), x.rend()

int main()
{
	int m;
    ll n;cin>>n>>m;
    ll dist[n + 1][n + 1];
    for (int i = 0; i < n + 1; ++i)
    {
    	for (int j = 0; j < n + 1; ++j)
    	{
    		dist[i][j] = 1e18;
    	}
    	dist[i][i] = 0;
    }
    for (int i = 0; i < m; ++i)
    {
    	ll x, y, w;cin>>x>>y>>w;
    	dist[x][y] = w;
    }
    for (int k = 1; k <= n; ++k)
    {
    	for (int i = 1; i <= n; ++i)
    	{
    		for (int j = 1; j <= n; ++j)
    		{
    			dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    		}
    	}
    }


}