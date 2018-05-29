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
const int maxn=1e5+5;
ll rec[maxn];
bool tou[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    for(int i=1;i<=n;++i)
        cin>>rec[i];
    /*int prev=rec[1];
    tou[rec[1]]=1;
    for(int i=2;i<=n;++i)
    {
        int x=rec[i];
        if(x>prev)
        {
            prev=x;
            tou[x]=1;
        }
        else
        {
            for(int j=x+1;j<=prev;++j)
            {
                if(!tou[j])
                {
                    cout<<"Cheater\n";
                    return 0;
                }
            }
            tou[x]=1;
            prev=x;
        }
    }
    cout<<"Not a proof\n";*/
    stack<int>my;
    int i=1,f=1;
    for(f=1;f<=n;++f)
    {
        my.push(f);
        while(!my.empty()&&rec[i]==my.top())
        {
            my.pop();
            i++;
        }
    }
    if(my.empty())
    {
        cout<<"Not a proof\n";
    }
    else cout<<"Cheater\n";
}













