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
    int n;
    cin>>n;
    pq<int,vector<int>,greater<int> >mih;
    pq<int>mah;
    int currm;
    cin>>currm;
	if(n==1)
	{
		cout<<currm<<'\n';
		return 0;
	}
    //mah.push(currm);
    cout<<fixed<<setprecision(1);
    cout<<(ld)currm<<'\n';
    int tot=1;
    for(int i=1;i<n;++i)
    {
	int x;
	cin>>x;
	double ans=0;
	if(tot%2)
	{
	    if(x<=currm)
	    {
		mah.push(x);
		ans=((double)currm+mah.top() )/2+    (double)mah.top()/2;
		//currm=currm;
	    }
	    else
	    {
		mih.push(x);
		mah.push(currm);
		currm=mih.top();
		mih.pop();
		ans=((double)currm-mah.top() )/2;+  (double)mah.top()/2;
	    }
	}
	else
	{
	    if(x<=currm)
	    {
		mah.push(x);
		mih.push(currm);
		currm=mah.top();mah.pop();
		ans=(ld)currm;
	    }
	    else
	    {
		mih.push(x);
		ans=(ld)currm;
	    }
	}
	if(i==n-1)
		cout<<ans<<'\n';
	tot++;
    }
}
