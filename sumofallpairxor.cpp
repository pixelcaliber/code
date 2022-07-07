#include <bits/stdc++.h>
using namespace std;

 int main(){
    
    int n;cin>>n;
    int a[n], count[32] = {0};

    for (int i = 0; i < n; i++)
    {
       cin>>a[i];
    }
      
  for(int j = 0; j < 32; j++){
    for (int i = 0; i < n; i++)
    {
       if ((a[i] & (1<<j)) != 0)
       {
          count[j]++;       //count store kr rha h count of kis index p how many times set bit aaya h..
       }
    }
  }

    for (int i = 0; i < 32; i++)
    {
       count[i] = count[i] * (n - count[i]);  //count m ek change kr re h.. change -- (noof setbits at that index * noof unset bits at that index) isko assign kr de rhe h count k hrr index p
    }
   //  for (int i = 0; i < 5; i++)
   //  {
   //     cout<<count[i]<<" ";
   //  }
    
     int res = 0;
    for (int i = 0; i < 32; i++)
    {
        res += count[i]* (1<<i); // yaha binary s decimal m convert krr re h 2 k power se multiply krke with the value of count at each index..
    }
    
   cout<<res<<endl;

    return 0;
}