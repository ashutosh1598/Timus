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
ll mm[40][40],pp[40];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<40;++i)
		for(int j=0;j<40;++j)
			mm[i][j]=1e15;
	mm[0][0]=0;
	pp[0]=1;
	for(int i=1;i<=n;++i)
	{
		int nop;
		cin>>nop;
		pp[i]=nop;
		for(int j=0;j<nop;++j)
		{
			while(1)
			{
				int x,y;
				cin>>x;
				if(x==0)break;
				cin>>y;
				mm[i][j]=min(mm[i][j],mm[i-1][x-1]+y);
			}
		}
		char ch;
		if(i<n)
		cin>>ch;
	}
	ll ans=1e16;
	for(int i=0;i<pp[n];++i)
	{
		ans=min(ans,mm[n][i]);
	}
	cout<<ans<<'\n';
}











