#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define bhaag ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ld double
vector<vector<ll>>ans;
void confusing(vector<ll>&a, ll index, vector<ll>&sb){

      if (index == sb.size())
      {
          ans.push_back(a);
          return;
      }
      confusing(a, index+1, sb);
      a.push_back(sb[index]);
      confusing(a, index+1, sb);
      a.pop_back();
}
int main(){
    ll x; ld n; cin>>x>>n;  
    ll temp = pow(x, 1/n);
    vector<ll>v;
    for (int i = 1; i <=temp; i++)
    {
        v.push_back(i);
    }
      vector<ll>empty;
     confusing(empty, 0, v);

     for (int i = 0; i < ans.size(); i++)
     {
         for (int j = 0; j < ans[i].size(); j++)
         {
             cout<<ans[i][j]<<" ";
         }
         cout<<endl;
     }
     
       
      

}