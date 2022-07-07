#include<bits/stdc++.h>
using namespace std;
void subsets(int arr[], int n){
  for (int i = 0; i < (1<<n); i++) // 0 to 2 power n
  {
      for (int j = 0; j < n; j++)
      {
          if (i & (1<<j))
          {
              cout<<arr[j]<<" ";
          }
      }
        cout<<endl;
  }
}
int main()
{
   int a[3] = {1,2,3}; 
   subsets(a, 3);
  
return 0;
}
/**
 * for i in range 0 to 1<<n
 *     for j in range a
 *         if j & 1<<j == 1
 *            cout<<arr...
 * */