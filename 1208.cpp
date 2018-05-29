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
vector<string>r[20];
int comp[20][20],n;
void in()
{
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            int co=1;
            if(j==i)continue;
            for(int k=0;k<3;++k)
            {
                for(int p=0;p<3;++p)
                {
                    if(r[i][k]==r[j][p])
                    {
                        co=0;
                        break;
                    }
                }
                if(co==0)break;
            }
            if(co==1)
            {
                comp[i][j]=1;
                comp[j][i]=1;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;++i)
    {
        string x,y,z;
        cin>>x>>y>>z;
        r[i].pb(x);
        r[i].pb(y);
        r[i].pb(z);
    }
    in();
    int up=(1<<n)-1;
    int ans=-1;
    for(int m=1;m<=up;++m)
    {
        int co=1;
        for(int i=0;i<n;++i)
        {
            if(  (m&(  1<<i))==0)continue;
            for(int j=0;j<n;++j)
            {
                if(j==i)continue;
                if( (m&(1<<j))==0)continue;
                if(comp[i][j]==0)
                {
                    co=0;
                    break;
                }
            }
            if(co==0)break;
        }
        if(co)ans=max(ans,__builtin_popcount(m));
    }
    cout<<ans<<'\n';
}
