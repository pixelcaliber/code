#include <bits/stdc++.h>
using namespace std;
// 2^5 * 3^3
// 24
int main(){

 int t;cin>>t;
   while(t--){
  int n,c=0,k=0,r=1;cin>>n;
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
        k++;
        r *= (c+1);
     }
  }
     if (n>1)
     {
         k+=1;

        r = 2*r;
        cout<<n<<"^"<<"1"<<endl;
     }
     cout<<"ans is"<<r - k<<endl;
   //   else cout<<"1"<<endl;
   }
  //1 2 4 5 10 20
  //1 2 3 6

    return 0;}