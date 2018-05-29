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
int dp[11][100];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s;cin>>s;
    for(int i=0;i<100;++i)
    {
        dp[1][i]=(i<=9?1:0);
    }
    for(int i=2;i<=9;++i)
    {
        for(int s=0;s<=85;++s)
        {
            for(int k=1;k<=9;++k)
            {
                dp[i][s]+=dp[i-1][s-k];
            }
            dp[i][s]+=dp[i-1][s];
        }
    }
    if(s==1)dp[9][s]++;
    cout<<dp[9][s]<<'\n';
}
