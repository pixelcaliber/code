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
	return n + m - dp[n][m];
}
string print_scs(string a, string b, ll n, ll m){

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
	string ans = "";
	int i = n, j = m;
	while (i>0 && j>0){
		if (a[i-1] == b[j-1])
		{
			ans += a[i-1];
		  	i--; j--;			
		}
		else {
			if (dp[i-1][j] > dp[i][j-1]){
				ans += a[i-1]; i--;
			}
			else{
				ans += b[j-1]; j--;
			}
		}
	}
		
	while(i>0){
		ans += a[i-1];
		i--;
	}
	while(j>0){
		ans += a[j-1];
		j--;
	}
	reverse(ans.begin(), ans.end());

	return ans;
}

void solve()
{
   ll n, m;
   string a, b; cin>>a>>b;

   n = a.length();
   m = b.length();
  
   cout<<lcs(a, b, n, m)<<endl;
   cout<<print_scs(a, b, n, m);

}
int main()
{    
    solve();   
}