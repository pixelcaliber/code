#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ld double
#define vll vector<ll>
#define pb push_back
#define ll long long
ll lcs(string a, string b, ll n, ll m){

	ll dp[n+1][m+1], ans = -1;

	for (int i = 0; i < n+1; ++i)	
	dp[i][0] = 0;
	
	for (int i = 0; i < m+1; ++i)	
	dp[0][i] = 0;
	
	for (int i = 1; i < n+1; ++i)
	{
		for (int j = 1; j < m+1; ++j)
		{
			if (a[i-1] == b[j-1])
			{
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = 0;
			}
			ans = max(ans, dp[i][j]);
		}
	}

	return ans;
}
int lcs_fast(string s, string t, int n, int m)
{
    int dp[2][m + 1];

    memset(dp , 0, sizeof(dp));
    
    int res = 0;
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
                if (dp[i % 2][j] > res)
                    res = dp[i % 2][j];
            }
            else
                dp[i % 2][j] = 0;
        }
    }
    return res;
}
void solve()
{
   ll n, m;
   string a, b; cin>>a>>b;

   n = a.length();
   m = b.length();
   // memset(dpp, -1, sizeof(dpp));
  
   cout<<lcs(a, b, n, m);

}
int main()
{    
    solve();   
}