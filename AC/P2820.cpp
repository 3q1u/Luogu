#include <cstdio>
#include <algorithm>
#include <cctype>
using namespace std;

int read()
{
    int s=0,f=1;char c=getchar();
    while(!isdigit(c)) {if(c=='-') f=-1;c=getchar();}
    while(isdigit(c)) {s=(s<<3)+(s<<1)+(c^48);c=getchar();}
    return s*f;
}

int s[105],sum=0,ans=0,n,k;
int find(const int& x)
{
    if(s[x] == x) return x;
    else return s[x]=find(s[x]);
}
void merge(const int&x, const int &y)
{
    s[find(x)] = find(y);
}
bool query(const int& x, const int& y)
{
    return find(x) == find(y);
}

struct edge
{
    int u,v,w;
    bool operator <(const edge& b)
    {
        return this->w < b.w;
    }
}e[5100];

void kru()
{
    int num=0;
    for(int i=1;i<=k && num < n-1;i++)
    {
        int u=e[i].u,v=e[i].v;
        if(!query(u,v))
        {
            ans+=e[i].w;
            num++;
            merge(u,v);
        }
    }
}

int main()
{
    n=read(), k=read();
    for(int i=1;i<=n;i++)
        s[i] = i;
    for(int i=1;i<=k;i++)
    {
        e[i].u=read(), e[i].v=read(), e[i].w=read();
        sum += e[i].w;
    }
    sort(e+1,e+k+1);
    kru();
    
    printf("%d",sum-ans);
}