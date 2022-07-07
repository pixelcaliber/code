#include <bits/stdc++.h>
#include <string>
#define m 1000000007
using namespace std;
//n ko n/2 krna h agr n odd h to n*n-1 krna h tb..
int powertofind(long long a, long long n){

  if(n == 0){return 1;}

  else if(n%2 == 0){
      return powertofind((a*a)%m,n/2);
  }   
   else{return a*(powertofind((a*a)%m,(n-1)/2))%m;}
}
 int main(){

  int t;cin>>t;
   while(t--){

       string a,n;cin>>a>>n;
       long long c=0,d=0;
   
        long long base=0,power=0;

        for(long long i=0; i<a.size(); i++)
        {
            base=((base%m*10)%m+(a[i]-'0')%m)%m;
        }

       long long M = m-1;
       
   for (int i=0; i<n.size(); i++) {
     power = ((power%M * 10)%M + (n[0] - 48)%M)%M;
   }
     
   long long result = powertofind(base,power);
   cout<<result<<endl;
   }
   
  return 0;}