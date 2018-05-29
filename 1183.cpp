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
int arr[1000000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string x;
	cin>>x;
	int n=x.length();
	int sq=0,cu=0;
	list<char>ans;
	stack<pair<char,int> >st1,st2;
	for(int i=0;i<n;++i)
	{
		if(x[i]=='(')
		{
			cu++;
			st1.push(mp(x[i],i));
		}
		else if(x[i]==')')
		{
			while(sq>0)
			{
				sq--;
				ans.pb(']');
				st2.pop();
			}
			cu--;
			if(!st1.empty())
				st1.pop();
		}
		else if(x[i]=='[')
		{
			sq++;
			st2.push(mp(x[i],i));
		}
		else
		{
			while(cu>0)
			{
				cu--;
				ans.pb(')');
				st1.pop();
			}
			sq--;
			if(!st2.empty())
			st2.pop();
		}
		if(sq<0)
		{
			sq++;
			ans.pb('[');
		}
		if(cu<0)
		{
			cu++;
			ans.pb('(');
		}
		ans.pb(x[i]);
	}

	while(!st1.empty())
	{
		/*
		if(st.top()=='(')ans.pb(')');
		if(st.top()=='[')ans.pb(']');
		*/
		arr[st1.top().ss]=1;
		st1.pop();
	}
	while(!st2.empty())
	{
		/*
		if(st.top()=='(')ans.pb(')');
		if(st.top()=='[')ans.pb(']');
		*/
		arr[st2.top().ss]=1;
		st2.pop();
	}
	for(int i=1000000-1;i>=0;--i)
	{
		if(arr[i]==2)
		{
			ans.pb(']');
		}
		else if(arr[i]==1)
		{
			ans.pb(')');
		}
	}
	
	/*
	while(sq>0)
	{
		ans.pb(']');
		sq--;
	}
	while(cu>0)
	{
		ans.pb(')');
		cu--;
	}
	*/
	cout<<string(all(ans))<<'\n';
}















