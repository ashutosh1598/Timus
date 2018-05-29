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
const int maxn=25005;
int rec[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;cin>>m;
    multiset<int>my;
    for(int i=0;i<m;++i)
    {
        int x;cin>>x;
        rec[i]=x;
        my.insert(x);
    }
    for(int i=m;;++i)
    {
        cout<<*(--my.end())<<'\n';
        auto it=my.find(rec[i-m]);
        my.erase(it);
        int x;cin>>x;
        if(x==-1)
            break;
        rec[i]=x;
        my.insert(x);
    }
}
