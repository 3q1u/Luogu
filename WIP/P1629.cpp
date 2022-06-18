#include <cstdio>
#include <cstring>
#include <cctype>
#include <utility>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 1e3+2,MAXM = 1e5+2;
struct edge
{
    int next,to;
    int val;
}gra[MAXM],rgra[MAXM];
int head[MAXN],rhead[MAXN],dis[MAXN],rdis[MAXN],cnt = 0,n,m;
bool vis[MAXN],rvis[MAXN];

typedef pair<int,int> node;
priority_queue<node,vector<node>,greater<node>> q,rq;

inline void addEdge(int u,int v,int w)
{
    gra[++cnt].next = head[u];
    gra[cnt].to = v;
    gra[cnt].val = w;
    rgra[cnt].next = rhead[v];
    rgra[cnt].to = u;
    rgra[cnt].val = w;
}

inline int read(){
    int s=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)) {if(ch == '-') f=0;ch=getchar();}
    while(isdigit(ch)) {s=(s<<1)+(s<<3)+(ch^48);ch=getchar();}
    return f?s:-s;
}

inline void dij();
inline void rdij();

int main()
{
    memset(dis,0x3f,sizeof(dis)),memset(rdis,0x3f,sizeof(rdis));
    memset(vis,0,sizeof(vis)),memset(rvis,0,sizeof(rvis));
    n = read(),m = read();
    for(int i=1;i<=m;i++) addEdge(read(),read(),read());
    int ans = 0;
    dij(),rdij();
    for(int i=2;i<=n;i++) ans = ans+dis[i]+rdis[i];
    printf("%d",ans);
    return 0;
}

inline void dij()
{
    dis[1] = 0;
    q.push(make_pair(0,1));
    while(!q.empty())
    {
        int x=q.top().second;
        q.pop();
        if(vis[x]) continue;
        vis[x] = 1;
        for(int i=head[x];i;i=gra[i].next)
        {
            if(!vis[gra[i].to] && dis[gra[i].to]>dis[x]+gra[i].val)
            {
                dis[gra[i].to] = dis[x]+gra[i].val;
                q.push(make_pair(dis[gra[i].to],gra[i].to));
            }
        }
    }
}

inline void rdij()
{
    rdis[1] = 0;
    rq.push(make_pair(0,1));
    while(!rq.empty())
    {
        int x=rq.top().second;
        rq.pop();
        if(rvis[x]) continue;
        rvis[x] = 1;
        for(int i=rhead[x];i;i=rgra[i].next)
        {
            if(!rvis[rgra[i].to] && rdis[rgra[i].to]>rdis[x]+rgra[i].val)
            {
                rdis[rgra[i].to] = rdis[x]+rgra[i].val;
                rq.push(make_pair(rdis[rgra[i].to],rgra[i].to));
            }
        }
    }
}