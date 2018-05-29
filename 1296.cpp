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
    ll glo=0,her=0;
    int n;cin>>n;
    for(int i=0;i<n;++i)
    {
        ll x;cin>>x;
        her=max(her+x,x);
        if(her<0)
            her=0;
        glo=max(glo,her);
    }
    cout<<glo<<'\n';
}
