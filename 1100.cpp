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
struct ch
{
    int id,m;
    bool operator<(const ch & ob)const
    {
        return m>ob.m;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    vector<ch>rec(n);
    for(int i=0;i<n;++i) {
        int x, y;
        cin >> x >> y;
        ch ob;
        ob.id = x;
        ob.m = y;
        rec[i] = ob;
    }
    stable_sort(rec.begin(),rec.end());
    for(int i=0;i<n;++i) {
        cout << rec[i].id << ' ' << rec[i].m << '\n';
    }
}
