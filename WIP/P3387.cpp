#include <bits/stdc++.h>
using namespace std;

const int N=1e4+5,M=1e5+5;
int w[N],_w[N],n,m;

int head[N],nxt[M],to[M],x[M],y[M],cnt;
void add(int u,int v) {
    nxt[++cnt] = head[u];
    to[cnt] = v;
    head[u] = cnt;
}

int dfn[N],low[N],stk[N],color[N],top,siz,scc; bool vis[N];
void tarjan(int u) {
    dfn[u]=low[u]=++siz;
    vis[u] = 1;
    stk[++top] = u;

    for(int i=head[u];i;i=nxt[i]) {
        int v=to[i];
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else if(vis[v]) {
            low[u] = min(low[u],low[v]);
        }
    }

    if(dfn[u] == low[u]) {
        scc++;
        while(stk[top+1] != u) {
            int v=stk[top--];
            _w[scc] += w[v];
            color[v] = scc;
            vis[v] = 0;
        }
    }
}

int in[N],f[N]; queue<int> q;
void topo() {
    for(int i=1;i<=scc;i++) {
        if(!in[i])
            q.push(i),
            f[i] = _w[i];
    }

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i=head[u];i;i=nxt[i]) {
            int v=to[i];
            f[u] = max(f[u],f[u]+_w[v]);
            if(!(--in[v]))
                q.push(v);
        }
    }
}

int main() {
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) 
        scanf("%d",&w[i]);
    for(int i=1;i<=m;i++) {
        scanf("%d %d",&x[i],&y[i]);
        add(x[i],y[i]);
    }

    for(int i=1;i<=n;i++) {
        if(!dfn[i])
            tarjan(i);
    }

    memset(head,0,sizeof(head));
    memset(nxt,0,sizeof(nxt));
    memset(to,0,sizeof(to));
    for(int i=1;i<=m;i++) {
        if(color[x[i]] != color[y[i]]) {
            add(color[x[i]],color[y[i]]);
            in[color[y[i]]]++;
        }
    }

    topo();
    int ans=0;
    for(int i=1;i<=scc;i++)
        ans = max(ans,f[i]);

    printf("%d",ans);
    return 0;
}