#include <iostream>
#define ll long long
#define p2 p<<1
#define pt p<<1|1
using namespace std;

const int MAXN = 1e5+1;
int a[MAXN];

struct node
{
    int l,r;
    ll val;
}t[MAXN<<2];

void buildTree(int,int,int);
void modify(int,int,int);
ll query(int,int,int);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    int a,b;
    char op;
    cin>>n>>m;
    buildTree(1,1,n);
    for(int i=1;i<=m;i++)
    {
        cin>>op>>a>>b;
        if(op == 'x')
            modify(1,a,b);
        if(op == 'y')
            cout<<query(1,a,b)<<endl;
    }
    return 0;
}

void buildTree(int p,int l,int r)
{
    t[p].l = l;
    t[p].r = r;
    t[p].val = 0;
    if(l == r) return;
    int mid = (l+r)>>1;
    buildTree(p2,l,mid);
    buildTree(pt,mid+1,r);
}

void modify(int p,int tar,int k)
{
    if(t[p].l == t[p].r) {t[p].val += k;return;}
    int mid = (t[p].l+t[p].r) >> 1;
    if(tar <= mid) modify(p2,tar,k);
    if(mid < tar) modify(pt,tar,k);
    t[p].val = t[p2].val+t[pt].val;
}

ll query(int p,int l,int r)
{
    if(t[p].l>=l && t[p].r<=r) return t[p].val; //如果包含直接输出
    ll ans = 0;
    int mid = (t[p].l+t[p].r) >> 1;
    if(l <= mid) ans += query(p2,l,r);
    if(mid < r) ans += query(pt,l,r);
    return ans;
}