#include <bits/stdc++.h>
using namespace std;

int main(){
   int res=0,r=0;
  
  for (int i = 1; i <= 100; i++)
  {
    //   for (int j = i; j <= 10; j++)
    //   {
    //       res += 2*i*j;
    //   }
     res += i*i;
     r += i;
      
  }
       r = r*r;
  cout<<r - res;
  




    return 0;
}