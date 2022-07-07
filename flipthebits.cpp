#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define bhaag ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ld double
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define tests int t;cin >> t;while (t--)
#define mod 1000000007
ll n, k;
void solve()
{
    cin>>n;
    string a, b;  cin>>a>>b;
    ll c1[n+1] = {0}, c2[n+1] = {0};
    for (int i = 1; i <= n; i++)
    {
        if (a[i-1] == '1')
        {
            c1[i] = c1[i-1] + 1;
        }
        else c1[i] = c1[i-1];
         if (a[i-1] == '0')
        {
            c2[i] = c2[i-1] + 1;
        }
        else c2[i] = c2[i-1];
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i]!=b[i])
        {
           ll temp = i;
           while (a[temp] != b[temp])
           {
               temp++;
           }
           if (c1[temp]!=c2[temp] || c1[i]!=c2[i])
           {
               cout<<"NO"<<endl;
               return;
           }
           i = temp;
        }
    }
        cout<<"YES"<<endl;    
}
int main()
{
    bhaag;
    tests
    solve();
}