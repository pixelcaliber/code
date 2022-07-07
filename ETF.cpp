#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){

     int n;cin>>n;
     int c = n;
     for (int i = 2; i*i<= n; i++)
    {
       if (n%i==0)
     {
          c/=i;
          c*=(i-1);
           while (n%i==0)
         {
            n/=i;  
         }
      }
    }
     if (n>1)
     {
         c /= n;
         c *= n-1;
     }
      cout<<c<<endl;

     return 0;}