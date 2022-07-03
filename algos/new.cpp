#include <bits/stdc++.h>
 
using namespace std;
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll              long long
#define ull             unsigned long long
#define vll             vector<ll>
#define pll             pair<ll,ll>
#define vpairll         vector<pair<ll,ll>>
#define mpll            map<ll,ll>
#define mpcl            map<char,ll>
#define setll           set<ll>
#define setbits         __builtin_popcountll //count number of 1 in binary
#define leadzero        __builtin_clz //count leading zeroes in binary
#define tailzero        __builtin_ctz //coutn tail zero
#define pb              push_back
#define pfrt            push_front
#define lb              lower_bound
#define ub              upper_bound
#define F               first
#define S               second
#define endl            "\n"
#define all(v)          v.begin(),v.end()
#define revall(v)       v.end(),v.begin()
#define MEM(a, b)       memset(a, (b), sizeof(a))    
#define loop(i,a,b)     for(ll i=a;i<b;i++)
#define rev(i,a,b)      for(ll i=b-1;i>=a;i--)
#define foreach(it,l)   for(auto it=l.begin();it!=l.end();it++)
#define reveach(it,l)   auto it = l.end();it--;for(it;it!=l.begin();it--)
 
#define PI           3.1415926535897932384626433832795
const ll M      =    1e9+7;
const ll i1     =    1e3+5;

bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){
    return (a.second < b.second);
}
 
ll n,m; 
char ch[i1][i1];
pll start;
ll dis[i1][i1];
 
ll a[]={-1,1,0,0};
ll b[]={0,0,1,-1};//UDRl
char go[]={'U','D','R','L'};
 
bool check(ll i1, ll j1){
    if(i1<0 || j1<0) return false;
    if(i1>n-1 || j1>m-1) return false;
    if(ch[i1][j1]!='.') return false;
    return true;
}
 
void harsh_op(ll test_case){
 
    cin>>n>>m;
 
    queue<pll> q;
 
    loop(i,0,n){
        loop(j,0,m){
            cin>>ch[i][j];
            if(ch[i][j]=='A')start = {i,j};
            if(ch[i][j]=='M')q.push({i,j});
        }
    }
 
    q.push(start);
    dis[start.F][start.S] = -1;
 
    while(!q.empty()){
        auto x = q.front().F, y = q.front().S;
        q.pop();
        if(ch[x][y]=='A' and (x==0 or x==n-1 or y==0 or y==m-1)){
            cout<<"YES"<<endl;
            string ans;
            ll k = dis[x][y];
            while(k!=-1){
                ans+=go[k];
                x -= a[k];
                y -= b[k];
                k = dis[x][y];
            }
            reverse(all(ans));
           
            cout<<ans.size()<<endl<<ans;
            return;
        }
        loop(i,0,4){
            ll x1 = x+a[i];
            ll y1 = y+b[i];
            if(check(x1,y1)){
                ch[x1][y1] = ch[x][y];
                if(ch[x1][y1]=='A') dis[x1][y1] = i;
                q.push({x1,y1});
            }
        }
 
    }
        
    cout<<"NO"<<endl;
 
}
 
 
int main(){
    fast;
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    ll ttcc = 1;
    ll test_case=0;
    while(ttcc--){
        harsh_op(test_case);
        test_case++;
    }
 
}