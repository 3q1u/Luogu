#include <map>
#include <iostream>
using namespace std;

map<int,int> f;

inline int find(int p){
    return p == f[p]?f[p]:p=find(f[p]);
}

inline void merge(int p,int q){
    f[find(p)] = find(q);
}

inline bool same(int p,int q){
    return find(p)==find(q);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,p,q;
    int male=0,female=0;
    cin>>n>>m>>p>>q;
    for(int i=-1*m;i<=n;i++)
        f[i] = i;
    for(int i=1;i<=p+q;i++){
        int x,y;
        cin>>x>>y;
        merge(x,y);
    }
    for(int i=1;i<=n;i++)
        if(same(f[i],1)) male++;
    for(int i=-1*m;i<=-1;i++)
        if(same(f[i],-1)) female++;
    cout<<min(male,female);
    return 0;
}