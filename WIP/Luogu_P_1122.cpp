#include <bits/stdc++.h>
#include <limits>
using namespace std;
const int N=16010;
int head[N],nxt[2*N],to[2*N],cnt=0;
int a[N],n,f[N],ans=numeric_limits<int>::min();
inline void __add(const int& u,const int& v)
{
    nxt[++cnt]=head[u];
    to[cnt] = v;
    head[u] = cnt;
}
inline void add(const int& u,const int& v)
{
    __add(u,v);
    __add(v,u);
}
void dfs(int cur,int fa)
{
    f[cur] = a[cur];
    for(int i=head[cur];i;i=nxt[i])
    {
        if(to[i] != fa)
        {
            dfs(to[i],cur);
            if(f[to[i]] > 0)
                f[cur] += f[to[i]];
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        add(u,v);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
        ans = max(ans,f[i]);
    printf("%d",ans);
    return 0;
}