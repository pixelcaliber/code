#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ld double
#define F first 
#define S second
#define pb push_back
#define ll int 
#define ull unsigned long long
#define em emplace_back
#define makep make_pair
#define mine(a) min_element(ALL(a))
#define maxe(a) max_element(ALL(a))
#define ALL(x) x.begin(), x.end()
#define ALLR(x) x.rbegin(), x.rend()
#define case(cases) cout<<"Case #"<<cases++<<": ";
#define vin(a) ll x; cin >> x; a.pb(x);
#define tests int t; cin >> t;  while (t--)
#define forr(i, a) (auto &i: a)
#define loop(i, x, y) for(int i = x; i < y; i++) 
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef vector<ll> vll;           typedef map<ll, ll> mapl; 
typedef vector<vector<ll>> vvl;   typedef vector<pair<ll, ll>> vpl;
const ll mod = 1e9 + 7;
bool prime(ll n){
    for(int i=2;i<=sqrt(n);i++){

        if(n%i==0)
        
        return false;
    }
    return true;
}
ll powertofind(ll a, ll b, ll m){

  if(b == 0) return 1;

  else if(b%2 == 0){
      return powertofind((a*a)%m,b/2,m);
  }
   return a*(powertofind((a*a)%m,(b-1)/2,m))%m;
}
void print(vector<ll> &v){

    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    cout<<endl;
}
ll knaps_dp(vll wgh, vll val, ll w, ll n){

	ll dp[w+2];
	memset(dp, 0, sizeof(dp));

	for (int i = 0; i < n; ++i)
	{
		for(int j = w; j >=wgh[i]; j--)

            dp[j] = max(dp[j] , val[i] + dp[j-wgh[i]]);
	}
	return dp[w];
}
void solve()
{
    ll n, x; cin>>n>>x;
    // cin>>n;
    vll a, b;
    for (int i = 0; i < n; ++i)
    {
    	int x, y; cin>>x>>y;
    	a.pb(x);
    	b.pb(y);
    }
   
    cout<<knaps_dp(a, b, x, n);
}
int main()
{
fastio;
    int cases = 1;
    // tests
    {

        solve();
    }
}