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
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(v) v.begin().v.end()
#define mset(a,b) memset(a,b,sizeof (a))
typedef long long ll;
const ll maxn=(1LL<<(20))+10;
ll dp[maxn];
ll rec[30];
int n;
ll ff(int xx)
{
	ll ans=0;
	for(int i=0;i<n;++i)
	{
		if(   (1<<i)&xx)
			ans+=rec[i];
	}
	return ans;
}
ll solve(int xx)
{
	if(dp[xx]!=-1)return dp[xx];
	//ll sum=__builtin_popcount(xx);
	if(xx==0)return dp[xx]=0;
	ll ans=1e15;
	for(int i=0;i<n;++i)
	{
		int cas=0;
		if(   !   (xx&(1<<i))   )continue;
		if(i==0)
		{
			cas|=(  (1<<0)|(1<<1)|(1<<(n-1))           );
		}
		else if(i==n-1)
		{
			cas|=(  (1<<0)|(1<<(n-1))|(1<<(n-2)));
		}
		else
		{
			cas|=(  (1<<i)|(1<<(i-1))|(1<<(i+1)));
		}
		int cas1=(xx&(~cas));
		ans=min(ans,ff(cas1)+solve(cas1));
	}
	return dp[xx]=ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
	mset(dp,-1LL);
    for(int i=0;i<n;++i)
    {
        cin>>rec[i];
    }
	int cas=(1<<(n))-1;
	ll ans=solve(cas);
	cout<<ans<<'\n';
}
