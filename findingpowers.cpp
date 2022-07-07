#include <bits/stdc++.h>

using namespace std;
//n ko n/2 krna h agr n odd h to n*n-1 krna h tb..
int powertofind(long a, long n){
  
    if (n==0)
  {
    return 1;
  }
    else if (n%2==0)
  {
    return powertofind(a*a,n/2);
  }
    else return a*(powertofind(a*a,(n-1)/2));
}

int main(){
     
long a,n,result=0;cin>>a>>n;

result = powertofind(a,n);
cout<<result;

return 0;
}
// int powertofind(long a, long n){

//   long result=1,p;
//    if(n%2==0)
//       {
//           p = n/2;
//       }
//       else{p = (n-1)/2;}
//   while (p>0)
//   { 
//       result *= a*a;
//       p--;
//   }
//      if(n%2==0)
//       {
//          return result;
//       }
//       else{return result*a;}
// }