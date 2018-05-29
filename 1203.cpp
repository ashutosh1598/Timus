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
const ll maxn=1e5+10;
pair<ll,ll>rec[maxn];
ll dp[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>rec[i].first>>rec[i].second;
    }
    sort(rec,rec+n);
    ll ans=0;
    for(int i=n-1;i>=0;--i)
    {
        dp[i]=1;
        pair<ll,ll> temp=make_pair(rec[i].second+1,-1e15);
        int posn=lower_bound(rec,rec+n,temp)-rec;
        if(posn<n)
        {
            dp[i]+=dp[posn];
        }
        //cout<<i<<' '<<dp[i]<<" i dp[i]\n";
        if(i+1<n)dp[i]=max(dp[i],dp[i+1]);
        ans=max(ans,dp[i]);
    }
    cout<<ans<<'\n';
}
