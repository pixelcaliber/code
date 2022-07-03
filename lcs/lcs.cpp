#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ld double
#define vll vector<ll>
#define pb push_back
#define ll long long
// ll static dpp[1002][1002];
// ll lcs_rec(string a, string b, ll n, ll m){

// 	if (n == 0 || m == 0) return 0;
// 	if (dpp[n][m] != -1)
// 	{
// 		return dpp[n][m];
// 	}
// 	if (a[n-1] == b[m-1])
// 	{
// 		return dpp[n][m] = (1 + lcs_rec(a, b, n-1, m-1));
// 	}
// 	return dpp[n][m] = max(lcs_rec(a, b, n, m-1),  lcs_rec(a, b, n-1, m));
// }
ll lcs(string a, string b, ll n, ll m){

	ll dp[n+1][m+1];

	for (int i = 0; i < n+1; ++i)
	{
		dp[i][0] = 0;
	}
	for (int i = 0; i < m+1; ++i)
	{
		dp[0][i] = 0;
	}
	for (int i = 1; i < n+1; ++i)
	{
		for (int j = 1; j < m+1; ++j)
		{
			if (a[i-1] == b[j-1])
			{
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[n][m];
}
void solve()
{
   ll n, m;
   string a, b; cin>>a>>b;

   n = a.length();
   m = b.length();
   // memset(dpp, -1, sizeof(dpp));
  
   cout<<lcs(a, b, n, m);

   // to check if a is subseq of b or not...
   /*
   	  if lcs of a and b is of size a then true a is subseq of b;

		  But, if we are given n and m large i.e 1e5 order then it is diff to create a 2d array
		  so there we need another approach for that.
		  One way is to use 2 pointer method. 

   */

}
int main()
{    
    solve();   
}