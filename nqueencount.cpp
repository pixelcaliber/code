#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ld double
#define pb push_back
#define ll long long
#define ALL(x) x.begin(), x.end()
#define ALLR(x) x.rbegin(), x.rend()
#define vin(a) ll x; cin >> x; a.pb(x);
#define tests int t; cin >> t;  while (t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef vector<ll> vll;           typedef map<ll, ll> mll; 
typedef vector<vector<ll>> vvl;   typedef vector<pair<ll, ll>> vpp;
ll n, ans;
vll placed;
void nqueen(ll row){

	if(row == n){
		ans++;
		return;
	}
    for(int col = 0; col < n; col++){

    	bool safe = 1;
    	for(int prow = 0; prow < row; prow++){
    		if(placed[prow] == col || (abs(prow - row) == abs(col-placed[prow])))
    		{
    			safe = 0;
    		}
    	}
    	if(safe){
    		placed.pb(col);
    		nqueen(row+1);
    		placed.pop_back();
    	}
    }

}


void solve()
{
    cin>>n;
    nqueen(0);
    cout<<ans<<endl;
}
int main()
{
fast;
    // tests
    {
        solve();
    }
}