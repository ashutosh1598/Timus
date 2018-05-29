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
ll rec[110][110];
ll dp[110][110];
ll ans[110][110];
ll ssub(ll x1,ll y1,ll x2,ll y2)
{
	return dp[x2][y2]  +  dp[x1-1][y1-1]  -   dp[x2][y1-1]  -   dp[x1-1][y2];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;cin>>n;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cin>>rec[i][j];
            dp[i][j]=rec[i][j] +dp[i-1][j]+dp[i][j-1] -dp[i-1][j-1];
        }
    }
    ll glo=-1e18;
	ll curr=0,eher=0;
    for(int i=1;i<=n;++i)
    {
        for(int j=i;j<=n;++j)
        {
			curr=0;eher=0;
			for(int row=1;row<=n;++row)
			{
				ll rsum=ssub(i,row,j,row);
				eher=max(curr+rsum,rsum);
				glo=max(glo,eher);
				curr=eher;
			}
        }
    }
    cout<<glo<<'\n';
}
