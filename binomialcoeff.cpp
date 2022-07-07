#include <bits/stdc++.h>
#define m 1000000007
using namespace std;
 
long long binomialCoeff(long long n, long long k)
{
     long long res = 1;
     if (k>n-k)
   {
       k = n-k;
   }
     for (long long i = 1; i <= k; i++)
   {
       res = (res * (n-i+1));
       res /= i;
   }  
     return res;
}
int main()
{
  long long t;cin>>t;
  
  while(t--){
    
     long long n=0,k=0;cin>>n>>k;
     cout << binomialCoeff(n, k)<<endl;
  }    
    return 0;
}
