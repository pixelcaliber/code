#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

using str = string; 
using ll  = long long;
using ld  = long double;
using ull = unsigned ll;

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, 
    rb_tree_tag,
      tree_order_statistics_node_update>;

#define endl        '\n'
#define gcd         __gcd
#define F           first
#define S           second
#define sz(x)       x.size()
#define mp          make_pair
#define pb          emplace_back
#define no          printf("NO\n");
#define yes         printf("YES\n");
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

const ll mod = 1e9 + 7, N = 2e5 + 9;
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
inline void print(vector<ll> &v){
    loop(i, 0, v.size()){cout<<v[i]<<" ";}cout<<endl;
}


vll a[N];
vll vis;
ll in[1000001], low[1000001], timer;
vector<pair<ll, ll>>bridges;
vll dfsarr;
bool dfs_checkforcycle(ll node, ll par_node)
{
    vis[node] = 1;
    dfsarr.push_back(node);
    for (int i = 0; i < a[node].size(); i++)
    {
        if (vis[a[node][i]] == 0)
        {
            if (dfs_checkforcycle(a[node][i], node) == true)
            {
                return true;
            }
        }
        else if (par_node != a[node][i] && vis[a[node][i]] == 1)
        {
            return true;
        }
    }
    return false;
}

void dfs(ll node, ll par){
   
    vis[node] = 1;
    in[node] = low[node] = timer++;
    for (auto &i : a[node])
    {
        if (i == par)
        continue;
        if (vis[i] == 1)
        {
            low[node] = min(low[node], in[i]);
        }
        else{
            dfs(i, node);
            if (low[i] > in[node])
            {
                bridges.push_back({node, i});
            }
            low[node] = min(low[i], low[node]);
        }
    }
    
}
void solve()
{
    cin>>n;
    vpl inp;
    loop(i, 0, n){
        ll x, y;cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
        inp.pb(mp(x, y));
    }
    
    vis.assign(n + 1, 0);
    dfs(1, -1);

    vis.assign(n + 1, 0);
    dfs_checkforcycle(1, -1);

    if (bridges.size() == 0)
    {
        for (int i = 0; i < n; ++i)
        {
            cout<<n*(n - 1)<<" ";
        }
        cout<<endl; return;
    }
    srt(bridges);
    cout<<"DONT";
    // for (int i = 0; i < dfsarr.size(); ++i)
    //     cout<<dfsarr[i]<<" ";
    // cout<<endl;

    // auto it = find(all(a), x); 
    // for(auto it = a[x].begin(); it != a[x].end(); it++){
    //     if(*it == y){
    //         a[x].erase(it);
    //     }
    // }
    // for(auto it = a[y].begin(); it != a[y].end(); it++){
    //     if(*it == x){
    //         a[y].erase(it);
    //     }
    // }

    // for (int i = 0; i < n; ++i)
    // {
    //     ll x = inp[i].F, y = inp[i].S;
    //     pll s = {x, y}, r = {y, x};

    //     if (!binary_search(all(bridges), s) && !binary_search(all(bridges), r));
    //     {

    //     }

        
    // }








}
int main()
{
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