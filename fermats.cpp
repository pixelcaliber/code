#include<bits/stdc++.h>
using namespace std;
#define m 10000000000000007
unsigned long long power(unsigned long long a, unsigned long long n){
    if (n == 0)
    {
        return 1;
    }
    else if(n%2 == 0)
    return power((a*a)%m, n/2);

    return a*power((a*a)%m, (n-1)/2)%m;

}
int main(){

   unsigned long long a, n; cin>>a>>n;
   unsigned long long base=0;
      base = a%m;
      unsigned long long M = m-1;
      n = n%M;
      cout<<power(base, n)<<endl;






    return 0;
}