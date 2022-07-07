#include <bits/stdc++.h>
using namespace std;
#define n 100000
int main(){
 
 int t;cin>>t;
 vector<int>v;
  
  bool isprime[n+1]; isprime[0] = false; isprime[1] = false;
 
 for (long i = 2; i<= n; i++)
 {
     isprime[i] = true;
 }
 for (long i = 2; i*i <= n; i++)
 {
     if (isprime[i] == true)
     {
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
        v.push_back(i);
     }
 }  
   
   while (t--)
   {
       int i;cin>>i;
       cout<<v.at(i-1)<<endl;
   }
   
 
 
 
return 0;} 