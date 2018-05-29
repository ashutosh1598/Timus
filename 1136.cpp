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
int a[3100];
void solve(int i,int j)
{
	if(i>j)return;
	if(i==j)
	{
		cout<<a[i]<<'\n';
		return;
	}
	int root=a[j];
	for(int k=i;k<=j;++k)
	{
		if(a[k]>=a[j])
		{
			solve(k,j-1);
			solve(i,k-1);
			cout<<root<<'\n';
			return;
		}
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	solve(0,n-1);
}
