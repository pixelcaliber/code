#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ld double
#define ll long long
ll coinChange(vector<ll>& coins, ll amt) {
        ll n = coins.size();
        ll dp[amt+1];        
        for (int j = 0; j < amt+1; j++)
        dp[j] = amt+1;

        dp[0] = 0;
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<amt+1; j++){
                if(j>=coins[i-1]){
                    dp[j] = min(1+dp[j - coins[i-1]], dp[j]);
                }
            }
        }
    return dp[amt]==amt+1?-1:dp[amt];
}