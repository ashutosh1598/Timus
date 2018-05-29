#include"iomanip"
#include"iostream"
#include"limits"
#include"cmath"
#include"vector"
#include"algorithm"
#include"list"
#include"queue"
#include"stack"
#include"set"
#include"unordered_set"
#include"map"
#include"unordered_map"
#include"string"
#include"cstring"
#include"assert.h"
using namespace std;
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define mp make_pair
#define pb push_back
#define mset(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int n,k;
vector<ll>len;
int solve(ll m)
{
    if(m==0)return 1;
    ll to=0;
    for(int i=0;i<n;++i)
    {
        to+=len[i]/m;
        if(to>=k)return 1;
    }
    return 0;
}
void print(ll x)
{
    /*
    cout<<x/100<<".";
    ll de=x%100;
    if(de<10)cout<<0;
    cout<<de<<'\n';
    */;
    ld y=x;
    y/=100;
    cout<<fixed<<setprecision(2);
    cout<<y<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    len.resize(n+5);
    for(int i=0;i<n;++i)
    {
        ld x;
        cin>>x;
        len[i]=100*x;
    }
    ll low=0,hi=1e7+2;
    while(low<hi-1)
    {
        ll mid=(low+hi)/2;
        if(solve(mid))
        {
            low=mid;
        }
        else hi=mid;
    }
    if(solve(hi))
    {
        print(hi);
    }
    else print(low);
}
