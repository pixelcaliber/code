#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){

   ll n;cin>>n;
   vector<ll>v(n);
   for (ll i = 0; i < n; i++)
   {
       cin>>v[i];
   }
   ll to_find; cin>>to_find;
   ll low = 0, high = n-1;
   ll mid;
//    while (high-low>1)
  for(ll i=0; i<100; i++)
   {
       mid = (low+high)/2;
       if (v[mid]<to_find)
       {
           low = mid + 1;
       }
       else {
           high = mid;
       }
   }
      if (v[low] == to_find)
      {
          /* code */cout<<low<<endl;
      }
      else if (v[high] == to_find)
      {
          /* code */cout<<high<<endl;
      }
      else cout<<"Not Found"<<endl;


    return 0;
}
// ll binary_search(ll v[], ll n, ll to_find)//(vector<ll>v, ll n, ll to_find){

//   ll low = 0, high = n-1;
//    ll mid;
//    while (high-low>1)
//    {
//        mid = (low+high)/2;
//        if (v[mid]<to_find)
//        {
//            low = mid + 1;
//        }
//        else {
//            high = mid;
//        }
//    }
//       if (v[low] == to_find)
//       {
//           // /* code */cout<<low<<endl;
//         return low;
//       }
      
//        else if (v[high] == to_find)
//       {   // /* code */cout<<high<<endl;
//         return high;
//       }
//       return -1;

// }