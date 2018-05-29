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
const int maxn=50000+5;
list<pii>adj[maxn];
int tou[maxn],froo[maxn],st[maxn],fi[maxn],ti=0;
int anc[maxn][17];
int n;
void df(int u,int len,int p=-1)
{
    st[u]=ti++;
    froo[u]=len;
    tou[u]=1;
    for(pii xx:adj[u])
    {
        if(xx.ff==p)continue;
        anc[xx.ff][0]=u;
        df(xx.ff,len+xx.ss,u);
    }
    fi[u]=ti++;
}
int che(int u,int v)//u is ancestor of v
{
    if(st[u]<=st[v]&&fi[v]<=fi[u])return 1;
    return 0;
}
void build()
{
    for(int i=1;i<=16;++i)
    {
        for(int u=0;u<n;++u)
        {
            anc[u][i]=anc[   anc[u][i-1] ]   [i-1];
        }
    }
}
int lca(int u,int v)
{
    if(che(u,v))return u;
    if(che(v,u))return v;
    for(int i=16;i>=0;--i)
    {
        if(!che(anc[u][i],v))
        {
            u=anc[u][i];
        }
    }
    return anc[u][0]; 
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n-1;++i)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].pb(mp(v,w));
        adj[v].pb(mp(u,w));
    }
    df(0,0);
    anc[0][0]=0;
    build();
    int m;
    cin>>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        cout<<froo[u]+froo[v]-2*froo[lca(u,v)]<<'\n';
    }
}
















