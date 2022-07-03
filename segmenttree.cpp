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
struct segtree
{
    int size;
    // vector<ll>sums;
    vector<ll> mins, maxs;

    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        // sums.assign(2 * size + 1, 0LL);
        mins.assign(2 * size + 1, inf);
        maxs.assign(2 * size + 1, ninf);
    }

    void build(vector<ll>&a, int x, int lx, int rx){
        if(rx - lx == 1) {
            if(lx < (int)a.size()){
                // sums[x] = a[lx];
                mins[x] = a[lx];
                maxs[x] = a[lx];
            }
            return;
        }
        int mid = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, mid);
        build(a, 2 * x + 2, mid, rx);

        // sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
        mins[x] = min({mins[2 * x + 1], mins[2 * x + 2]});
        maxs[x] = min({maxs[2 * x + 1], maxs[2 * x + 2]});
    }
    void build(vector<ll>&a){
        build(a, 0, 0, size);
    }
    // void set(int i, int v, int x, int lx, int rx){
    //  if(rx - lx == 1){
    //      sums[x] = v;
    //      return;
    //  }
    //  int mid = (lx + rx) / 2;
    //  if (i < mid)
    //  {
    //      set(i, v, 2 * x + 1, lx, mid);
    //  }
    //  else{
    //      set(i, v, 2 * x + 2, mid, rx);
    //  }
    //  sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    // }
    // void set(int i, int v){
    //  set(i, v, 0, 0, size);
    // }
    void setmin(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1){
            mins[x] = v;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid)
        {
            setmin(i, v, 2 * x + 1, lx, mid);
        }
        else{
            setmin(i, v, 2 * x + 2, mid, rx);
        }
        mins[x] = min({mins[2 * x + 1], mins[2 * x + 2]});
    }
    void setmin(int i, int v){
        setmin(i, v, 0, 0, size);
    }
    void setmax(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1){
            maxs[x] = v;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid)
        {
            setmax(i, v, 2 * x + 1, lx, mid);
        }
        else{
            setmax(i, v, 2 * x + 2, mid, rx);
        }
        maxs[x] = min({maxs[2 * x + 1], maxs[2 * x + 2]});
    }
    void setmax(int i, int v){
        setmax(i, v, 0, 0, size);
    }
    // long long sum(int l, int r, int x, int lx, int rx){

    //  if(lx >= r or l >= rx) return 0;
    //  if(lx >= l and rx <= r) return sums[x];

    //  ll mid = (lx + rx) / 2;
    //  return sum(l, r, 2 * x + 1, lx, mid) + sum(l, r, 2 * x + 2, mid, rx);

    // }
    // long long sum(int l, int r){
    //  return sum(l, r, 0, 0, size);
    // }
    
    long long getmin(int l, int r, int x, int lx, int rx){

        if(lx >= r or l >= rx) return inf;
        if(lx >= l and rx <= r) return mins[x];

        ll mid = (lx + rx) / 2;
        return min(getmin(l, r, 2 * x + 1, lx, mid), getmin(l, r, 2 * x + 2, mid, rx));
    }
    long long getmin(int l, int r){
        return getmin(l, r, 0, 0, size);
    }
    long long getmax(int l, int r, int x, int lx, int rx){

        if(lx >= r or l >= rx) return ninf;
        if(lx >= l and rx <= r) return maxs[x];

        ll mid = (lx + rx) / 2;
        return min(getmax(l, r, 2 * x + 1, lx, mid), getmax(l, r, 2 * x + 2, mid, rx));
    }
    long long getmax(int l, int r){
        return getmax(l, r, 0, 0, size);
    }

};


//void dfs(ll v){
//    vis[v] = 1;
//    for(auto &i: graph[v]){
//        if(!vis[i])
//        {
//           dfs(i);
//        }
//    }
//}


void solve()
{
    cin>>n;

    vll a;
    loop(i, 0, n){
    	vin(a);
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

    tests
    {
        //cout<<"Case #"<<cases++<<": ";
        solve();

    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
//D:\cfcontests\