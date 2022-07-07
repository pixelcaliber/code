#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,count = 0;cin>>n;
  // while (n > 0)
  // {
  //    count++;
  //    n =  (n & n-1);
  // }
  //  cout<<count<<endl;
  
   //OR
   //logn -- tc
  int c = 0,i = 0;
  while (n>0)
  {
    if (((n) & 1) == 1) c++;
    n = n>>i;
  
    i++;
  }
  
  cout<<c<<endl;

  return 0;
}