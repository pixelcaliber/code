#include <bits/stdc++.h>
using namespace std;
#define M 1000000007;
long a[2][2],I[2][2];

void mul(long b[][2],long I[][2]){
     long res[2+1][2+1];

     for (long i = 0; i < 2; i++)
     {
         for (long j = 0; j < 2; j++)
         {
             res[i][j] = 0;
             for (long k = 0; k < 2; k++)
             {
                 res[i][j] = (res[i][j] + b[i][k] * I[k][j])%M;
             }   
         }   
     }
      for (long i = 0; i < 2; i++)
     {
         for (long j = 0; j < 2; j++)
         {
             b[i][j] = res[i][j];
         }
     }
}
void power(long b[][2], long n){

   for (long i = 0; i < 2; i++)
   {
       for (long j = 0; j < 2; j++)
      {     
         if (i==j)
       {
           I[i][j] = 1;
       }
         else I[i][j] = 0;
       } 
   }
    while (n)
    {
        if(n%2)
        {mul(I,b);
        n--;}

        else
        {mul(b,b);
        n /= 2;}
    }
    
      for (long i = 0; i < 2; i++)
      {
          for (long j = 0; j < 2; j++)
          {
              b[i][j] = I[i][j];
          }
          
      }
}
int main(){
   long t=0;cin>>t;

    while(t--){
 
  long a[2][3], b[2][2];
    // a[0][0] = 1;a[0][1] = 1;

  for (int i = 0; i < 1; i++)
  {
      for (int j = 0; j < 2; j++)
      {
          cin>>a[i][j];
      } 
  }
     long n=0;cin>>n;
     n = n-1;
     if (n<=1)
     {
          cout<<a[0][n];
          return 0;
     }
     
     b[0][0] = 0;b[0][1] = 1;
     b[1][0] = 1;b[1][1] = 1;

     power(b,n);

     long final[1][2] = {0,0};

       for (long j = 0; j < 2; j++)
       {
          for (long k = 0; k < 2; k++)
          {
              final[0][j] += a[0][k]*b[k][j]; 
          }  
       }
         cout<<final[0][0]<<endl;
    }

    return 0;
}