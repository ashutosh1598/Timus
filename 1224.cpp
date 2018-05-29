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
ll solve(ll n,ll m)
{
	if(n==1)
		return 0;
	if(m==1)
		return 1;
	if(n==2)
	{
		return 2;
	}
	if(m==2)
	{
		return 3;
	}
	else
	{
		return 4+solve(n-2,m-2);
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n,m;
	cin>>n>>m;
	if(n==1||m==1)
	{
		if(n!=1)
		{
			cout<<"1\n";
		}
		else
			cout<<"0\n";
		return 0;
	}
	ll k=min((n-1)/2,(m-1)/2);
	n-=2*k;
	m-=2*k;
	cout<<4*k+solve(n,m)<<'\n';
}
