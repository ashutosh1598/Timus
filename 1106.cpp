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
int g[200];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		int ot;
		if(g[i]==0)
		{
			g[i]=1;
			ot=2;
		}
		else if(g[i]==1)
		{
			ot=2;
		}
		else ot=1;
		int x;
		cin>>x;
		bool a=true,b=false;;
		while(x!=0)
		{
			if(g[x]==0)
			{
				g[x]=ot;
				a=false;
			}
			else if(g[x]==1)
				b=true;
			cin>>x;
		}
		if(a)
		{
			if(b)
				g[i]=2;
			else g[i]=1;
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i)
		if(g[i]==1)
			ans++;
	cout<<ans<<'\n';
	for(int i=1;i<=n;++i)
		if(g[i]==1)
			cout<<i<<' ';
	if(ans>0)
		cout<<'\n';
}
