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
int ma[200];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	for(char c:{'A','P','O','R'})
	{
		ma[c-'A']=1;
	}
	for(char c:{'B','M','S'})
	{
		ma[c-'A']=2;
	}
	for(char c:{'D','G','J','K','T','W'})
	{
		ma[c-'A']=3;
	}
	int n;
	cin>>n;
	int st=1;
	int ans=0;
	for(int i=0;i<n;++i)
	{
		string x;
		cin>>x;
		char c=x[0];
		int nest=ma[c-'A'];
		ans+=abs(nest-st);
		st=nest;
	}
	cout<<ans<<'\n';
}












