
#include <bits/stdc++.h>
using namespace std;

int main(void){
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
    std::cout<<c+2<<endl;
     std::cout<<k<<endl;
    //  printf("%d", c+2);
  }
    //   std::cout<<k<<endl;
    //  printf("%d", k+2);

