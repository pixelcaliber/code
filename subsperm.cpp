#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define bhaag ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ld double
bool isprime[10000001];
int n, k;
int ans;
vector<int>v;
int main(){
    bhaag;
    int t;cin>>t;
    while(t--){
    cin>>n;
     string s;cin>>s;
     string tem = s;
     sort(tem.begin(), tem.end());
     ll cnt=0;
     for (int i = 0; i < s.length(); i++)
     {
         if (s[i]!=tem[i])
         {
            cnt++;
         }
         
     }
      cout<<cnt<<endl;

    } 
       
}