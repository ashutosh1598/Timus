#include"iomanip"
#include <inttypes.h>
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
const int maxn=1e4+10;
ll dist[2*maxn];
list<pll>adj[2*maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int sh=n;
    for(int i=0;i<m;++i)
    {
        ll x,y,d;
        string s;
        cin>>x>>y>>d>>s;
        if(s[0]=='L')
        {
            adj[x].pb(mp(y,d));
        }
        else if(s[0]=='P')
        {
            adj[x].pb(mp(y+sh,d));
            adj[x+sh].pb(mp(y+sh,d));
        }
        else if(s[0]=='C')
        {
            adj[x].pb(mp(y,d));
            adj[x+sh].pb(mp(y+sh,d));
        }
    }
    for(int i=0;i<2*maxn;++i)
    {
        dist[i]=1e15;
    }
    dist[1]=0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > pq;
    pq.push(mp(0,1));
    while(!pq.empty())
    {
        auto xx=pq.top();
        pq.pop();
        if(dist[xx.ss]!=xx.ff)
        {
            continue;
        }
        for(auto yy:adj[xx.ss])
        {
            if(xx.ff+yy.ss<dist[yy.ff])
            {
                dist[yy.ff]=xx.ff+yy.ss;
                pq.push(mp(dist[yy.ff],yy.ff));
            }
        }
    }
    ll ans=min(dist[n],dist[2*n]);
    if(ans>1e12)
    {
        cout<<"Offline\n";
    }
    else
    {
        cout<<"Online\n"<<ans<<'\n';
    }
}



















