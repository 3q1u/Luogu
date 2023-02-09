#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=5*N;

int x[M],y[M],n,m;

int head[N],nxt[M],to[M],cnt;
void add(int u,int v) {
    nxt[++cnt] = head[u];
    to[cnt] = v;
    head[u] = cnt;
}

int dfn[N],low[N],stk[N],c[N],num[N],scc,siz,top; bool vis[N];
void tarjan(int u) {
    dfn[u]=low[u]=++siz;
    vis[u] = 1;
    stk[++top] = u;

    for(int i=head[u];i;i=nxt[i]) {
        int v = to[i];
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else if(vis[v])
            low[u] = min(low[u],low[v]);
    }

    if(dfn[u] == low[u]) {
        scc++;
        while(stk[top+1] != u) {
            int w = stk[top--];
            num[scc]++;
            c[w] = scc;
            vis[w] = 0;
        }
    }
}

int main() {
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++) {
        scanf("%d %d",&x[i],&y[i]);
        add(x[i],y[i]);
    }

    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);

    int ans=0;
    for(int i=1;i<=scc;i++) {
        if(num[i] > 1)
            ans++;
    }
    printf("%d",ans);
    return 0;
}