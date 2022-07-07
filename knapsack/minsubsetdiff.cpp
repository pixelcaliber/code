#include <bits/stdc++.h>
using namespace std;
#define vll vector<ll>
#define ll long long
ll n;
ll knaps_dp(vll wgh, ll w, ll n){
	bool dp[n+2][w+2];

	for (int i = 0; i < n+1; ++i)
	dp[i][0] = true;

	for (int j = 1; j < w+1; ++j)
	dp[0][j] = false;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= w; ++j)
		{
			if (j >= wgh[i-1]){

				dp[i][j] = dp[i-1][j - wgh[i-1]] || dp[i-1][j];
			}
			else{
				dp[i][j] =  dp[i-1][j];
			}
		}
	}
	ll cnt = 0;
	for (int i = 0; i <= w/2; ++i)
	{
		if (dp[n][i])
		{
			cnt = w - 2*i;
		}
	}
   return cnt;
}
int main()
{
	cin>>n;
    vll a;
    ll sum = 0;
    for (int i = 0; i < n; ++i){
    	ll x; cin>>x;
    	a.push_back(x);
    	sum += a[i];
    }

    cout<<knaps_dp(a, sum, n);
}