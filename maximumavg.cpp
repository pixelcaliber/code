#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
ll lo, hi;
ll n, d;
vector<ll>a;
bool check(ld mid){
          ld sum = 0, last = 0;
          for (int i = 0; i < d; i++)
          {
               sum += a[i] - mid;
          }
          if (sum>=0)
          {
               lo = 0, hi = d-1;
               return true;
          }
          ld minn = 0;
          for (int i = d; i < n; i++)
          {
               sum += a[i]-mid;
               last += a[i-d]-mid;
               minn = min(minn, last);
               if (sum>=minn)
               {
                    hi = i;
                    return true;
               }      
          }
     return false;
}
int main(){
               cin>>n>>d;
               for (int i = 0; i < n; i++)
               {
                    int x;cin>>x;
                    a.push_back(x);
               }
               ld low = INT64_MIN, high = INT64_MAX;
               for (int i = 0; i < 100; i++)
               {
                    ld mid = low + (high-low)/2;
                    if (check(mid))
                    {
                              low = mid;
                    }
                    else high = mid;
               }
               cout<<low<<endl;
               vector<ld>s;
               ll sum = 0;
               for (int i = 0; i < n; i++)
               {
                    sum += a[i];
                    s.push_back(sum);
               }
               for (int i = 0; i <= hi-d; i++)
               {
                         ld c = (s[hi]-s[i])/(hi-i);
                         if (low-c<=1e-8)
                         {
                              lo = i+1;
                              break;
                         }   
               }
           cout<<lo+1<<" "<<hi+1<<endl;              
 return 0; 
}