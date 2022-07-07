#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ld double
#define pb push_back
#define ll long long
#define ALL(x) x.begin(), x.end()
#define ALLR(x) x.rbegin(), x.rend()
#define vin(a) int x; cin>>x; a.pb(x);
#define tests int t; cin>>t; while(t--)
#define bhaag ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1e9 + 7;
int main()
{
   bhaag;
   ll n, k;
   cin>>n>>k;
   ll s[n], a[n];
   bool check[n];
   for (int i = 0; i < n; i++)
   {
      check[i] = true;
   }
   vector<ll>mpp[k+1];
   for (int i = 0; i < n; i++)
   {
      cin>>s[i];
      a[i] = s[i]%k;
      mpp[a[i]].pb(i);
   }
   for (int i = 0; i < n; i++)
   {
      if (check[i])
      {
          ll s1 = mpp[a[i]].size(), temp = mpp[k - a[i]].size();
          ll to_find = k - a[i];
          if (temp>s1) to_find = a[i];
             
          if (to_find == k){
             for (int j = 0; j < mpp[0].size(); j++)
             {
                if (mpp[0][j] != i)
                {
                   check[mpp[0][j]]= false;
                }  
             }
          }
          else {
             for (int j = 0; j < mpp[to_find].size(); j++)
             {
                if (mpp[to_find][j] != i)
                {
                   check[mpp[to_find][j]]= false;
                }                
             }
          }
      }
   }
   ll ans = 0;
   for (int i = 0; i < n; i++)
   {
      if (check[i])
      {
         ans++;
      }
   }
   cout<<ans<<endl;   
}