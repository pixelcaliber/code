#include <bits/stdc++.h>
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;

int main(){
  
  int n;cin>>n;
  string s,r;
  int k,m=0;
  cin>>s>>k;

  for (int i = 0; i < s.size()+1; i++)
  {
      for (int j = 1; j < s.size()-i; j++)
      {
            r[m] = s.substr(i,j);
            m++;
      }
  }
     for (int i = 0; i < m; i++)
   {
       cout<<r[i]<<endl;
   }
   



    return 0;}