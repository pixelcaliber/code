#include <bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
 
int t;cin>>t;
 vector<int>v;
   for(int j =0; j<t;j++){
  long n;cin>>n;

  bool isprime[n+1];
  isprime[0] = false;
  isprime[1] = false;
 for (long i = 2; i<= n; i++)
 {
     isprime[i] = true;
 }
 for (long i = 2; i*i <= n; i++)
 {
     if (isprime[i] == true)
     {
         for (long j = i*i; j <=n; j+=i)
         {
             isprime[j] = false;
         }  
     }  
 }  
      int k=0;
    for (long i = 1; i <= n; i++)
 {
    
     if (isprime[i] == true)
     {
         k++;
       cout<<"prime "<<i<<endl;
    //    v.push_back(i);
     }
    // else cout<<"composite"<<endl;
    // cout<<v.at(4);
    
   }
   cout<<k;
}return 0;}