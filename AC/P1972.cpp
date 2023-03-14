#include <bits/stdc++.h>
using namespace std;

void read(int &x)
{
    int f = 1; x = 0; char ch = getchar();
    while(!isdigit(ch))
    {
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(isdigit(ch))
    {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }

    x *= f;
}

const int MAXN = 1e6 + 5;

int a[MAXN], c[MAXN], ap[MAXN], ans[MAXN], m, n, p = 1;

struct Quest
{
    int l, r, p;
    bool operator <(const Quest &b)
    {
        return this->r < b.r;
    }
}q[MAXN];

inline int lowbit(int x)
{
    return x & (-x);
}

void add(int i, int k)
{
    for(; i <= n; i += lowbit(i))
        c[i] += k;
}

int query(int i)
{
    int ret = 0;
    for(; i; i -= lowbit(i))
    {
        ret += c[i];
    }
    return ret;
}

int main()
{
    read(n);
    for(int i = 1; i <= n; ++i)
        read(a[i]);

    read(m);
    for(int i = 1;i <= m; ++i)
    {
        read(q[i].l), read(q[i].r);
        q[i].p = i;
    }

    sort(q + 1, q + m + 1);

    for(int i = 1;i <= m; ++i)
    {
        for(int j = p; j <= q[i].r; ++j)
        {
            if(ap[a[j]]) add(ap[a[j]], -1);
            add(j, 1);
            ap[a[j]] = j;
        }
        p = q[i].r + 1;
        ans[q[i].p] = query(q[i].r) - query(q[i].l - 1);
    }

    for(int i = 1; i <= m; ++i)
        printf("%d\n", ans[i]);
}