#include <bits/stdc++.h>
#define gc getchar
using namespace std;

auto read = []()
{
    auto s=0,f=1;char c=gc();
    while(!isdigit(c)) {if(c=='-') f=-1;c=gc();}
    while(isdigit(c)) {s=(s<<3)+(s<<1)+(c^48);c=gc();}
    return s*f;
};

const int INF = 0x3f3f3f3f;
int e[201][201];
int n,m,t[201];
bool vis[201];

void init()
{
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        e[i][j] = (i==j?0:INF);
}

int main()
{
    memset(vis,0,sizeof(vis));
    n=read(), m=read();
    for(int i=0;i<n;i++)
    {
        t[i] = read();
    }
    init();

    while(m--)
    {
        int i=read(), j=read(), w=read();
        e[i][j]=w;
        e[j][i]=w;
    }

    int q=read();
    while(q--)
    {
        int x=read(), y=read(), ti=read();
        for(int k=0;k<n;k++)
        {
            if(t[k]>ti || vis[k]) continue;
            for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                e[i][j] = min(e[i][j],e[i][k]+e[k][j]);
                if(e[i][j] == e[i][k]+e[k][j]) vis[k] = 1;
            }
        }
        if(e[x][y]==INF || t[x]>ti || t[y]>ti)
            puts("-1");
        else printf("%d\n",e[x][y]);
    }
    return 0;
}