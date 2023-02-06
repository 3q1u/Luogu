#include <bits/stdc++.h>
// #define DEBUG
using namespace std;

const int N=2005;

int n;

int head[N],nxt[N],to[N],cnt; vector<pair<int,int>> e;
void add(int u,int v) {
    nxt[++cnt] = head[u];
    to[cnt] = v;
    head[u] = cnt;
}

int dfn[N],low[N],stk[N],color[N],f[N],scc,siz,top; bool vis[N];
void tarjan(int u) {
    dfn[u]=low[u]=++siz;
    vis[u] = 1;
    stk[++top] = u;

    for(int i=head[u];i;i=nxt[i]) {
        int v=to[i];
        if(!dfn[v]) {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v])
            low[u]=min(low[u],low[v]);
    }

    if(dfn[u] == low[u]) {
        scc++;
        while(stk[top+1] != u) {
            int w=stk[top--];
            f[scc]++;
            color[w] = scc;
            vis[w] = 0;
        }
    }
}

void dfs(int u) {
    vis[u] = 1;
    for(int i=head[u];i;i=nxt[i]) {
        int v=to[i];
        if(!vis[v])
            dfs(v);
        f[u] += f[v];
    }
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        string tmp;
        cin >> tmp;
        for(int j=0;j<tmp.size();j++) {
            if(tmp[j] == '1') {
                e.push_back(make_pair(i,j+1));
                add(i,j+1);
            }
        }
    }

    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);
    
    #ifdef DEBUG
    for(int i=1;i<=n;i++) {
        for(int j=head[i];j;j=nxt[j])
            printf("%d %d\n",i,to[j]);
    }
    #endif

    memset(head,0,sizeof(head));
    memset(nxt,0,sizeof(nxt));
    memset(to,0,sizeof(to));
    memset(vis,0,sizeof(vis));
    for(auto p:e) {
        if(color[p.first] != color[p.second])
            add(color[p.first],color[p.second]);
    }

    

    long long ans=0;
    for(int i=1;i<=n;i++) {
        ans += f[color[i]];
    }
    printf("%lld",ans);
    return 0;
}