#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define bhaag ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ld double
ll m = 1000000007;
vector<ll>v;
 long long int nthFibonacci(long long int n, long long val = 1, long long prev = 0){
        
        if(n == 0) return prev%m;
        
        v.push_back(val%m); // this is to stre fibo numbers..

        return nthFibonacci((n - 1)%m, (val%m+prev%m)%m, val%m)%m;;
    }
int main(){
   
    ll n;cin>>n;
    cout<<nthFibonacci(n)<<endl;; //printing nth fibo number 

    for (int i = 0; i < n; i++)  // printing 1st n fibo numbers
    {
        cout<<v[i]<<" ";
    }
    
}