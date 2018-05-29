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
	int m=0,e=0,l=0;
	map<string,int>my;
	for(int i=0;i<n;++i)
	{
		string x,y;
		cin>>x>>y;
		my[x]++;
		if(x[0]=='E')
			e++;
		if(x[0]=='M')
			m++;
		if(x[0]=='L')
			l++;
	}
	/*
	if(e>m&&e>l)cout<<"Emperor";
	if(m>e&&m>l)cout<<"Macaroni";
	if(l>m&&l>e)cout<<"Little";
	cout<<" Penguin\n";
	return 0;
	*/
	string y="";
	int ans=0;
	for(auto x:my)
	{
		if((x.ss)>ans)
		{
			ans=x.ss;
			y=x.ff;
		}
	}
	cout<<y<<" Penguin\n";
}
