#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, 
    rb_tree_tag,
      tree_order_statistics_node_update>;

#define endl        '\n'
#define gcd         __gcd
#define F           first
#define S           second
#define ld          double
#define sz(x)       x.size()
#define mp          make_pair
#define ll          long long
#define pb          emplace_back
#define no          printf("NO\n");
#define yes         printf("YES\n");
#define ull         unsigned long long
#define all(x)      x.begin(), x.end()
#define maxe(a)     max_element(all(a))
#define mine(a)     min_element(all(a))
#define allr(x)     x.rbegin(), x.rend()
#define vin(a)      ll x; cin >> x; a.pb(x);
#define tests       int t; cin >> t;  while (t--)
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);
#define loop(i,x,y) for(int i = x; i < y; i++)

mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count()); 
#define SHUF(v) shuffle(aint(v), RNG);
// Use mt19937_64 for 64 bit random numbers.

typedef vector<ll> vll;           typedef map<ll, ll> mapl;
typedef pair<ll, ll>vpp;          typedef set<ll> sll;
typedef vector<vector<ll>> vvl;   typedef vector<pair<ll, ll>> vpl;

const ll mod = 1e9 + 7, N = 2e5 + 9;
const ll inf = INT64_MAX, ninf = INT64_MIN;

ll n;
bool prime(ll n){
    loop(i, 2, sqrt(n)+1){if(n%i==0) return false;}
    return true;
}
ll binomialCoeff(ll n, ll k){
    ll res = 1; if (k>n-k) k = n-k;
    for (int i = 1; i <= k; i++)
       res = (res * (n-i+1)), res /= i;
    return res;
}
ll lcm(ll a, ll b){
    return (a * (b / gcd(a, b)));
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
void solve()
{
    cin>>n;
    string s, rev; 
    cin>>s;
    string ans = "";

    ans += s[0];

    for (int i = 1; i < n; ++i)
    {
        if (s[i] > s[i-1])
        {
            break;
        }
        else ans += s[i];
    }

    rev = ans;   
    reverse(all(rev));
    ans += rev;

    rev = "";
    rev += s[0];
    rev += s[0];

    if (rev < ans)
    {
        cout<<rev<<endl;
    }
    else 
        cout<<ans<<endl;
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
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}