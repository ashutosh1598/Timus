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
int a[5][5];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	for(int i=0;i<4;++i)
	{
		for(int j=0;j<4;++j)
		{
			char ch;
			cin>>ch;
			if(ch=='X')
			{
				a[i][j]=1;
				a[j][3-i]=2;
				a[3-i][3-j]=3;
				a[3-j][i]=4;
			}
		}
	}
	vector<string>r(5);
	for(int i=0;i<4;++i)cin>>r[i];
	list<char>my;
	for(int n=1;n<=4;++n)
	{
		for(int i=0;i<4;++i)
		{
			for(int j=0;j<4;++j)
			{
				if(a[i][j]==n)
				{
					my.pb(r[i][j]);
				}
			}
		}
	}
	cout<<string(all(my))<<'\n';
}





