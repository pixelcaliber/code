#include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
long power(long a,long n, long M){
   
    if (n==0)
   {
       return 1;
   }
     else if(n%2==0)
   {
      return power((a*a)%M,n/2, M);
   }
     else return (a*power((a*a)%M,(n-1)/2,M))%M;
}
int main(){
  
     long a,n;cin>>a>>n;
    //  long M = n;
    //   n = n-2;
     a = a - n;
     cout<< power(a,n-2, n);

    return 0;
}