#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string,string> f;

inline string find(string p)
{
    return (f[p] == p)?p:f[p]=find(f[p]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k;
    cin>>n>>m;
    string tmp1,tmp2;
    for(auto i=1;i<=n;i++)
    {
        cin>>tmp1;
        f[tmp1] = tmp1;
    }
    for(auto i=1;i<=m;i++)
    {
        cin>>tmp1>>tmp2;
        tmp1 = find(tmp1);
        tmp2 = find(tmp2);
        if(tmp1 != tmp2) f[tmp1] = tmp2;
    }
    cin>>k;
    for(auto i=1;i<=k;i++)
    {
        cin>>tmp1>>tmp2;
        if(find(f[tmp1]) == find(f[tmp2])) cout<<"Yes.\n";
        else cout<<"No.\n";
    }
    return 0;
}