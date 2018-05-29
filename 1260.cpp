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
    int n;
    cin>>n;
    ll a=1,b=1,c=2;
    if(n<=2)
    {
        cout<<"1\n";
        return 0;
    }
    for(int i=4;i<=n;++i)
    {
        ll t=a;
        a=b;
        b=c;
        c+=t+1;
    }
    cout<<c<<'\n';
}
