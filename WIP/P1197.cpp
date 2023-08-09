#include <bits/stdc++.h>
using namespace std;

const int MAXM = 2*1e5+5;

struct tunnel
{
    int x, y;
}edge[MAXM];

int a[2*MAXM], m, n, k;
int des[2*MAXM];
bool isDes[2*MAXM];
int ans[2*MAXM];
int find(int x)
{
    return x==a[x]?x:a[x]=find(a[x]);
}
void merge(int x,int y)
{
    int fx = find(x), fy = find(y);
    a[fy] = fx;
}
bool query(int x, int y)
{
    return find(x) == find(y);
}

int main()
{
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        a[i] = i;
    for(int i=1; i<=m; i++)
        cin >> edge[i].x >> edge[i].y;
    cin >> k;
    for(int i=1; i<=k; i++)
    {
        cin >> des[i];
        isDes[des[i]] = 1;
    }

    for(int i=1; i<=m; i++)
    {
        if(isDes[edge[i].x] || isDes[edge[i].y])
            continue;
        merge(edge[i].x, edge[i].y);
    }

    for(int i=1)
}