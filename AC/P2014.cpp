#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 305;

int m, n;

int val[MAXN];
int head[MAXN], nxt[MAXN], to[MAXN], cnt = 0;
inline void add(const int &u, const int &v)
{
    nxt[++cnt] = head[u];
    to[cnt] = v;
    head[u] = cnt;
}

int dp[MAXN][MAXN];
void dfs(int u)
{
    for(int i = head[u]; i; i = nxt[i])
    {
        int v = to[i];
        dfs(v);

        for(int j = m + 1; j >= 1; j--)
        for(int k = 0; k < j; k++)
            dp[u][j] = std::max(dp[u][j], dp[v][k] + dp[u][j - k]);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        int pre;
        scanf("%d %d", &pre, &dp[i][1]);
        add(pre, i);
    }

    dfs(0);

    printf("%d", dp[0][m+1]);
}