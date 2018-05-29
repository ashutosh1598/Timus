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
struct inte
{
    int l,r;
    bool operator<(const inte & ob)const
    {
        return l==ob.l?r<ob.r:l<ob.l;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    cin>>m;
    vector<inte>rec;
    inte fir;
    fir.r=-1e7;
    while(1)
    {
        int x,y;cin>>x>>y;
        if(x==0&&y==0)
            break;
        if(x<=0&&y>=0)
        {
            if(y>fir.r)
            {
                fir.l=x;
                fir.r=y;
            }
        }
        else if(! (x>m||y<0) )
        {
            inte ob;
            ob.l=x;ob.r=y;
            rec.push_back(ob);
        }
    }
    rec.resize(rec.size());
    sort(rec.begin(),rec.end());
    vector<inte>ans;
    int n=rec.size();
    if(fir.r>=m)
    {
        cout<<"1\n";
        cout<<fir.l<<' '<<fir.r<<'\n';
        return 0;
    }
    if(fir.r==-1e7)
    {
        cout<<"No solution\n";
        return 0;
    }
    int i=0;
    while(i<n)
    {
        inte ob=fir;
        inte temp;
        while(i<n)
        {
            temp=rec[i];
            if(temp.l<=fir.r)
            {
                if(temp.r>=ob.r)
                {
                    ob=temp;
                }
                ++i;
            }
            else 
            {
                  ++i;
                  break;
            }
        }
        ans.push_back(fir);
        if(fir.r>=m)
        {
            break;
        }
        fir=ob;
    }
    cout<<ans.size()<<'\n';
    for(auto x:ans)
    {
        cout<<x.l<<' '<<x.r<<'\n';
    }
}
