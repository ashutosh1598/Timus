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
//#include"unordered_set"
#include"map"
//#include"unordered_map"
#include"string"
#include"cstring"
using namespace std;
typedef long long ll;
ll pre[510];
ll dp[510][510];
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    ll n,k;scanf("%lld %lld",&n,&k);
    for(int i=1;i<=k;++i)
    {
        dp[n+1][i]=1e15;
    }
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&pre[i]);
        pre[i]+=pre[i-1];
        dp[i][k+1]=1e15;
    }
    dp[n+1][k+1]=0;
    for(int i=n;i>=1;--i)
    {
        for(int j=1;j<=k;++j)
        {
            dp[i][j]=1e15;
            for(int p=1;i+p-1<=n;++p)
            {
                ll b=pre[i+p-1]-pre[i-1];
                ll w=p-b;
                dp[i][j]=min(w*b+dp[i+p][j+1],dp[i][j]);
            }
        }
    }
    printf("%lld\n",dp[1][1]);
}
