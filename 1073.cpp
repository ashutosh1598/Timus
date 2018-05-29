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
static int dp[249][60005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    int up=sqrt(n);
    /*
    if(up*up==n)
    {
        cout<<"1\n";
        return 0;
    }
    set<int>my;
    for(int i=1;i<=up;++i)
    {
        for(int j=1;j<=up;++j)
        {
            my.insert(i*i+j*j);
        }
    }
    if(my.find(n)!=my.end())
    {
        cout<<"2\n";
        return 0;
    }
    for(int i=1;i<=up;++i)
    {
        if(my.find(n-i*i)!=my.end())
        {
            cout<<"3\n";
            return 0;
        }
    }
    cout<<"4\n";
    return 0;*/
    for(int i=1;i<60005;++i)
    {
        dp[up+1][i]=100;
    }
    dp[up+1][0]=0;
    for(int i=up;i>=1;--i)
    {
        dp[i][0]=0;
        for(int j=1;j<=n;++j)
        {
            dp[i][j]=dp[i+1][j];
            if(j>=i*i)dp[i][j]=min(1+dp[i][j-i*i],dp[i+1][j]);
            dp[i][j]=min(dp[i][j],dp[i+1][j]);
        }
    }
    cout<<dp[1][n]<<'\n';
}
