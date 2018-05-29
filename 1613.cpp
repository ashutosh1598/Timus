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
struct ci
{
    int po,pos;
    bool operator<(const ci & ob)const
    {
        return (po==ob.po?pos<ob.pos:po<ob.po);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    vector<ci>rec(n);
    for(int i=0;i<n;++i)
    {
        ci ob;
        cin>>ob.po;
        ob.pos=i+1;
        rec[i]=ob;
    }
    sort(rec.begin(),rec.end());
    int q;cin>>q;
    list<char>my;
    while(q--)
    {
        int l,r,x;cin>>l>>r>>x;
        ci ob;
        ob.po=x;
        ob.pos=l;
        int posn=lower_bound(rec.begin(),rec.end(),ob)-rec.begin();
        if(posn<n&&rec[posn].po==x&&rec[posn].pos<=r)
        {
            my.push_back('1');
        }
        else my.push_back('0');
    }
    string ans(my.begin(),my.end());
    cout<<ans<<'\n';
}
