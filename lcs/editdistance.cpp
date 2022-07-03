#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
#define endl '\n'
#define ld double
#define ll long long
#define pb emplace_back
#define mp make_pair
#define ull unsigned long long
#define ALL(x) x.begin(), x.end()
#define maxe(a) max_element(ALL(a))
#define mine(a) min_element(ALL(a))
#define ALLR(x) x.rbegin(), x.rend()
#define vin(a) ll x; cin >> x; a.pb(x);
#define tests int t; cin >> t;  while (t--)
#define loop(i, x, y) for(int i = x; i < y; i++)
typedef vector<ll> vll;           typedef map<ll, ll> mapl; 
typedef vector<vector<ll>> vvl;   typedef vector<pair<ll, ll>> vpl;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const ll mod = 1e9 + 7, SZ = 4e5 + 4;
ll n;
bool prime(ll n){
    loop(i, 2, sqrt(n)+1){
        if(n%i==0)        
        return false;
    }
    return true;
}
ll power(ll a, ll b, ll m){
  if(b == 0) return 1;
  else if(b%2 == 0)
      return power((a*a)%m,b/2,m);
  return a*(power((a*a)%m,(b-1)/2,m))%m;
}
void print(vector<ll> &v){
    loop(i, 0, v.size())
    {cout<<i<<" ";}
    cout<<endl;
}
//<--------------------------------------------------------------------------------------->
void knaps_dp(string &s, string &p, int &n, int &m){

	int dp[n+2][m+2];

	loop(i, 0, n+1)
	{
		loop(j, 0, m+1)
		dp[i][j] = INT32_MAX - 4;
	}
	dp[0][0] = 0;
	
	for (int i = 0; i <= n; i++) {
   	
   	 for (int j = 0; j <= m; j++) {
	
	    if(s[i-1] == p[j-1] && i && j)
	    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
	    
	    else if(i && j)
		dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1);

		if(i)
		dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
	      
	    if(j)
		dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
	 }
  }
	cout<<dp[n][m]<<endl;
}
void solve()
{
    string s, p;
    cin>>s>>p;
    int n = s.length(), m = p.length();
    knaps_dp(s, p, n, m);
}
int main()
{
    fastio;
    int cases = 1;
    // tests
    {
        //cout<<"Case #"<<cases++<<": ";
        solve();
    }
}