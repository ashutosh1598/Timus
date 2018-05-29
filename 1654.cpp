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
using namespace std;
typedef long long ll;
void push(list<char>&my,char ch)
{
    if(my.empty())
    {
        my.push_back(ch);
    }
    else
    {
        if(*(--my.end())==ch)
        {
            my.pop_back();
        }
        else my.push_back(ch);
    }
}
bool solve(string &x)
{
    list<char>my;
    int n=x.length();
    for(int i=0;i<n;++i)
    {
        push(my,x[i]);
    }
    string y(my.begin(),my.end());
    x=y;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string x;cin>>x;
    solve(x);
    cout<<x<<'\n';
}
