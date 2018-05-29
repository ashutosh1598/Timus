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
int g[155];
int main()
{
    int x;
    scanf("%d",&x);
    int n=149;
    mset(g,-1);
    g[0]=0;
    g[1]=1;
    g[2]=1;
    g[3]=2;
    for(int i=4;i<=n;++i)
    {
        set<int>my;
        my.insert(g[i-2]);
        for(int j=2;j<i;++j)
        {
            my.insert(g[j-2]^g[i-1-j]);
        }
        int f=0;
        while(my.find(f)!=my.end())++f;
        g[i]=f;
    }/*
    for(int i=0;i<=n;++i)
    {
        cout<<i<<' '<<(g[i])<<'\n';
    }*/
    if(x<=149)
    {
        puts(g[x]>0?"White":"Black");
    }
    else
    {
        int by=(x-100)/34;
        x-=by*34;
        puts(g[x]>0?"White":"Black");       
    }
}






