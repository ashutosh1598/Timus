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
struct se
{
    int l,r,i;
    se(int x,int y,int z)
    {
        l=x;r=y;z=i;
    }
    bool operator<(const se & ob)
    {
        return r==ob.r?l<ob.l:r<ob.r;
    }
}
typedef pair<ll,ll> pll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<seg>re(n);
    for(int i=0;i<n;++i)
    {
        int l,r;
        cin>>l>>r;
        re[i]=se(l,r,i);
    }
    sort(all(re));

}







