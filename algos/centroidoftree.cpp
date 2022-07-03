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
ll n;
vll Centroid(vll a[]) {

        vll centroid, size(n + 1);
        function<void (ll, ll)> dfs = [&](ll u, ll prev) {
                size[u] = 1;
                bool is_centroid = true;
                for (auto v : a[u]) 
                    if (v != prev) {
                        dfs(v, u);
                        size[u] += size[v];
                        if (size[v] > n / 2) 
                            is_centroid = false;
                    }
                if (n - size[u] > n / 2) 
                    is_centroid = false;
                if (is_centroid) 
                    centroid.push_back(u);
        };
        dfs(1, -1);
        return centroid;
}
int main()
{
    cin>>n;
    vll a[n + 1];
    for (int i = 0; i < n - 1; ++i)
    {
    	ll x, y;cin>>x>>y;
    	a[x].pb(y);
    	a[y].pb(x);
    }
    vll centroids = Centroid(a);
}