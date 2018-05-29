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
string x,y;
string fl()
{
    string z="aaaa";
    z[0]=y[1];
    z[1]=y[3];
    z[2]=y[2];
    z[3]=y[0];
    return z;
}
string fr()
{
    string z="aaaa";
    z[0]=y[2];
    z[1]=y[1];
    z[2]=y[3];
    z[3]=y[0];
    return z;
}
string b()
{
    string z="aaaa";
    z[0]=y[3];
    z[1]=y[2];
    z[2]=y[1];
    z[3]=y[0];
    return z;
}
int check()
{
    if(x[0]!=y[0])return 0;
    int i=0;
    string temp=y;
    while(1)
    {
        string z="aaaa";
        z[0]=temp[0];
        z[1]=temp[2];
        z[2]=temp[3];
        z[3]=temp[1];
        temp=z;
        if(x==temp)return 1;
        i++;
        if(i>6)return 0;
    }
    return 0;
}
void ca()
{
    if(check())
    {
        puts("equal");
        exit(0);
    }
}
int main()
{
    string temp;
    cin>>x>>y;
    ca();
    temp=y;
    y=fl();ca();y=temp;
    y=fr();ca();y=temp;
    y=b();ca();y=temp;
    puts("different");
}
