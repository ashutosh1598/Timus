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
const int maxn=4010;
int dp [maxn][maxn];
int ans[maxn],pre[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string x;
	cin>>x;
	int n=x.length();
	for(int i=n-1;i>=0;--i)
	{
		dp[i][i]=1;
		for(int j=i+1;j<n;++j)
		{
			if(x[i]!=x[j])continue;
			if(i+1==j)
			{
				dp[i][j]=1;
			}
			else
			{
				dp[i][j]=dp[i+1][j-1];
			}
		}
	}
	ans[0]=1;
	pre[0]=0;
	for(int i=1;i<n;++i)
	{
		ans[i]=1+ans[i-1];
		pre[i]=i;
		for(int j=i-1;j>=0;--j)
		{
			if(dp[j][i]==1)
			{
				if(j==0)
				{
					ans[i]=1;
					pre[i]=0;
				}
				else
				{
					if(ans[i]>1+ans[j-1])
					{
						ans[i]=1+ans[j-1];
						pre[i]=j;
					}
				}
			}
		}
	}
	list<string> pp;
	int i=n-1;
	while(i>=0)
	{
		int l=pre[i];
		pp.push_front(x.substr(l,i-l+1));
		i=l-1;
	}
	cout<<pp.size()<<'\n';
	for(string xx:pp)
	{
		cout<<xx<<' ';
	}
	cout<<'\n';
}

