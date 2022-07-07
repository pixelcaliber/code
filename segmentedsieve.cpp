#include <bits/stdc++.h>
using namespace std;

int main(void){

    long l,r,n;cin>>l>>r>>n;
    long k =sqrt(r) ;
    //cout<<k<<endl;
    long arr[k + 1];
   for (long i = 0; i <= k; i++)
   {
       arr[i] = 0;
   }
  
   for (long i = 2; i*i <= r; i++)
   {
       if (arr[i] == 0)
       {
           for (long j = i*i; j <= k; j+=i)
           {
               arr[j] = 1;
           } 
       } 
   }
    //    for (long i = 0; i < k+1; i++)
    //    {
    //        cout<<"a is "<<arr[i]<<" i is "<<i<<endl;
    //    }

    long b[r-l+2];   
   for (long i = 0; i <= r-l+1; i++)
   {
       b[i] = 0;
   }
   b[0] = 1;
   b[1] = 1;
   for (long i = 2; i <= k; i++)
   { 
        if(arr[i] == 0)
       {
      //for every multiple of p in l to r.
      // i is prime aab i k multiple from L to r ko 1 kr dena h aur kya bs itna hi kaam h baki aur kuch nhi h jyada isse
       for (long j = l; j < r+1; j++)
       {
           if (j%i == 0)
           {
               b[j-l] = 1;
           }   
       }
     }
    }
    for (long i = 0; i < r-l+1; i++)
    {
        cout<<"b is "<<b[i]<<" i is "<<i+1<<endl;
    }
    
    //  cout<<b[n-l];   
    //cout<<b[n]<<endl;
     
return 0;}