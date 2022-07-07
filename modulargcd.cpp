#include <bits/stdc++.h>
using namespace std;
#define m 1000000007
/*
aN + bN, a-b
s-b k divisors nikal lenge aur hrr divisor ko check krenge ky vo divisible h ya nhi aN + bN
aur a se check krne k liye hmlog ye dekhenge ki aN%d ar bN%d %d 0 h ya nhi...
*/
unsigned long long powertofind(unsigned long long a, unsigned long long n, unsigned long long c){

  if(n == 0){return 1;}

  else if(n%2 ==0){
      return powertofind((a%c*a%c)%c,n/2,c);
  }   
   return a%c*(powertofind((a%c*a%c)%c,(n-1)/2,c))%c;
}
unsigned long long gcd(unsigned long long a, unsigned long long b, unsigned long long n){

   if (a == b)
   {
       return (powertofind(a, n, m) + powertofind(b, n, m))%m;
   }
   unsigned long long num = a - b, p = 1;
   for (unsigned long long i = 1; i*i <= num; i++)
   {
        if (num%i == 0)
        {
            unsigned long long temp = (powertofind(a, n, i) + powertofind(b, n, i))%i;

            if (temp == 0)
            {
                p = max(p, i);
            }
            temp = (powertofind(a, n, num/i) + powertofind(b, n, num/i))%(num/i);
        
            if (temp == 0)
            {
                p = max(p, num/i);
            }
        }    
   }
       return p%m;
}
int main(){

  int t;cin>>t;
  while (t--)
  {
     unsigned long long a,b,n;cin>>a>>b>>n;
     cout<< gcd(a, b, n) <<endl;

  }
  





    return 0;
}