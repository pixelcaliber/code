#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll kadens(vector<ll>&a, int ind){
     
         ll crr_sum = 0, maxx_sum = INT64_MIN;
         for (int i = 0; i < a.size(); i++)
         {
                crr_sum += a[i];
                if (crr_sum > maxx_sum)
                {
                    maxx_sum = crr_sum;
                }
                if (crr_sum < 0)
                {
                   crr_sum = 0;
                }
         }
    return maxx_sum;
    // return max(maxx_sum, *max_element(a.begin(), a.end()));  // improvisation..
}
int main(){

   

    int n; cin>>n;
    vector<ll>a;
    for (int i = 0; i < n; ++i)
    {
        ll x; cin>>x;
        a.push_back(x);
    }
    cout<<kadens(a, 0);

}