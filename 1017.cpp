#include"iostream"
#include"cmath"
#include"algorithm"
#include"cstring"
using namespace std;
typedef long long ll;
ll my[505][505];
ll solve(ll n,ll i)
{
    if(my[n][i]>=0)
    {
        return my[n][i];
    }
    else if(n==0)
        return 1;
    ll ans=0;
    for(int j=1;j<i&&j<=n;++j)
    {
        ans+=solve(n-j,j);
    }
    return my[n][i]=ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;cin>>n;
    ll ans=0;
    for(int i=0;i<505;++i)
    {
        for(int j=0;j<505;++j)
        {
            my[i][j]=-1;
        }
    }
    memset(my,-1,sizeof my);
    for(int i=1;i<=n;++i)
    {
        ans+=solve(n-i,i);
    }
    cout<<ans-1<<'\n';
}
