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
using namespace std;
typedef  long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;cin>>n>>k;
    ll a=k-1,b=0;
    for(ll i=2;i<=n;++i)
    {
        ll t=b;
        b=a;
        a=(a+t)*(k-1);
    }
    cout<<a+b<<'\n';
}
