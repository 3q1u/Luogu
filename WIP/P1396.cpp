#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+10,MAXM = MAXN<<2;

typedef pair<int,int> node;
int nxt[MAXM],to[MAXM],val[MAXM],head[MAXN],cnt = 0;
bool vis[MAXN];
int dis[MAXN];

priority_queue<node,vector<node>,greater<node>> q;

auto rd = []()
{
    auto s=0,f=1;char ch=getchar();
    while(!isdigit(ch)) {if(ch=='-') f=-1;ch=getchar();}
    while(isdigit(ch)) {s=(s<<3)+(s<<1)+(ch^48);ch=getchar();}
    return s*f;
};

inline void adde(int u,int v,int w)
{
    nxt[++cnt] = head[u];
    to[cnt] = v;
    val[cnt] = w;
    head[u] = cnt;
}

void dij(int s)
{
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s] = 0;
    q.push(make_pair(0,s));
    while(!q.empty())
    {
        int x = q.top().second;
        q.pop();
        if(vis[x]) continue;
        vis[x] = 1;
        for(int i=head[x];i;i=nxt[i])
        {
            if(!vis[to[i]] && dis[to[i]] > max(dis[x],val[i]))
            {
                dis[to[i]] = max(dis[x],val[i]);
                q.push(make_pair(dis[to[i]],to[i]));
            }
        }
    }
}

int main()
{
    int n=rd(),m=rd(),s=rd(),t=rd();
    while(m--)
    {
        int u=rd(),v=rd(),w=rd();
        adde(u,v,w);
        adde(v,u,w);
    }

    dij(s);
    printf("%d",dis[t]);
}