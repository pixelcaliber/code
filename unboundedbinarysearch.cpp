#include <bits/stdc++.h>
using namespace std;
vector<long>v;

long f(long x) {
    long a = v[0];
    long b = v[1]; long c = v[2];

    return a*x*x + b*x + c;
}
// Find the value of `x` in the search space `[low, high]` using binary search
// where `f(x)` becomes positive for the first time
long binarySearch(long low, long high)
{
    // Base condition (search space is exhausted)
    if (high < low) {
        return -1;
    }
 
    // find the mid-value in the search space
    long mid = low + ((high - low) / 2);
    // if `f(mid)` is positive
    if (f(mid) > 0)
    {
        // return `mid` if it is the first element of the search space or
        // when `f(mid-1)` is not positive
        if (mid == low || f(mid - 1) <= 0) {
            return mid;
        }
        // otherwise, discard all elements in the right search space
        return binarySearch(low, mid - 1);
    }
    // if `f(mid)` is zero or negative,
    // discard all elements in the left search space
    return binarySearch(mid + 1, high);
}
// Returns the positive value `x`, where `f(x)` becomes positive for the first time
long exponentialSearch()
{
    // find the range in which the result would reside
    long i = 1;
    while (f(i) <= 0)
    {
        // calculate the next power of 2
        i *= 2;
    }
    // call binary search on `[i/2, i]`
    return binarySearch(i/2, i);
}
int main(void)
{
    long t;cin>>t;

    while(t--){

    for (long i = 0; i < 4; i++)
    {
        long k;cin>>k;
        v.push_back(k);
    }
    v[2] = v[2] - v[3];
    if (v[2] == 0)
    {
        cout<<"0"<<endl;
    }
    else{
    long x = exponentialSearch();
    
    if (f(x-1) == 0)
    {
        if (x-1< 0)
        {
                cout<<"0"<<endl;
        }
        else
        cout<<x-1<<endl;
    }
    else
    cout<<x<<endl;
    }
    v.clear();  
}

    return 0;
}