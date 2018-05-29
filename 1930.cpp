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
bool touch[maxn],u[maxn],d[maxn];
ll dist[maxn];
vector<list<int> >up,down;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,m;cin>>n>>m;
	up.resize(n+1);down.resize(n+1);
	for(int i=0;i<m;++i)
	{
		int x,y;cin>>x>>y;
		up[x].pb(y);
		down[y].pb(x);
	}
	int st,fin;
	cin>>st>>fin;
	for(int i=0;i<maxn;++i)
	{
		dist[i]=1e10;
	}
	dist[st]=0;
	u[st]=1;d[st]=1;
	queue<int>qq;
	qq.push(st);
	while(!qq.empty())
	{
		int vert=qq.front();
		qq.pop();
		touch[vert]=1;
		for(int v:up[vert])
		{
			
		}
	}
}












