#include<bits/stdc++.h>
using namespace std;
#define epsilon 1e-7
int main(){
     long long t;cin>>t;
     while (t--)
     {
        long long x;cin>>x;
        long long cube;
        cube = pow(double(x), 1.0/3);
      //   cout<<setprecision(7)<<cube<<endl;
        long long low = 1, high = cube;
        bool flag = false;
        while (low<=high)
        {
           if (pow(low, 3) + pow(high, 3) == x)
           {
               cout<<"YES"<<endl;
               flag = true;
               break;
           }
           else if (pow(low, 3) + pow(high, 3)<x)
           {
               low++;
           }
           else if(pow(low, 3) + pow(high, 3)>x)
           {
              high--;
           }
        }
           if (!flag)
           {
              cout<<"NO"<<endl;
           }
     }
    return 0;
}