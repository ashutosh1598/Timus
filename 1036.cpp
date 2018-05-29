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
ll dp[55][1005];
ll solve(int n,int s)
{
    if(dp[n][s]!=-1)return dp[n][s];
    if(n==1)
    {
        if(s>=0&&s<=9)
        {
            return dp[n][s]=1;
        }
        else return dp[n][s]=0;
    }
    ll ans=0;
    for(int i=0;i<10;++i)
    {
        ans+=solve(n-1,s-i);
    }
    return dp[n][s]=ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,s;
    cin>>n>>s;
    if(s%2!=0)
    {
        cout<<"0\n";
        return 0;
    }
    s/=2;
    mset(dp,-1);
    ll ans=solve(n,s);
    cout<<ans*ans<<'\n';
}
