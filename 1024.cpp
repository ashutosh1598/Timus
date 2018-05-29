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
const int maxn=1000+10;
int p[maxn];
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int lcm(int a,int b)
{
    return a/gcd(a,b)*b;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",p+i);
    int ans=1;
    for(int i=1;i<=n;++i)
    {
        int k=1;
        int val=p[i];
        while(val!=i)
        {
            k++;
            val=p[val];
        }
        ans=lcm(ans,k);
    }
    cout<<ans<<'\n';
}
