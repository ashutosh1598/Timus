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
const int maxn=1005;
int a[maxn];
vector<int>clist;
vector<list<int> >adj;
const ll mo=1000000009LL;
ll conv[1005],fir=0;
void make()
{
	for(int i=0;i<maxn;++i)
	{
		a[i]=i%2;
	}
	a[2]=1;a[1]=0;a[0]=0;
	for(int i=3;i<maxn;i+=2)
	{
		if(!a[i])continue;
		if(i>=100&&i<=999)
		{
			clist.pb(i);
			conv[i]=fir++;
		}
		for(int j=i*i;j<maxn;j+=i)
		{
			a[j]=0;
		}
	}
	for(int i:clist)
	{
		for(int j:clist)
		{
			int x2=i%10,x1=(i/10)%10;
			int y2=(j/10)%10,y1=(j/100)%10;
			if(x1==y1&&x2==y2)
			{
				adj[i].pb(j);
			}
		}
	}
}
ll dp[145][10005];
ll solve(ll pp,ll n)
{
	if(dp[conv[pp]][n]!=-1)return dp[conv[pp]][n];
	if(n==1)
	{
		return dp[conv[pp]][n]=1LL;
	}
	else
	{
		ll ans=0LL;
		for(int xx:adj[pp])
		{
			ans+=solve(xx,n-1);
			ans%=mo;
		}
		return dp[conv[pp]][n]=ans;
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;
	adj.resize(maxn);
	make();
	ll ans=0LL;
	mset(dp,-1LL);
	for(int x:clist)
	{
		ans+=solve(x,n-2);
		ans%=mo;
	}
	cout<<ans<<'\n';
}












