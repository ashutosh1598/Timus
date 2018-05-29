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
const int maxn=1e5+10;
int e1[maxn],e2[maxn],qu[maxn],rem[maxn],pa[maxn],ans[maxn];
int find(int x){return pa[x]==x?x:pa[x]=find(pa[x]);}
void merge(int x,int y){pa[find(x)]=find(y);}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<maxn;++i)pa[i]=i;
    for(int i=1;i<=m;++i)cin>>e1[i]>>e2[i];
    int q;
    cin>>q;
    for(int i=1;i<=q;++i)
    {
        cin>>qu[i];
        rem[qu[i]]=1;
    }
    int an=n;
    for(int i=1;i<=m;++i)
    {
        if(!rem[i])
        {
            if(find(e1[i])!=find(e2[i]))
            {
                merge(e1[i],e2[i]);
                an--;
            }
        }
    }
    for(int i=q;i>=1;--i)
    {
        ans[i]=an;
        if(find(e1[qu[i]])!=find(e2[qu[i]]))
        {
            merge(e1[qu[i]],e2[qu[i]]);
            an--;
        }
    }
    for(int i=1;i<=q;++i)
    {
        if(i-1)cout<<' ';
        cout<<ans[i];
    }
    cout<<'\n';
}







