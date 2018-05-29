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
bool sp[150];
int par[150];
int find(int x)
{
	return par[x]==x?x:par[x]=find(par[x]);
}
void merge(int x,int y)
{
	par[find(x)]=find(y);
}
struct edge
{
	int u,v,dist;
	bool operator<(const edge & ob)const
	{
		return dist<ob.dist;
	}
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,k;cin>>n>>k;
	for(int i=0;i<k;++i)
	{
		int x;cin>>x;
		sp[x]=1;
	}
	int tot=(n*n-n)/2;
	vector<edge>ed(tot);
	int in=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			int x;
			cin>>x;
			if(i<=j)continue;
			edge ob;
			ob.u=i;ob.v=j;ob.dist=x;
			ed[in++]=ob;
		}
	}
	sort(all(ed));
	for(int i=0;i<150;++i)
		par[i]=i;
	ll ans=0;
	for(auto e:ed)
	{
		int u=e.u,v=e.v;
		bool x1=sp[find(u)],y1=sp[find(v)];
		if(x1^y1)
		{
			ans+=e.dist;
			merge(u,v);
			sp[u]=1;sp[v]=1;
			sp[find(u)]=1;sp[find(v)]=1;
		}
		else if((!x1)&&(!y1))
		{
			ans+=e.dist;
			merge(u,v);
			if(sp[find(u)])
			{
				sp[u]=1;sp[v]=1;
			}
		}
	}
	cout<<ans<<'\n';
}
















