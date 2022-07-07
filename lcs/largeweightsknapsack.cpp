#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ld double
#define F first 
#define S second
#define pb push_back
#define ll long long 
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
#define V_SUM_MAX 1000
#define N_MAX 100
#define W_MAX 10000000
 
void solve()
{
    ll n,w;
    cin>>n>>w;

    vll weight(n+1), value(n+1);
    loop(i,0,n)
    cin>>weight[i]>>value[i];

    ll sum_value = 0;
    sum_value = accumulate(ALL(value), 0);
    
    // vll dp(sum_value+1, 1e18L);
    // dp[0] = 0;

    ll dpp[sum_value+1];

    for (int i = 0; i <= sum_value; i++) dpp[i] = 1e18L;
    dpp[0] = 0;
    
    // for(ll item = 0; item < n; item++)
    // {
    //     for(ll j = sum_value; j>=0; j--)
    //     {
    //         dp[j] = min(dp[j], weight[item] + dp[j - value[item]]);
    //     }
    // }
    for(ll i = 1; i <= n; i++)
    {
        for(ll j = sum_value; j >= 1; j--)
        {
            if (j >= value[i-1])
            {
                dpp[j] = min(weight[i-1] + dpp[j - value[i-1]], dpp[j]);
            }
        }
    }
     // return (min_cost[n][W]==INF)? -1: min_cost[n][W];
    ll ans = -1;
    // for(ll i = 0;i < dp.size(); i++)
    // {
    //     if(dp[i] <= w)
    //     ans = max(ans, i);
    // }
    // cout<<ans<<endl;
    // ans = -1;
    for(ll i = 1;i <= sum_value; i++)
    {
        if(dpp[i] <= w)
        {
            ans = max(ans, i);
        }
    }
    cout<<ans<<endl;
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