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
	string x;
	cin>>x;
	string y=x.substr(0,x.length()-1);
	int len=y.length();
	int n;
	char c=x[x.length()-1];
	if(len==1)
		n=y[0]-'0';
	else
	{
		n=(y[1]-'0')+10*(y[0]-'0');
	}
	if(n<=2)
	{
		if(c=='A'||c=='D')
			cout<<"window\n";
		else cout<<"aisle\n";
		return 0;
	}
	if(n<=20)
	{
		if(c=='A'||c=='F')
			cout<<"window\n";
		else cout<<"aisle\n";
		return 0;
	}
	auto a=string::npos;
	string b="AK",d="BEFJ";
	if(b.find(c)!=a)
	{
		cout<<"window\n";
	}
	else if(d.find(c)!=a)
	{
		cout<<"neither\n";
	}
	else cout<<"aisle\n";
}
