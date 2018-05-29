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
using namespace std;
typedef long long ll;
typedef long double ld;
ll n,m;
ld dp[1005][1005];
bool al[1005][1005];
ld st=100,di=sqrt(20000),inf=1e8;
ld solve(ll x,ll y)
{
    if(x>n||y>m)
        return inf;
    else if(dp[x][y]>=0)
        return dp[x][y];
    dp[x][y]=st+min(solve(x+1,y),solve(x,y+1));
    if(al[x][y])
        dp[x][y]=min(dp[x][y],di+solve(x+1,y+1));
    return dp[x][y];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll k;cin>>n>>m>>k;
    while(k--)
    {
        ll x,y;cin>>x>>y;
        al[x-1][y-1]=1;
    }
    memset(dp,-1,sizeof dp);
    dp[n][m]=0;
    cout<<round(solve(0,0))<<'\n';
}
