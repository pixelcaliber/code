#include<bits/stdc++.h>
using namespace std;

int main(){
 
        // string s; cin>>s;
        //  uint32_t res = 0;
        // for(int i=0; i<10; i++){
        //     res += (s[i] * (1<<i));
        // }
        // // cout<<s<<endl;
        // cout<<res<<endl;
    //     reverse(s.begin(), s.end());

    //     res =0;
    //     for(int i=0; i<32; i++){
    //         res += (s[i] * (1<<i));
    //     }
    //   cout<<res<<endl;
     
       vector<int>s;    
       uint32_t res = 0,n,i=0;
        // 
        cin>>n;
        while(i<32){
           
          int x = n%2;
          n = n/2;
          s.push_back(x);
            i++;
        }
        for (int j = 0; j < i; j++)
        {
            cout<<s.at(j)<<" ";
        }
        reverse(s.begin(), s.end());
        for (int j = i-1; j >= 0; j--)
        {
            res += s[j] * (1<<j);
        }
        
        cout<<endl<<res<<endl;//43261596

    return 0;
}