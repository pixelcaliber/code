#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int n;
      cin>>n;
      vector<pair<int,int>>a;
      for(int i=0;i<n;i++)
      {
          int x; cin>>x;
          a.push_back(make_pair(x,i));
      }
      sort(a.rbegin(),a.rend());
      int res[n];
      int sum=1;
      for(int i=0;i<=n-1;i+=2,sum++)
      {
        res[a[i].second]=(sum+1);
        if(i+1 < n)
        res[a[i+1].second]=(1-sum);
      }
      

      sum=1;
      int ans=0;
      for(int i=0;i<=n-1;i+=2,sum++)
      {
          ans+=((a[i].first)*2*sum);
          if(i+1 < n)
          ans+=((a[i+1].first)*2*sum);
      }
    
    cout<<ans<<"\n"; 
    cout<<1<<" ";
    for(int i=0;i<n;i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<"\n";
  }
}