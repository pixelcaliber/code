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
ll n, maxSum;
vll arr;
void calculateSubSet(vll &x, ll s, ll size){

	for (int ind = 0; ind < (1<<size); ++ind)
	{
		ll sum = 0;
		for (int j = 0; j < size; ++j)
		{
			if (ind & (1<<j))
			{
				sum += arr[j+s];
			}
		}
		x.pb(sum);
		// cout<<sum<<endl;
	}
}
ll calcMaxSum(vll x, vll y){
	sort(ALL(y));
	ll ans = -1;
	for (int i = 0; i < x.size(); ++i)
	{
		if (x[i]<=maxSum)
		{
			ll no = lower_bound(ALL(y), maxSum - x[i]) - y.begin();

			if (no == y.size() || y[no] != maxSum - x[i])
			{
				no--;
			}
			ans = max(ans, y[no] + x[i]);
		}
	}
	return ans;
}
void solve()
{
    cin>>n>>maxSum;
    // we have n <= 40 elements and we want to find max sum of subset poss such that it is less than 
    //or equal to a given sum S.
    vll x, y;
    for (int i = 0; i < n; ++i)
    {
    	vin(arr);
    }
    calculateSubSet(x, 0, n/2);
    calculateSubSet(y, n/2, n-n/2);
    cout<<calcMaxSum(x, y)<<endl;

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