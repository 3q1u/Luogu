#include <bits/stdc++.h>
using namespace std;

const int N = 3*1e4+5;
int a[N],bkt[N],blk,curL=1,curR=0,cnt,ans[N];
int rd()
{
    int s=0,f=1;char c=getchar();
    while(!isdigit(c)) {if(c=='-') f=-1;c=getchar();}
    while(isdigit(c)) {s=(s<<3)+(s<<1)+(c^48);c=getchar();}
    return s*f;
}

struct query
{
    int l,r,p;
    bool operator<(const query& b);
}req[N];

bool query::operator <(const query& b)
{
    return (this->l/blk)==(b.l/blk)?this->r<b.r:this->l<b.l;
}

inline void add(const int& pos)
{
    if(!bkt[a[pos]]++) ++cnt;
}

inline void del(const int& pos)
{
    if(!(--bkt[a[pos]])) --cnt;
}

int main()
{
    int n=rd();
    blk = sqrt(n);
    for(int i=1;i<=n;i++) a[i]=rd();
    int q=rd();
    for(int i=1;i<=q;i++)
    {
        req[i].l=rd(),req[i].r=rd();
        req[i].p = i;
    }
    sort(req+1,req+q+1);

    for(int i=1;i<=q;i++)
    {
        int L=req[i].l,R=req[i].r;
        while(curL < L) del(curL++);
        while(curL > L) add(--curL);
        while(curR < R) add(++curR);
        while(curR > R) del(curR--);
        ans[req[i].p] = cnt;
    }

    for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
    return 0;
}