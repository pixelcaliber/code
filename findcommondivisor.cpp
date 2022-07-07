#include <bits/stdc++.h>
#include<vector>
using namespace std;
int gcd(int a, int b){
  
  if (b == 0)
  return a;
  else return gcd(b, a%b);
}
int main(){

    int n,k;cin>>n>>k;
   
    int res = gcd(n, k);
    cout<<"res is "<<res<<endl;

    int c=0;
    for (int i = 1; i*i<= res; i++)
  {
      if (res%i==0)
     {
        if (i  == sqrt(res))
        {
          c++;
        }
        else c+=2;
     }
  }  
    //  if (res>1)
    //  {
    //      c+=2;
    //  }
    //  else if (res == 1){c++;}
       
    cout<<"c is "<<c;

    return 0;}