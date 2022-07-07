#include <bits/stdc++.h>
#include<iostream>
using namespace std;

//  1 9 1
//  2 9 1
//  3 9 3
//  4 9 1
//  5 9 1
//  6 9 3
//  7 9 1
//  8 9 1
//  9 9 9


// time compl is nlogn + q*sqrt n
int getcount(int n, int d){

   return phi[n/d];
}


int main(){

     int n,res=0;cin>>n;

    for (int i = 1; i*i <= n; i++)
    {
        if (n%i==0)
        {
          int d1 = i;
          int d2 = n/i;

           res += d1 * getcount(d1 , n);

           if (d1 != d2)
           {
             res += d2* getcount(d2 ,n);
           }
           
        }
        
    }
       cout<<res<<endl;






   return 0;}