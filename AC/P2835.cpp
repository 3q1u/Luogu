#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> e[205],nw[205],x,y;
void add(vector<int> *e,int u,int v) {
    e[u].push_back(v);
}

int dfn[205],low[205],stk[205],c[205],top,siz,scc; bool vis[205];
void tarjan(int u) {
    dfn[u]=low[u]=++siz;
    vis[u] = 1;
    stk[++top] = u;

    for(auto it=e[u].begin();it!=e[u].end();it++) {
        int v = *it;
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
            vis[w] = 0;
        }
    }
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        int v;
        scanf("%d",&v);
        while(v != 0) {
            m++;
            add(e,i,v);
            x.push_back(i);
            y.push_back(v);
            scanf("%d",&v);
        }
    }

    for(int i=1;i<=n;i++) {
        if(!dfn[i])
            tarjan(i);
    }

    int in[205];
    memset(in,0,sizeof(in));
    map<pair<int,int>,bool> mp;
    
    for(int i=0;i<m;i++) {
        if(c[x[i]]!=c[y[i]] && !mp[make_pair(c[x[i]],c[y[i]])]) {
            add(nw,c[x[i]],c[y[i]]);
            in[c[y[i]]]++;
            mp[make_pair(c[x[i]],c[y[i]])] = 1;
        }
    }

    int ans=0;
    for(int i=1;i<=scc;i++) {
        if(!in[i])
            ans++;
    }
    printf("%d",ans);
    return 0;
}