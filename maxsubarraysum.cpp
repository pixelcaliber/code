#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define bhaag ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ld double
int main(){
    bhaag;
    int t;cin>>t;
    while (t--)
    {
      ll n, m;cin>>n>>m;
       vector<ll>v;
       for (int i = 0; i < n; i++)
       {
           ll x;cin>>x;
           v.push_back(x);
       }

       ll crr_sum = 0, max_sum = 0;
       for (int i = 0; i < n; i++)
       {
           crr_sum = (crr_sum%m + v[i]%m)%m;
           
           if (crr_sum > max_sum)
           {
               max_sum = crr_sum;
           }
           else crr_sum = 0;
       }
       cout<<max_sum<<endl;
      
    }
}