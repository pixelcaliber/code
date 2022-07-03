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
    {cout<<v[i]<<" ";}
    cout<<endl;
}
//<--------------------------------------------------------------------------------------->
void knaps_dp(int &a, int &b){
     
    int dp[a+2][b+2];
    
    for (int i = 0; i <= a; ++i)
        for (int j = 0; j <= b; ++j)
            dp[i][j] = INT32_MAX - 1;
         
    for (int i = 1; i <= a; ++i)
    {
         for (int j = 1; j <= b; ++j)
         {
            if (i == j)
            {
                dp[i][j] = 0;
            }
            else{

                for (int vertcut = 1; vertcut < j; ++vertcut)
                    dp[i][j] = min(dp[i][j], 1 + dp[i][j - vertcut] + dp[i][vertcut]);

                for (int horizcut = 1; horizcut < i; ++horizcut)
                    dp[i][j] = min(dp[i][j], 1 + dp[i - horizcut][j] + dp[horizcut][j]);
            }
         }
    } 
    cout<<dp[a][b]<<endl;
}
void solve()
{
	int a, b; cin>>a>>b;

    knaps_dp(a, b);

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