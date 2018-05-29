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
map<string,set<string> >my;
void add(string x,string y,string z)
{

    my[x].insert(y);
    my[x].insert(z);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    for(int i=0;i<n;++i)
    {
        string x,y,z;cin>>x>>y>>z;
        add(x,y,z);
        add(y,z,x);
        add(z,x,y);
    }
    map<string,int> ans;
    queue<string> qq;
    for(auto it=my.begin();it!=my.end();++it)
    {
        if(it->first=="Isenbaev")
        {
            qq.push("Isenbaev");
            ans["Isenbaev"]=0;
            break;
        }
    }
    int no=1;
    while(!qq.empty())
    {
        string xx=qq.front();qq.pop();
        if(ans[xx]==no)
            no++;
        for(auto it=my[xx].begin();it!=my[xx].end();it++)
        {
            if(ans.find(*it)==ans.end())
            {
                ans[*it]=no;
                qq.push(*it);
            }
        }
    }
    for(auto it=my.begin();it!=my.end();++it)
    {
        if(ans.find(it->first)==ans.end())
        {
            ans[it->first]=-1;
        }
    }
    for(auto it=ans.begin();it!=ans.end();++it)
    {
        int x=it->second;
        if(x!=-1)
            cout<<it->first<<' '<<x<<'\n';
        else cout<<it->first<<" undefined\n";
    }
}
