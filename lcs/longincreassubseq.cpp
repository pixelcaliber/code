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
    loop(i, 2, sqrt(n)+1){if(n%i==0) return false;} return true;
}
ll power(ll a, ll b, ll m){
  if(b == 0) return 1;
  else if(b%2 == 0) return power((a*a)%m,b/2,m);
  return a*(power((a*a)%m,(b-1)/2,m))%m;
}
void print(vector<ll> &v){
    loop(i, 0, v.size()){cout<<v[i]<<" ";} cout<<endl;
}
//<--------------------------------------------------------------------------------------->
void solve()
{
    cin>>n;
    vll dp;
    for (int i = 0; i < n; ++i)
    {
        ll x; cin>>x;
        auto it = lower_bound(ALL(dp), x); // this is for strictly increasing subseq.. 
                                           // we use upper bound if strictly condt is not there to consider equal elements as well in our subseq.
        if(it == dp.end()){
            dp.pb(x);
        }
        else {
            int j = it - dp.begin();   // replaceing lowerbound value to value smaller than it.. becoz if lowerbound is present that means a value greater or equal must be there in our lis dp array.
            dp[j] = x;
        }
    }
    cout<<dp.size()<<endl;
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