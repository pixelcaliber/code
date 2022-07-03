#include <bits/stdc++.h>
using namespace std;
#define endl        '\n'
#define F           first
#define S           second
#define ld          double
#define sz(x)       x.size()
#define ll          long long
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define maxe(a)     max_element(all(a))
#define mine(a)     min_element(all(a))
#define vin(a)      ll x; cin >> x; a.pb(x);
#define loop(i,x,y) for(int i = x; i < y; i++)

typedef vector<ll> vll;           typedef map<ll, ll> mapl;
typedef vector<pair<ll, ll>> vpl;

const ll mod = 1e9 + 7, N = 2e5 + 2;

int main()
{
    ll n, m; cin>>n>>m;
    vector<pair<ll, ll>>a;
    vector<ll>w;
    for (int i = 0; i < m; ++i)
    {
        ll x, y, wgh;cin>>x>>y>>wgh;
        a.push_back({x, y});
        w.pb(wgh);
    }
    ll dist[n + 1];
    for (int i = 1; i < n + 1; ++i)
    {
        dist[i] =  1e9;
    }
    dist[1] = 0;
    for (int i = 1; i <= n + 1; ++i)
    {
        bool f = 0;
        for (int j = 0; j < m; ++j)
        {
            if (dist[a[i].F] < 1e9)
            {
                if (dist[a[i].S] > dist[a[i].F] + w[i])
                {
                    dist[a[i].S] = dist[a[i].F] + w[i];
                    f = 1;
                }
            }
        }
        if (!f)
        {
            break;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cout<<dist[i]<<" ";
    }
    //to check for neg cycle we will have n interations and if till iterations if we will be getting relaxations then we can say there is neg cycle..

}