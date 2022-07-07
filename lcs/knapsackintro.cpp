#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ld double
#define ll long long
ll dp[1000+1][100+1];
ll knp_memoized(ll wgh[], ll val[], ll w, ll n){

	if(n == 0 || w == 0){
		return 0;
	}
	if (dp[n][w] != -1) 
	{
		return dp[n][w];
	}
	if(w >= wgh[n-1]){
		return dp[n][w] = max(val[n-1] + knp_memoized(wgh, val, w - wgh[n-1], n-1), knp_memoized(wgh, val, w, n-1));
	}
	
	return dp[n][w] = knp_memoized(wgh, val, w, n-1);	
  
}
ll knaps_dp(ll wgh[], ll val[], ll w, ll n){

	for (int i = 0; i < n+1; ++i)
	{
		for (int j = 0; j < w+1; ++j)
		{
			if (i == 0 || j == 0){
				dp[i][j] = 0;
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= w; ++j)
		{
			if (j >= wgh[i-1]){

				dp[i][j] = max(val[i-1] + dp[i-1][j - wgh[i-1]], dp[i-1][j]);
			}
			else{
				dp[i][j] =  dp[i-1][j];
			}
		}
	}
	return dp[n][w];
}
void solve()
{
	ll n;
    cin>>n;
    // for (int i = 0; i < n+1; ++i)   //for knp_memoized we initialize every elem as -1;
    // {
    // 	for (int j = 0; j < n+1; j++){
    // 		dp[i][j] = -1;
    // 	}
    // }
    // call recursive knp_memoized(weight, value, W, n);

    knaps_dp()

}
int main()
{
    solve();
}