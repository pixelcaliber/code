#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){

     int n;cin>>n;
     int a[99999];
    for (int i = 0; i <= 99998; i++)
    {
        a[i] = i;
    }
    for (int i = 2; i <= n; i++)
    {
        if (a[i] == i)
        {
            a[i] *= (i-1);
            a[i] /= i;
            // cout<<"a is "<<a[i]<<" i is "<<i<<endl;
            for (int j = i; j <= n; j+=i)
            {
                a[j] *= (i-1);
                a[j] /= i;
            //   cout<<"a is "<<a[j]<<" j is "<<j<<endl;

            }
            if (a[i]>1)
            {
                 a[i] /= i;
                 a[i] *= i-1;
            }
            //  cout<<a[2]<<endl;
        }    
        
    }
      
        int q;cin>>q;

        cout<<a[q];

     return 0;}