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
ll shif=32000+10;
const int maxn=32000*2+200;
ll edif1[maxn];
ll vdif1[maxn];
ll edif2[maxn];
ll vdif2[maxn];
ll eans[maxn];
ll vans[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    while(n--)
    {
        int a,b,y;
        cin>>a>>b>>y;
        edif1[a+shif]++;
        edif1[b+shif]--;
        vdif1[a+shif]+=y;
        vdif1[b+shif]-=y;
    }
    cin>>n;
    while(n--)
    {
        int a,b,y;
        cin>>a>>b>>y;
        edif2[a+shif]++;
        edif2[b+shif]--;
        vdif2[a+shif]+=y;
        vdif2[b+shif]-=y;
    }
    for(int i=1;i<maxn;++i)
    {
        edif1[i]+=edif1[i-1];
        vdif1[i]+=vdif1[i-1];
        edif2[i]+=edif2[i-1];
        vdif2[i]+=vdif2[i-1];
    }
    for(int i=0;i<maxn;++i)
    {
        if(edif1[i]&&!edif2[i])
        {
            vans[i]=vdif1[i];
            eans[i]=1;
        }
    }
    int lef=-1e5;
    vector<pair<pii,int> >an;
    for(int i=1;i<maxn;++i)
    {
        if(   (eans[i]==0&&eans[i-1]==1)||(eans[i]==1&&eans[i-1]==1&&vans[i]!=vans[i-1])  )
        {
            if(lef!=-1e5)
            {
                an.pb(mp( mp(lef-shif,i-shif),vans[i-1] ) );
            }
        }
        if( (eans[i]==1&&eans[i-1]==0)||(eans[i]==1&&eans[i]==1&&vans[i]!=vans[i-1]))
        {
            lef=i;
        }
    }
    cout<<an.size()<<' ';
    for(auto x:an)
    {
        cout<<x.ff.ff<<' '<<x.ff.ss<<' '<<x.ss<<' ';
    }
    cout<<'\n';
    return 0;
}
/*
   3 -1 1 2 1 3 4 4 6 3
   2 -2 2 1 5 7 5
   2 3 3 4 3 4 3 
*/











