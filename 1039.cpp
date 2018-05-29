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
const int maxn=6005;
int d1[maxn],d2[maxn],ra[maxn];
list<int>adj[maxn];
void dfs(int v)
{
    d1[v]=ra[v];
    d2[v]=0;
    for(int ver:adj[v])
    {
        dfs(ver);
        d1[v]+=d2[ver];
        d2[v]+=max(d1[ver],d2[ver]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>ra[i];
    }
    int x,y;
    set<int>r;for(int i=1;i<=n;++i)r.insert(i);
    for(int i=0;i<n-1;++i)
    {
        cin>>x>>y;
        adj[y].pb(x);
        r.erase(x);
    }
    cin>>x>>y;
    int root=*r.begin();
    dfs(root);
    cout<<max(d1[root],d2[root])<<'\n';
}
