#include <bits/stdc++.h>

using namespace std;
int gcd(int a,int b){
  
  if(b == 0) 
  return a;

  else return gcd( b , a%b);
}

int main(){

  int a,b;cin>>a>>b;
//   int m = min(a,b),gcd;

//   for (int i = m; i > 0; i--)
//   {
//       if (a%i==0 && b%i==0)
//       {
//           gcd = i;
//           break;
//       }
      
//   }
     
      cout<<gcd(a,b);


    return 0;
}