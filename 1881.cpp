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
#include"assert.h"
using namespace std;
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define mp make_pair
#define pb push_back
#define mset(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h,w,n;
    cin>>h>>w>>n;
    int cl=1;
    int cw=1;
    for(int i=0;i<n;++i)
    {
        string x;
        cin>>x;
        int p=x.length();
        if(cw+p-1>w)
        {
            cw=1;
            cl++;
        }
        if(cw+p-1<=w)
        {
            cw=cw+p+1;
            if(cw>w)
            {
                cw=1;
                cl++;
            }
        }
    }
    if(cw==1)cl--;
    cout<<(cl+h-1)/h<<'\n';
}
