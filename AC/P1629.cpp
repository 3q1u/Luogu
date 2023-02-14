#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5,M=1e5+5;
int n,m;

struct graph {
    vector<int> head,nxt,to,val;
    vector<int> dis;
    bitset<N> vis;
    int cnt = 0;
    graph() {}
    graph(int n,int m) {
        head.resize(n+5);
        nxt.resize(m+5);
        to.resize(m+5);
        val.resize(m+5);
        dis.resize(n+5,0x3f3f3f3f);
        vis.reset();
    }

    void add(int u,int v,int w) {
        nxt[++cnt] = head[u];
        head[u] = cnt;
        to[cnt] = v;
        val[cnt] = w;
    }
}*e,*re;

struct node {
    int dis,u;
    bool operator >(const node& a) const {
        return dis > a.dis;
    }
};
void dij(graph& e,int s) {
    priority_queue<node,vector<node>,greater<node>> q;
    e.dis[1] = 0;
    q.push({0,1});

    while(!q.empty()) {
        int u = q.top().u;
        q.pop();
        if(e.vis[u]) continue;
        e.vis[u] = 1;
        for(int i=e.head[u];i;i=e.nxt[i]) {
            int v = e.to[i];
            if(e.dis[v] > e.dis[u]+e.val[i]) {
                e.dis[v] = e.dis[u]+e.val[i];
                q.push({e.dis[v],v});
            }
        }
    }
}


int main() {
    scanf("%d %d",&n,&m);
    e = new graph(n,m);
    re = new graph(n,m);

    for(int i=1;i<=m;i++) {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        e->add(u,v,w);
        re->add(v,u,w);
    }

    dij(*e,1);
    dij(*re,1);

    long long ans=0;
    for(int i=1;i<=n;i++)
        ans += (e->dis[i]+re->dis[i]);
    printf("%lld",ans);
    return 0;
}