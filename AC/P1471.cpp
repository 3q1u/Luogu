#include <bits/stdc++.h>
using namespace std;
using d = double;

const int MAXN = 1e5 + 5;


struct Node
{
    d sum1, sum2;
    d lazy;
}tr[4 * MAXN];

int n, m;

inline int ls(int x)
{
    return x << 1;
}

inline int rs(int x)
{
    return x << 1 | 1;
}

inline d fSq(d x)
{
    return x * x;
}

inline int half(int x, int y)
{
    return x + ((y - x) >> 1);
}
void pushUp(int x)
{
    tr[x].sum1 = tr[ls(x)].sum1 + tr[rs(x)].sum1;
    tr[x].sum2 = tr[ls(x)].sum2 + tr[rs(x)].sum2;
}

void build(int x, int l, int r)
{
    if(l == r)
    {
        scanf("%lf", &tr[x].sum1);
        tr[x].sum2 = fSq(tr[x].sum1);
        return;
    }

    int mid = half(l, r);
    build(ls(x), l, mid);
    build(rs(x), mid + 1, r);

    pushUp(x);
}

void add(int x, int l, int r, d k)
{
    tr[x].lazy += k;
    tr[x].sum2 += (tr[x].sum1 * 2 * k + (r - l + 1) * fSq(k));
    tr[x].sum1 += (r - l + 1) * k;
}

void pushDown(int x, int l, int r)
{
    if(!tr[x].lazy) return;
    
    int mid = half(l, r);
    add(ls(x), l, mid, tr[x].lazy);
    add(rs(x), mid + 1, r, tr[x].lazy);

    tr[x].lazy = 0.0;
}

void update(int x, int l, int r, int cl, int cr, d k)
{
    if(cl <= l && r <= cr)
    {
        add(x, l, r, k);
        return;
    }

    pushDown(x, l, r);

    int mid = half(l, r);
    if(cl <= mid) update(ls(x), l, mid, cl, cr, k);
    if(mid < cr) update(rs(x), mid + 1, r, cl, cr, k);

    pushUp(x);
}

d query_a(int x, int l, int r, int cl, int cr)
{
    if(cl <= l && r <= cr)
        return tr[x].sum1;
    
    d ret = 0;
    int mid = half(l, r);
    pushDown(x, l, r);
    if(cl <= mid) ret += query_a(ls(x), l, mid, cl, cr);
    if(mid < cr) ret += query_a(rs(x), mid + 1, r, cl, cr);

    return ret;
}

d query_b(int x, int l, int r, int cl, int cr)
{
    if(cl <= l && r <= cr)
        return tr[x].sum2;
    
    d ret = 0;
    int mid = half(l, r);
    pushDown(x, l, r);
    if(cl <= mid) ret += query_b(ls(x), l, mid, cl, cr);
    if(mid < cr) ret += query_b(rs(x), mid + 1, r, cl, cr);

    return ret;
}

int main()
{
    // freopen("data.in", "r", stdin);
    scanf("%d %d", &n, &m);

    build(1, 1, n);

    int op;
    while(m--)
    {
        scanf("%d", &op);
        switch(op)
        {
            case 1:
            {
                int x, y; d k;
                scanf("%d %d %lf", &x, &y, &k);
                update(1, 1, n, x, y, k);
                break;
            }
            case 2:
            {
                int x, y;
                scanf("%d %d", &x, &y);
                printf("%.4lf\n", query_a(1, 1, n, x, y) / (y - x + 1));
                break;
            }
            case 3:
            {
                int x, y;
                scanf("%d %d", &x, &y);
                d s1 = query_a(1, 1, n, x, y) / (y - x + 1),
                  s2 = query_b(1, 1, n, x, y) / (y - x + 1);
                printf("%.4lf\n", s2 - fSq(s1));
                break;
            }
            default:
            {
                break;
            }
        }
    }
}