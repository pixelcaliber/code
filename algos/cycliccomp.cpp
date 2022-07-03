#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ld double
#define pb push_back
#define ll long long
#define ALL(x) x.begin(), x.end()
#define ALLR(x) x.rbegin(), x.rend()
#define vin(a) ll x; cin >> x; a.pb(x);
#define tests int t; cin >> t;  while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef vector<ll> vll;           typedef map<ll, ll> mll; 
typedef vector<vector<ll>> vvl;   typedef vector<pair<ll, ll>> vpp;
ll n, m, f;
bool prime(int n){
    for(int i=2;i<=int(ceil(sqrt(n)));i++){

        if(n%i==0)
        
        return false;
    }
    return true;
}
void print(vector<ll> &v){

    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    cout<<endl;
}
void dfs(vector<ll> a[], ll source, ll vis[]){

	vis[source] = 1;

	if (a[source].size() != 2)
	{
		f = 0;
	}
	for(auto &&i: a[source]){

		if (!vis[i])
		{
			(dfs(a, i, vis));		
		}
	}
}
void solve()
{
    cin>>n>>m;
    vll a[n+1];
    for (int i = 0; i < m; ++i)
    {
    	ll x, y;  cin>>x>>y;
    	a[x].pb(y); a[y].pb(x);
    }

    ll vis[n+1] = {0}, cnt = 0;

    for (int i = 1; i <= n; ++i)
    {
    	if(!vis[i]){
    		f = 1;
			dfs(a, i, vis);
			cnt += f;
    	}
    }

   cout<<cnt<<endl;
}
int main()
{
fast;
    // tests
    {
        solve();
    }
}