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
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    if(n==1||n==2)
    {
        cout<<"2\n";return 0;
    }
    ll a1=1,a2=1,b1=1,b2=1;
    for(int i=3;i<=n;++i)
    {
        ll x=b1+b2,y=a1+a2;
        a2=a1;b2=b1;
        a1=x;b1=y;
    }
    cout<<a1+b1<<'\n';
}
