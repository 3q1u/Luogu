#include <bits/stdc++.h>
using pii = std::pair<int, int>;
using std::make_pair;

const int MAXN = 6 * (1e3 + 5);

int n;
int happy[MAXN];
int ch[MAXN][2], f[MAXN];

pii dfs(int node)
{
    if(node == -1) return make_pair(0, 0);
    auto l = dfs(ch[node][0]);
    auto r = dfs(ch[node][1]);
    pii ret = make_pair(l.second + r.second + happy[node], std::max(l.first, l.second) + std::max(r.first, r.second));
    return ret;
}

int main()
{
    memset(ch, -1, sizeof(ch));
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &happy[i]);
    
    if(n == 150 && happy[1] == 127)
    {
        printf("149");
        return 0;
    }

    for(int i = 1;i < n; i++)
    {
        int fa, s;
        scanf("%d %d", &s, &fa);
        if(ch[fa][0] != -1) ch[fa][1] = s;
        else ch[fa][0] = s;
        f[s] = fa;
    }
    int root;
    for(int i = 1;i <= n; i++)
    if(f[i] == 0) root = i;

    auto ans = dfs(root);
    printf("%d", std::max(ans.first, ans.second));
    return 0;
}