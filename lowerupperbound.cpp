#include<bits/stdc++.h>
using namespace std;
int lower_bound(vector<int>&v, int element){
    int s = v.size();
    int mid;
    int low = 1;
    int high = s - 1;
    while (high - low >1)
    {
        mid = (high+low)/2;
        if (v[mid]<element)
        {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
      if (v[low]>=element)
      {
          return low;
      }
      else if (v[high]>=element)
      {
            return high;
      }
      else return -1;
}
int upper_bound(vector<int>&v, int element){
    int s = v.size();
    int mid;
    int low = 1;
    int high = s - 1;
    while (high - low >1)
    {
        mid = (high+low)/2;
        if (v[mid]<=element)
        {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
      if (v[low]>element)
      {
          return low;
      }
      else if (v[high]>element)
      {
            return high;
      }
      else return -1;
}
int main(){

    int n;cin>>n;
   vector<int>v(n);
   sort(v.begin(), v.end());
   for (int i = 0; i < n; i++)
   {
       cin>>v[i];
   }
   int to_find; cin>>to_find;
  
   cout<<lower_bound(v, to_find)<<endl;
   cout<<upper_bound(v, to_find)<<endl;

    return 0;
}