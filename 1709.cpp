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
int par[200];
vector<string>adj;
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
	int n;
	cin>>n;
	int d,a;
	cin>>d>>a;
	adj.resize(n);
	for(int i=0;i<n;++i)
		cin>>adj[i];
	for(int i=0;i<200;++i)
		par[i]=i;
	ll ans=0;
	for(int i=0;i<n;++i)
	{
		for(int j=i+1;j<n;++j)
		{
			if(adj[i][j]=='1')
			{
				if(find(i)==find(j))
				{
					adj[i][j]='d';
					adj[j][i]='d';
					ans+=d;
				}
				else merge(i,j);
			}
		}
	}
	for(int i=0;i<n;++i)
	{
		for(int j=i+1;j<n;++j)
		{
			if(adj[i][j]=='0')
			{
				if(find(i)!=find(j))
				{
					adj[i][j]='a';
					adj[j][i]='a';
					ans+=a;
					merge(i,j);
				}
			}
		}
	}
	cout<<ans<<'\n';
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(adj[i][j]!='1')
				cout<<adj[i][j];
			else cout<<'0';
		}
		cout<<'\n';
	}
}









