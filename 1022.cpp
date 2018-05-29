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
int in[150];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;
	vector<list<int> >adj(n+1);
	for(int i=1;i<=n;++i)
	{
		int x;
		cin>>x;
		while(x!=0)
		{
			adj[i].pb(x);
			++in[x];
			cin>>x;
		}
	}
	queue<int>qq;
	for(int i=1;i<=n;++i)
	{
		if(in[i]==0)
		{
			qq.push(i);
		}
	}
	while(!qq.empty())
	{
		int u=qq.front();
		cout<<u<<' ';
		qq.pop();
		for(int v:adj[u])
		{
			in[v]--;
			if(in[v]==0)
			{
				qq.push(v);
			}
		}
	}
	cout<<'\n';
}

















