#include <bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
 
 vector<int>v;
  
  long n,ans=0;cin>>n;

  bool isprime[n+1];
  isprime[0] = false;
  isprime[1] = false;
 for (long i = 2; i<= n; i++)
 {
     isprime[i] = true;
 }
 for (long i = 2; i*i <= n; i++)
 {
     if (isprime[i] == true)
     {
            //  ans++;
         for (long j = i*i; j <=n; j+=i)
         {
             isprime[j] = false;
         }  
     }  
 }
    for (long i = 2; i <= n; i++)
 {
     if (isprime[i] == true)
     {
         ans++;
         cout<<i<<endl;
    //    cout<<"prime"<<endl;
    //    v.push_back(i);
     }
 }
     cout<<ans<<endl;
    // cout<<v.at(4);
   
    return 0;}