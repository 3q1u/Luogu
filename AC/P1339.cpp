#include <bits/stdc++.h>
using namespace std;
const int N=2505,M=12410;

int n,m,s,t;

int head[N],nxt[M],to[M],val[M],cnt;
void add(int u,int v,int w) {
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
    val[cnt] = w;
}

struct node {
    int dis,u;
    bool operator >(const node& a) const{
        return dis > a.dis;
    }
};
priority_queue<node,vector<node>,greater<node>> q;
int dis[N]; bool vis[N];
void dij() {
    for(int i=1;i<=n;i++) {
        dis[i] = 0x3f3f3f3f;
    }
    dis[s] = 0;
    q.push({0,s});
    
    while(!q.empty()) {
        int u = q.top().u;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i=head[u];i;i=nxt[i]) {
            int v = to[i];
            if(dis[v] > dis[u]+val[i]) {
                dis[v] = dis[u]+val[i];
                q.push({dis[v],v});
            }
        }
    }
}

int main() {
    scanf("%d %d %d %d",&n,&m,&s,&t);
    for(int i=1;i<=m;i++) {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }

    dij();
    printf("%d",dis[t]);
    return 0;
}