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
bool prime(ll n){
    loop(i, 2, sqrt(n)+1){if(n%i==0)return false;}
    return true;
}
ll power(ll a, ll b, ll m){
  if(b == 0) return 1;
  else if(b%2 == 0) return power((a*a)%m,b/2,m);
  return a*(power((a*a)%m,(b-1)/2,m))%m;
}
inline void print(vector<ll> &v){
    loop(i, 0, v.size()){cout<<v[i]<<" ";}cout<<endl;
}
//<--------------------------------------------------------------------------------------->
int lcs_eff(string &X, string &Y, int m, int n)
{
      
    int dp[2][n + 1];
    bool ind;
 
    for (int i = 0; i <= m; i++)
    {
        if(i%2 == 0) ind = 0;
        else ind = 1;
 
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[ind][j] = 0;
 
            else if (X[i-1] == Y[j-1])
                 dp[ind][j] = dp[1 - ind][j - 1] + 1;
 
            else
                dp[ind][j] = max(dp[1 - ind][j],
                               dp[ind][j - 1]);
        }
    }
 
    return dp[ind][n];
}
int lcs(string a, string b, int n, int m){

	int dp[n+1][m+1];

	for (int i = 0; i < n+1; ++i)
	{
		dp[i][0] = 0;
	}
	for (int i = 0; i < m+1; ++i)
	{
		dp[0][i] = 0;
	}
	for (int i = 1; i < n+1; ++i)
	{
		for (int j = 1; j < m+1; ++j)
		{
			if (a[i-1] == b[j-1])
			{
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[n][m];
}
void solve()
{
    string s;
    cin>>s;
    int n = s.length(), i = 0, k = 1;
    
    vector<string>div;

    while(i<1000){

    	div.push_back(to_string(i));
    	i = (k++)*8;
    }
    for (int i = 0; i < div.size(); ++i)
    {
    	int m = div[i].length();

    	if (lcs_eff(s, div[i], n, m) == div[i].length())
    	{
    		cout<<"YES\n"; 
    		cout<<div[i]<<endl;
    		return;
    	}
    }


    cout<<"NO\n";

}
int main()
{
    fastio;
    int cases = 1;
    tests
    {
        //cout<<"Case #"<<cases++<<": ";
        solve();
    }
}
//D:\cfcontests\