#include <bits/stdc++.h>
using namespace std;

int main(){

   int a,b,c=0,i=0;
   a = 8;//1000
   b = 13;//1101

   a = (a^b);
   cout<<a<<endl;
   while (a>0)
   {
      if ((a&1))
      {
        c++;
      }
       a = a>>1;    
   }
   cout<<c<<endl; 

    return 0;
}