#include <bits/stdc++.h>

using namespace std;
//n ko n/2 krna h agr n odd h to n*n-1 krna h tb..
long long powertofind(long long a, long long n, long long m){

  if(n == 0){return 1;}

  else if(n%2 ==0){
      return powertofind((a*a)%m,n/2,m);
  }   
   else{return a*(powertofind((a*a)%m,(n-1)/2,m))%m;}
}
 int main(){

   long long a,n,m,result=0;cin>>a>>n>>m;
   result = powertofind(a,n,m);
   cout<<result;
  return 0;}

//   5
// 9198928175275306856 88589373934493004
// 2079266551859936617 82000937650676615
// 4022095175003610813 980706422180266800
// 9759621850968318016 9163073129721701429
// 26843724234241091 540522616808150046