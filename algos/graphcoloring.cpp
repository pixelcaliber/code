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
vector<int>a[N], vis, col;

void dfs(int s, int c){
	vis[s] = 1;
	col[s] = c;
	for(auto &i:a[s]){
		if(!vis[i]){
			dfs(i, ((c == 0) ? 1 : 0));
		}
		else if() {

		}
	}
}
int main()
{
    int n, m;cin>>n>>m;

    for (int i = 0; i < m; ++i)
    {
    	int x, y;cin>>x>>y;
    	a[x].push_back(y);
    	a[y].push_back(x);
    }

    for (int i = 0; i < n; ++i)
    {
    	if(!vis[i]){
    		dfs(i, c);
    	}
    }



}