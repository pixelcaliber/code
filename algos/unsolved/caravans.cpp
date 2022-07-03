#include <bits/stdc++.h>
using namespace std;
#define endl        '\n'
#define F           first
#define S           second
#define ld          double
#define sz(x)       x.size()
#define ll          int
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define maxe(a)     max_element(all(a))
#define mine(a)     min_element(all(a))
#define vin(a)      ll x; cin >> x; a.pb(x);
#define loop(i,x,y) for(int i = x; i < y; i++)

typedef vector<ll> vll;           typedef map<ll, ll> mapl;
typedef pair<ll, ll>pll;          typedef set<ll> sll;
typedef vector<bool>vb;           typedef vector<string> vs;
typedef vector<vector<ll>> vvl;   typedef vector<pair<ll, ll>> vpl;

void find_paths(vector<vector<ll> >& paths, vector<ll>& path, vector<ll> parent[], ll u){

    if (u == -1) {
        paths.push_back(path);
        return;
    }
    for (int par : parent[u]) {

        path.push_back(u);
 
        find_paths(paths, path, parent, par);
 
        path.pop_back();
    }
}
void bfs(vector<ll>a[], vector<ll>parent[], ll source, vll &d){

	queue<ll>q;

	q.push(source);
	d[source] = 0;
	parent[source] = {-1};

	while(q.size() > 0){

		ll u = q.front();
		q.pop();
		for (ll v : a[u]) {
            if (d[v] > d[u] + 1) {

                d[v] = d[u] + 1;
                q.push(v);
                parent[v].clear();
                parent[v].push_back(u);
            }
            else if (d[v] == d[u] + 1) {

                parent[v].push_back(u);
            }
        }
	}

}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    // int t; cin >> t;  while (t--)
    {
        ll n;
        ll m;
	    cin>>n>>m;

	    vector<ll>a[n + 1], parent[n + 1];
	    vvl paths;
	    vll path;

	    for (int i = 0; i < m; ++i)
	    {
	    	ll x, y;cin>>x>>y;
	    	a[x].pb(y);
	    	a[y].pb(x);
	    }
	    ll s, f, r; cin>>s>>f>>r;

	    vll dc(n + 1, INT_MAX), d(n + 1, INT_MAX);

	    bfs(a, parent, s, d);

	    find_paths(paths, path, parent, f);

	    ll ans = 0;

	    bfs(a, parent, r, dc);

	    for (int i = 0; i < paths.size(); ++i)
	    {
	    	ll val = INT_MAX;
	   		for (auto j: paths[i])
	   		{
	   			val = min(val, dc[j]);
	   		}
	   		ans = max(ans, val);
	    }

	    cout<<ans;

    }
}