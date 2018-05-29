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
int a[1100];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	int sum=-1,mid=-1;
	for(int i=0;i+2<n;++i)
	{
		int tt=a[i]+a[i+1]+a[i+2];
		if(tt>sum)
		{
			sum=tt;
			mid=i+1+1;
		}
	}
	cout<<sum<<' '<<mid<<'\n';
}
