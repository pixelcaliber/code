#include <bits/stdc++.h>
#include<vector>
using namespace std;
#define N 51
#define M 1000000007;
long a[N][N],I[N][N];

void mul(long size,long a[][N],long I[][N]){
     long res[size+1][size+1];

     for (long i = 0; i < size; i++)
     {
         for (long j = 0; j < size; j++)
         {
             res[i][j] = 0;
             for (long k = 0; k < size; k++)
             {
                 res[i][j] = (res[i][j] + a[i][k] * I[k][j])%M;
             }   
         }   
     }
      for (long i = 0; i < size; i++)
     {
         for (long j = 0; j < size; j++)
         {
             a[i][j] = res[i][j];
         }
     }
}
void power( long size,long a[][N], long n){

   for (long i = 0; i < size; i++)
   {
       for (long j = 0; j < size; j++)
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
        {mul(size,I,a);
        n--;}

        else
        {mul(size,a,a);
        n /= 2;}
    }
    
      for (long i = 0; i < size; i++)
      {
          for (long j = 0; j < size; j++)
          {
              a[i][j] = I[i][j];
          }
          
      }
}

void print(long a[][N],long size){
  for (long i = 0; i < size; i++)
  {
      for (long j = 0; j < size; j++)
      {
          cout<<a[i][j]<<" ";
      }
      cout<<endl;
  }
}

int main(){
    long t=0;cin>>t;

    for(long z=0;z<t;z++){
    long n,size;cin>>size>>n;
    for (long i = 0; i < size; i++)
    {
        for (long j = 0; j < size; j++)
        {
            cin>>a[i][j];
        }
    }
    power(size,a,n);
    print(a,size);
 }
}