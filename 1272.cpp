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
const int maxn=10000+10;
int par[maxn];
int find(int x)
{
	return par[x]==x?x:par[x]=find(par[x]);
}
void merge(int x,int y)
{
	par[find(x)]=find(y);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,k,m;
	cin>>n>>k>>m;
	for(int i=0;i<maxn;++i)
		par[i]=i;
	for(int i=0;i<k;++i)
	{
		int x,y;
		cin>>x>>y;
		merge(x,y);
	}
	int ans=0;
	for(int i=0;i<m;++i)
	{
		int x,y;
		cin>>x>>y;
		if(find(x)!=find(y))
		{
			merge(x,y);
			ans++;
		}
	}
	cout<<ans<<'\n';
}
