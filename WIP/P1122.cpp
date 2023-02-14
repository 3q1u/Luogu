#include <bits/stdc++.h>
#include <climits>
using namespace std;
const int N = 16*1e3+5;
int n;

int head[N],nxt[2*N],to[2*N],cnt;
void __add(int u,int v) {
    nxt[++cnt] = head[u];
    to[cnt] = v;
    head[u] = cnt;
}
void add(int u,int v) {
    __add(u,v);
    __add(v,u);
}

int f[N],a[N];
void dfs(int u,int p) {
    f[u] = a[u];
    for(int i=head[u];i;i=nxt[i]) {
        int v = to[i];
        if(v != p)
            dfs(v,u);
        f[u] += f[v]>0?f[v]:0;
    }
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    
    for(int i=1;i<n;i++) {
        int u,v;
        scanf("%d %d",&u,&v);
        add(u,v);
    }

    dfs(1,0);
    int ans=INT_MIN;
    for(int i=1;i<=n;i++)
        ans = max(ans,f[i]);
    printf("%d",ans);
    return 0;
}