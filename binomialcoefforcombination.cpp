#include <bits/stdc++.h>
using namespace std;
#define M 1000000007

long long power(long long a,long long b){

    if (b==0)
    {
        return 1;
    }
    else if (b%2==0) return power((a*a)%M, b/2);

    else return (a * power((a*a)%M , (b-1)/2))%M;
}
int main(){

   int t;cin>>t;
    long long f[99999];

    f[0] = f[1] = 1;
    for (long long i = 2; i <= 99998; i++)
    {
        f[i] = ((f[i-1])%M * (i)%M)%M;
    }

   for (int z = 0; z < t; z++)
   {   
    long long n,k;cin>>n>>k;
    
    long long res = 1;
    res = f[n];

    res = (res * power(f[n-k], M-2))%M;

    res = (res * power(f[k], M-2))%M;

    cout<<res<<endl;
   }
   
    return 0;
}