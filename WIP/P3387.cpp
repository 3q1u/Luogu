#include <bits/stdc++.h>
#include <random>
#define gc() getchar()
using namespace std;

const int N=1e4+5,M=1e5+5;

int x[M],y[M],n,m; //V+E=G
struct {
    int operator ()() {
        int s=0,f=1;char ch=gc();
        while(!isdigit(ch)) {if(ch=='-') f=-1;ch=gc();}
        while(isdigit(ch)) {s=(s<<3)+(s<<1)+(ch^48);ch=gc();}
        return s*f;
    }
}read; //快读

int head[N],nxt[M],to[M],v[N],cnt; //链式前向星
void add(int u,int v) { 
    nxt[++cnt] = head[u];
    to[cnt] = v;
    head[u] = cnt;
} //建边

int dfn[N],low[N],_v[N],color[N],stk[N],top,siz,scc; bool vis[N]; //tarjan
void tarjan(int u) {
    dfn[u]=low[u]=++siz;
    vis[u] = 1;
    stk[++top]=u;

    for(int i=head[u];i;i=nxt[i]) { //更新low
        int v=to[i];
        if(!dfn[v]) {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v])
            low[u]=min(low[u],low[v]);
    }
    
    if(dfn[u]==low[u]) { //一个环
        ++scc;
        while(stk[top+1]!=u) {
            int w=stk[top--];
            color[w] = u;
            vis[w] = 0;
            _v[scc]+=v[w];
        }
    }
}

int indr[N],ord[N],f[N],ans=0; queue<int> q;//拓扑
void topo() { //顺带dp
    for(int i=1;i<=scc;i++)
        if(!indr[i]) //入度为0就进队
            q.push(i); 
    
    while(!q.empty()) {
        int u=q.front();q.pop();
        for(int i=head[u];i;i=nxt[i]) {
            int v=to[i];
            f[v]=max(f[v],f[u]+_v[v]);
            indr[v]--;
            if(!indr[v])
                q.push(v);
        }
    }
}

int main() {
    n=read(),m=read();
    for(int i=1;i<=n;i++)
        v[i] = read();
    for(int i=1;i<=m;i++) {
        x[i]=read(),y[i]=read();
        add(x[i],y[i]);
    } //输入

    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i); //缩点
    
    memset(head,0,sizeof(head));
    memset(nxt,0,sizeof(nxt));
    memset(to,0,sizeof(to));
    for(int i=1;i<=m;i++) {
        if(color[x[i]] != color[y[i]]) {
            add(color[x[i]],color[y[i]]);
            indr[color[y[i]]]++;
        }
    } //重新建边

    topo(); //拓扑+DP

    for(int i=1;i<=n;i++) //统计最大值
        ans=max(ans,f[i]);
    printf("%d",ans);

    return 0;
}