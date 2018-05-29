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
string x;int n;
bool solve(int m,string&temp)
{
    if(n>=1&&m<=1)
    {
        temp="";temp.push_back(x[0]);
        return 1;
    }
    for(int i=0;i<n-m+1;++i)
    {
        bool b=true;
        for(int j=i;j<i+m/2;++j)
        {
            if(x[j]!=x[i+m-1-(j-i)])
            {
                b=false;
                break;
            }
        }
        if(b)
        {
            temp=x.substr(i,m);
            return true;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>x;
    n=x.length();
    int l=0,h=n;
    string ans;
    while(l<h-1)
    {
        int m=(l+h)/2;
        if(solve(m,ans)||solve(m+1,ans))
        {
            l=m;
        }
        else
        {
            h=m;
        }
    }
    if(solve(h,ans))
    {
        cout<<ans<<'\n';
    }
    else
    {
        solve(l,ans);
        cout<<ans<<'\n';
    }
}

