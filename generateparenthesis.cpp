#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define bhaag ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ld double
vector<vector<string>>ans;
vector<string>sb;
void generate(string &s, ll open, ll close){
  
    if (open == 0 && close == 0)
    {
        sb.push_back(s);
    }
    
    if (open>0)
    {
        s.push_back('(');
        generate(s, open-1, close);
        s.pop_back();
    }
    if (close>0 && open<close)
    {
        s.push_back(')');
        generate(s, open, close-1);
        s.pop_back();
    }
    
    return;
    
     
}
int main(){
   
     string s = "";
     generate(s, 3, 3);
     
     for (int i = 0; i < sb.size(); i++)
     {
         cout<<sb[i]<<endl;
     }
       
      

}