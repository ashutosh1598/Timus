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
const int maxn=1e3+10;
int din[maxn],dout[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;cin>>n>>m;
    vector< list<int> >rec(n);
    for(int i=0;i<m;++i)
    {
        int x,y;cin>>x>>y;
        x--;y--;
        din[y]++;dout[x]++;
        rec[x].push_back(y);
    }
    vector<int>bb(n);
    for(int i=0;i<n;++i)
    {
        cin>>bb[i];
        bb[i]--;
    }
    for(int i=0;i<n;++i)
    {
        int v=bb[i];
        if(din[v]>0)
        {
            cout<<"NO\n";return 0;
        }
        else
        {
            for(auto it=rec[v].begin();it!=rec[v].end();++it)
            {
                din[*it]--;
            }
        }
    }
    cout<<"YES\n";
}
