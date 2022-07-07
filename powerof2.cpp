#include<bits/stdc++.h>
using namespace std;
bool ispower2(int n){

    return (n && !(n & (n-1)));

}
int main()
{
  int n;cin>>n;
  
  cout<<((ispower2(n) == 1) ? "true" : "false")<<endl;
  
  return 0;
}