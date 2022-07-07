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
#define tests       int t; cin >> t;  while (t--)
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);
#define loop(i,x,y) for(int i = x; i < y; i++)

mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count()); 
#define SHUF(v) shuffle(aint(v), RNG);
// Use mt19937_64 for 64 bit random numbers.

typedef vector<int> vll;           typedef map<ll, ll> mapl;
typedef pair<ll, ll>pll;          typedef set<ll> sll;
typedef vector<bool>vb;           typedef vector<string> vs;
typedef vector<vector<ll>> vvl;   typedef vector<pair<ll, ll>> vpl;

const ll mod = 1e9 + 7, N = 1e6 + 1, K = 27;
const ll inf = INT64_MAX, ninf = INT64_MIN;

int n;
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
str decimalToBinary(ll n){
    str s = bitset<64> (n).to_string();
    if(s.find('1') != string::npos) return s.substr(s.find('1')); return "0";
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
int table[N + 1][K + 1];
int binary_log[N + 1];
void precompute_logs(){
	 binary_log[1] = 0;
	 for (int i = 2; i < n + 1; ++i)
		binary_log[i] = binary_log[i / 2] + 1;
}
void sparseTable(int a[], int n){

	for (int i = 0; i < n; ++i)
		table[i][0] = a[i];

	for (int j = 1; j <= K; ++j)
		for(int i = 0; i + (1LL << j) <= n; i++)
			table[i][j] = min(table[i][j - 1], table[i + (1LL << (j - 1))][j - 1]);
}
void solve()
{
    str s;cin>>s; n = s.length();
	precompute_logs();
    
    int prefix[n + 1];
    prefix[0] = 0;

    map<int, vll>f;			//map to store values of indexes having indentical prefix sums.
    f[0].pb(0);
    
    for (int i = 1; i <= n; ++i)
    {
    	if(s[i - 1] == '(')
			prefix[i] = prefix[i - 1] + 1;
		else
			prefix[i] = prefix[i - 1] - 1;

		f[prefix[i]].pb(i); 
    }

    sparseTable(prefix, n + 1);
    int lenMax = -1;
    map<int, int> ans, vis;
    for (int i = 0; i < n + 1; ++i)
    {
    	int valAti = prefix[i], len = 0;
    	
    	if (vis[valAti] > i)
    		continue;

    	if (f[prefix[i]].size() <= 1)
    		continue;
    	
    	int lowerIndex = vis[valAti];

    	if (lowerIndex == f[prefix[i]].size())
    		continue;

    	vll tobeSearch = f[prefix[i]];

    	int low = lowerIndex, high = tobeSearch.size() - 1;
    	while (high >= low){

    		int mid = low + (high - low)/2;
    		int L = tobeSearch[lowerIndex], R = tobeSearch[mid];
    		
    		int length = binary_log[R - L + 1];
			int minimum = min(table[L][length], table[R - (1 << length) + 1][length]);
			if (minimum >= valAti)
			{
				len = max(len, tobeSearch[mid] - tobeSearch[lowerIndex]);
				vis[valAti] = max(mid + 1, vis[valAti]);
				low = mid + 1;
			}
			else high = mid - 1;
    	}

    	if(lenMax <= len){
			lenMax = len;
			ans[lenMax]++;
		}
    }

    (lenMax <= 0) ? (cout<<"0 1\n") : (cout<<lenMax<<" "<<ans[lenMax]);

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
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
//D:\cfcontests\