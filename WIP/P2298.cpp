#include <cstdio>
#include <queue>
using namespace std;

static const int MAXN = 2005;
static const int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

struct coo
{
    int x,y;
    coo(){};
    coo(int x,int y):x(x),y(y){};
};

queue<coo> q;
char maze[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dis[MAXN][MAXN],n,m;

int bfs(coo c)
{
    q.push(c);
    vis[c.x][c.y] = 1;
    while(!q.empty())
    {
        coo f = q.front();
        q.pop();
        if(maze[f.x][f.y] == 'd') return dis[f.x][f.y];
        for(auto i=0;i<4;i++)
        {
            coo t(f.x+d[i][0],f.y+d[i][1]);
            if(t.x<=0||t.x>n||t.y<=0||t.y>m||maze[t.x][t.y]=='#'||vis[t.x][t.y]==1) continue;
            dis[t.x][t.y] = dis[f.x][f.y]+1;
            vis[t.x][t.y] = 1;
            q.push(t);
        }
    }
    return -1;
}

int main()
{
    coo start;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%c",&maze[i][j]);
            if(maze[i][j] == 'm') {start.x = i;start.y = j;}
        }
    }
    int r = bfs(start);
    if(r == -1) printf("No Way!");
    else printf("%d",r);
    return 0;
}