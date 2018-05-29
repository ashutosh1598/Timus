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
const int maxn=1e5+5;
int rec[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b;cin>>a>>b;
    int n=b-a+1;
    for(int i=0;i<n;++i)
    {
        cin>>rec[i];
    }
    int cur=0,prev=rec[0];
    int ans=0;
    for(int i=1;i<n;++i)
    {
        int x=rec[i];
        if(cur==0)
        {
            if(x>prev)
            {
                cur=1;
                prev=x;
            }
            else if(x<prev)
            {
                cur=2;
                prev=x;
            }
        }
        else if(cur==1)
        {
            if(x>prev)
            {
                prev=x;
            }
            else if(x<prev)
            {
                ++ans;
                cur=0;
                prev=x;
            }
        }
        else if(cur==2)
        {
            if(x<prev)
            {
                prev=x;
            }
            else if(x>prev)
            {
                ++ans;
                cur=0;
                prev=x;
            }
        }
    }
    cout<<ans+1<<'\n';
}
















