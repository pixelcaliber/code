#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
/*
*  Using Automatic Vectorization - Intel
*/
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else 
#define debug(x)
#endif

using str = string; 
using ll  = long long;
using ld  = long double;
using ull = unsigned ll;

#define endl        '\n'
#define gcd         __gcd
#define F           first
#define S           second
#define sz(x)       x.size()
#define mp          make_pair
#define pb          push_back
#define no          cout<<"NO\n"
#define yes         cout<<"YES\n"
#define each(a,x)   for (auto& a: x)
#define all(x)      x.begin(), x.end()
#define maxe(a)     max_element(all(a))
#define mine(a)     min_element(all(a))
#define allr(x)     x.rbegin(), x.rend()
#define vin(a)      ll x; cin >> x; a.pb(x);
#define srt(x)      sort(x.begin(), x.end());
#define rev(x)      reverse(x.begin(), x.end());
#define tests       int t; cin >> t;  while (t--)
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);
#define loop(i,x,y) for(int i = x; i < y; i++)

mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count()); 
#define SHUF(v) shuffle(aint(v), RNG);
// Use mt19937_64 for 64 bit random numbers.

typedef vector<ll> vll;           typedef map<ll, ll> mapl;
typedef pair<ll, ll>pll;          typedef set<ll> sll;
typedef vector<bool>vb;           typedef vector<string> vs;
typedef vector<vector<ll>> vvl;   typedef vector<pair<ll, ll>> vpl;

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, 
    rb_tree_tag,
      tree_order_statistics_node_update>;
template<class T> void print(vector<T> v){ 
      for(int i=0;i<v.size();i++) cout<<v[i]<<" "; cout << "\n";}

const ll mod = 1e9 + 7, N = 2e5 + 9, mod2 = 998244353;
const ll inf = INT64_MAX, ninf = INT64_MIN;
ll fact[N];

ll n;
bool prime(ll n){
    loop(i, 2, sqrt(n)+1){if(n%i==0) return false;}
    return true;
}
ll power(ll a, ll b, ll m){
    if(b == 0) return 1;
    else if(b%2 == 0) return power((a*a)%m,b/2,m);
    return a*(power((a*a)%m,(b-1)/2,m))%m;
}
ll binomialCoeff(ll n, ll k){
    ll res = 1; if (k>n-k) k = n-k;
    for (int i = 1; i <= k; i++)
       res = (res * (n-i+1)), res /= i;
    return res;
}
ll nCk(ll n, ll k){
    ll res = 1;
    res = fact[n]; res = (res%mod * (power(fact[n-k], mod-2, mod))%mod)%mod;
    res = (res%mod * (power(fact[k], mod-2, mod))%mod)%mod;
    return res;
}
str decimalToBinary(ll n){
    str s = bitset<64> (n).to_string();
    if(s.find('1') != string::npos) return s.substr(s.find('1')); return "0";
}
int topbit(ll t){
    return t==0?-1:63-__builtin_clzll(t);
}
int botbit(ll a){
    return a==0?64:__builtin_ctzll(a);
}
int popcount(ll t){
    return __builtin_popcountll(t);
}
bool ispow2(ll i){
    return i&&(i&-i)==i;
}
ll mask(ll i){
    return (ll(1)<<i)-1;
}
ll lcm(ll a, ll b){
    return (a * (b / gcd(a, b)));
}
//void dfs(ll s){
//    vis[s]=1;
//    for(auto &i: graph[s]){
//       if(!vis[i])
//         dfs(i);
//    }
//}

vll parent, grpsize;
multiset<ll>szeAt_each_union;

void make(ll x){
	parent[x] = x;
	grpsize[x] = 1;
	szeAt_each_union.insert(1);
}

ll findparent(ll x){
	if(parent[x] == x) return x;
	return parent[x] = findparent(parent[x]);
}
void merge(ll a, ll b){

	szeAt_each_union.erase(szeAt_each_union.find(grpsize[a]));
	szeAt_each_union.erase(szeAt_each_union.find(grpsize[b]));

	szeAt_each_union.insert(grpsize[a] + grpsize[b]);

}
void unions(ll a, ll b){
	a = findparent(a), b = findparent(b);
	if (a != b)
	{
		if (grpsize[a] < grpsize[b])
		{
			swap(a, b);
		}
		parent[b] = a;
		merge(a, b);
		grpsize[a] += grpsize[b];
	}
}
void solve()
{
    cin>>n;

    for (int i = 0; i < n; ++i)
    {
    	ll a, b;cin>>a>>b;
    	unions(a, b);

    }


}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("Error.in", "w", stderr);
#endif
    fastio;
    int cases = 1;

    //fact[0] = fact[1] = 1;
    //loop(i, 2, N){
      // fact[i] = (fact[i - 1]%mod * i%mod)%mod;
    //}

    // tests
    {
        //cout<<"Case #"<<cases++<<": ";
        solve();

    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
//D:\cfcontests\