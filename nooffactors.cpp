#include <bits/stdc++.h>
using namespace std;

int main(){
int n,c=0;cin>>n;
int k=0;

  for (int i = 2; i*i <= n; i++)
  {
      if (n%i == 0)
      {
          if (i == sqrt(n)) c++;
          else c+=2;     
      }   
         k++;
  }
    //  cout<<c+2<<endl;
     printf("%d\n", c+2);
  
      //  cout<<k<<endl;
     printf("%d", k+2);

  

    return 0;
}