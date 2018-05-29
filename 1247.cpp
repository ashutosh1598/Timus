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
int r[100000];
int main()
{
    int s,n;
    scanf("%d%d",&s,&n);
    vector<int>d(s+1,0);
    for(int i=1;i<=s;++i)scanf("%d",r+i);
    for(int i=1;i<=s;++i)d[i]+=r[i]+d[i-1];
    for(int i=1;i<=s;++i)d[i]-=i;
    int ok=1;
    int cur=d[s]-n;
    for(int i=s-1;i>=0;--i)
    {
        if(d[i]<cur)ok=0;
        cur=max(cur,d[i]-n);
    }
    puts(ok?"YES":"NO");
}
