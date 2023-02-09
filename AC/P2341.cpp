#include <bits/stdc++.h>
#include <new>
#include <system_error>
using namespace std;

const int N = 1e4+5,M = 5*N+5;

int n,m,x[M],y[M],num[N];

int head[N],nxt[M],to[M],cnt;
void add(int u,int v) {
    nxt[++cnt] = head[u];
    to[cnt] = v;
    head[u] = cnt;
}

int dfn[N],low[N],stk[N],c[N],top,siz,scc; bool vis[N];
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
            c[w] = scc;
            num[scc]++;
            vis[w] = 0;
        }
    }
}

int search() {
    int *out = new int[scc+1];
    memset(out,0,sizeof(int)*(scc+1));
    memset(head,0,sizeof(head));
    memset(nxt,0,sizeof(nxt));
    memset(to,0,sizeof(to));

    map<pair<int,int>,bool> mp;
    for(int i=1;i<=m;i++) {
        if(c[x[i]] != c[y[i]]) {
            if(!mp[make_pair(c[x[i]],c[y[i]])]) {
                add(c[x[i]],c[y[i]]);
                out[c[x[i]]]++;
                mp[make_pair(c[x[i]],c[y[i]])] = 1;
            }
        }
    }

    int f=0;

    for(int i=1;i<=scc;i++) {
        if(!out[i]) {
            if(f) {
                delete[] out;
                return 0;
            }
            else {
                f=num[i];
            }
        }
    }

    delete[] out;
    return f;
}

int main() {
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++) {
        scanf("%d %d",&x[i],&y[i]);
        add(x[i],y[i]);
    }

    for(int i=1;i<=n;i++) {
        if(!dfn[i])
            tarjan(i);
    }

    printf("%d",search());
    return 0;
}