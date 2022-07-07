#include<bits/stdc++.h>
using namespace std;
#define epsilon 1e-7
//epsilon will give ans with precision of that digits..
int sqr_root(int k){ //returns int value for greatest integer numbers..
    int low = 1; int high = k;
    while (high-low>1)
    {
        int mid = (low+high)/2;
        if (mid*mid < k)
        {
            low = mid;    
        }
        else high = mid;
    }
    if (low*low == k)
    {
         return low;
    }
    else if (high*high == k)
    {
         return high;
    }
    else return low;
}
double sqr_root_precised(double k){ //returns double with precision of epsilon e
    double low = 1; double high = k;
    // while (high-low>epsilon)
    for(int i=0;i<100;i++)
    {
        double mid = (low+high)/2;
        if (mid*mid < k)
        {
            low = mid;    
        }
        else high = mid;
    }
      return low;
}
double multiply(double k, int n){
 
   double ans = 1;
   for (int i = 0; i < n; i++)
   {
       ans *= k;
   }
   
    return ans;

}
double nth_root_precised(double k, int n){ //returns double with precision of epsilon e
    double low = 0; double high = k;
    // while (high-low>epsilon)
    for(int i=0; i<100; i++)
    {
        double mid = (low+high)/2;
        if (multiply(mid, n) < k)
        {
            low = mid;    
        }
        else high = mid;
    }
      return low;
}
int main(){
   
   long long k, n;cin>>k>>n;
//    cout<<sqr_root(k)<<endl;
//    cout<<fixed<<setprecision(20)<<sqr_root_precised((double)k)<<endl;
   cout<<fixed<<setprecision(20)<<nth_root_precised((double)k, n)<<endl;
   cout<<pow((double)k, 1.0/n)<<endl;
//    cout<<fixed<<setprecision(20)<<sqrt(k)<<endl;


    return 0;
}
//T C -- 
//for sqrt = log(n*(10^d)) d decimal places k liye agr chahiye to..
// for pth root tc = p*log(n*(10^d))...
