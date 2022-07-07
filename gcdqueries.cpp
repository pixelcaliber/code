#include <bits/stdc++.h>
using namespace std;
long pre[100002];
long suf[100002];

long gcd(long a,long b){
  
  if(b == 0) 
  return a;
  else return gcd(b , a%b);
}
int main(){
  
   long t;cin>>t;
   while (t--)
   {
     long n=0,q=0,l=0,r=0;
     cin>>n>>q;
     pre[0] = suf[n+1] = 0;
     long a[n+2];
     for(long i=0; i<n ;i++)
     {
         cin>>a[i+1];
     }
     for (long i = 1; i <= n; i++)
  {
     pre[i] = gcd(pre[i-1], a[i]);
  }
  for (long i = n; i > 0; i--)
  {
    suf[i] = gcd(suf[i+1], a[i]);
  }
    while(q--){
      cin>>l>>r;
      cout<< gcd(pre[l-1], suf[r+1])<<endl;
    }
   }
  return 0;
}