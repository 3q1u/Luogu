#include <bits/stdc++.h>
using namespace std;

int rd()
{
    int s=0,f=1;char ch=getchar();
    while(!isdigit(ch)) {if(ch=='-') f=-1;ch=getchar();}
    while(isdigit(ch)) {s=(s<<3)+(s<<1)+(ch^48);ch=getchar();}
    return s*f;
}

const int N=1e5+5,M=5*1e5+10,INF=0x3f3f3f3f;
int dp[N],c[N];
int head[N],nxt[M],to[M],cnt=0;
int minv[N];

void add(int u,int v)
{
    nxt[++cnt] = head[u];
    to[cnt] = v;
    head[u] = cnt;
}

void dfs(int ver,int curm,int pre)
{
    bool f=0;
    curm=curm<c[ver]?curm:c[ver];
    if(minv[ver]>curm) minv[ver]=curm,f=1;
    int maxi=dp[pre]<c[ver]-curm?c[ver]-curm:dp[pre];
    if(dp[ver]<maxi) dp[ver]=maxi,f=1;
    if(!f) return ;
    for(int i=head[ver];i;i=nxt[i])
        dfs(to[i],curm,ver);
}

int main()
{
    memset(minv,0x3f,sizeof(minv));
    int n=rd(),m=rd();
    for(int i=1;i<=n;i++) c[i]=rd();
    for(int i=1;i<=m;i++)
    {
        int t1=rd(),t2=rd(),t3=rd();
        add(t1,t2);
        if(t3 == 2) add(t2,t1);
    }

    dfs(1,INF,0);
    printf("%d",dp[n]);
    return 0;
}