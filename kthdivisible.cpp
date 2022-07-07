#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define bhaag ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ld double
/*
     n==k ans 1
     n>k
     value = k*(n/k + 1) iss value tk phuchna h hme theek h aur kaise aab phuche vo dekhna h bs...
     r = value - n;
     r%n ans

     n<k
     r = k-n
*/
int main(){

        int t;cin>>t;
        while (t--)
        {
            ll n, k; cin>>n>>k;
            if (n%k==0)
            {
                cout<<"1"<<endl;
            }
            else if(n<k){
                ld tmp = (ld)k/n;
                tmp = ceil(tmp);
                cout<<(ll)tmp<<endl;
            }
            else
            {
                ld temp = (ld)n/k;
                temp = ceil(temp);
                ll x = temp*k;
                ld y = ceil((ld)x/n);
                cout<<(ll)y<<endl;
            }
        
        }
    return 0;
}