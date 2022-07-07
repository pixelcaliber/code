#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int gcd(int a, int n){

   if (n==0)
   {
       return a;
   }
   else
   {
      return gcd(n,a%n);
   }
}
int main(){

     int n,sum=0;cin>>n;

    for (int i = 1; i <= n; i++)
    {
        cout<<"gcd is "<<gcd(i,n)<<endl;
        sum += gcd(i,n);
    }
    //  cout<<gcd(400,32);
     cout<<sum;



     return 0;}
     /* 

     gcd 1 7 = 1
     2 7 = 1
     3 7 = 1
     4 7 = 1
     5 7 = 1
     6 7 = 1
     7 7 = 7
    
     */