#include <bits/stdc++.h>
using namespace std;

int main(){

  int n,c=0,k=1,r=1;cin>>n;

  for (int i = 2; i*i<= n; i++)
  {
     //  cout<<"i is "<<i<<endl;
      if (n%i==0)
     {
        c=0;
        while (n%i==0)
        {
            n/=i;c++;
        }
        cout<<i<<"^"<<c<<endl;
      //   if (i!=2)
      //   {
      //      r *= (c+1);
      //   }
        
      //    k *= (c+1);
     }
  }
  
     if (n>1)
     {
      //    if (n!=2)
      //   {
      //      r *= (c+1);
      //   }
      //     k = k*2;
         cout<<n<<"^"<<"1"<<endl;
     }

   //  cout<<k-r<<endl;

    return 0;}