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
const ll mo=1e9+7;
ll dp1[50002],dp2[50002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a,b;cin>>n>>a>>b;
    dp1[1]=1;
    dp2[1]=1;
    dp1[0]=1;
    dp2[0]=1;
    for(int i=2;i<=n;++i)
    {
        dp1[i]=dp1[i-1]+dp2[i-1];
        dp2[i]=dp1[i-1]+dp2[i-1];
        if(i>a)
        {
            dp1[i]-=dp2[i-a-1];
        }
        if(i>b)
        {
            dp2[i]-=dp1[i-b-1];
        }
        dp1[i]=(dp1[i]%mo+mo)%mo;
        dp2[i]=(dp2[i]%mo+mo)%mo;
    }
    cout<<(dp1[n]+dp2[n])%mo<<'\n';
}
