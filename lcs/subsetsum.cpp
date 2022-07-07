#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ld double
#define ll long long
bool dp[1000+1][1000+1];
bool knaps_dp(ll wgh[], ll w, ll n){

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
	return dp[n][w];

	//faster version...
	/*
		int dp[w+1];
		memset(dp, 0, sizeof(dp));

		dp[0] = 1;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = w; j >= 1; j--)
		{
			if(j - wgh[i-1] >= 0)
			dp[j] = dp[j] || dp[j - wgh[i-1]];
		}
	}
	
	*/
}
void solve()
{
	ll n;
    cin>>n;
   	ll a[n+1];
   	for (int i = 0; i < n; ++i)
   	{
   		cin>>a[i];
   	}
   	ll sum; cin>>sum;
    cout<<knaps_dp(a, sum, n);

}
int main()
{
    solve();
}