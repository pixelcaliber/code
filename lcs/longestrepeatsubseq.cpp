#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ld double
#define vll vector<ll>
#define pb push_back
#define ll long long
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
		  for (int j = 1; j <= m; ++j)
		  {
		  	    if (a[i-1] == b[j-1] && (i != j)) // < or !=
		  	    {
		  	    	  dp[i][j] = 1 + dp[i-1][j-1];		  	    	  
		  	    }
		  	    else{

		  	    	  dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		  	    }
		  }
	}
   return dp[n][m];
}
void solve()
{
   ll n, m;
   string a, b; cin>>a;
   b = a;
   n = a.length();
   m = b.length();
  
   cout<<lcs(a, b, n, m)<<endl;

}
int main()
{    
    solve();   
}