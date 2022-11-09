#include <cstdio>
#include <algorithm>
using namespace std;

struct app
{
    int hgt,p;
    friend bool operator <(const app& a,const app& b);
}tr[5005];

int main()
{
    int n,s,a,b,able=0,ans=0;
    scanf("%d %d\n%d %d",&n,&s,&a,&b);
    a += b;
    for(int i=1;i<=n;++i)
    {
        scanf("%d %d",&tr[i].hgt,&tr[i].p);
        if(tr[i].hgt <= a) ++able;
    }
    sort(tr+1,tr+n+1);
    for(int i=1;s>=0&&i<=able;i++)
    {
        if(tr[i].hgt <= a) s -= tr[i].p,++ans;
    }
    printf("%d",ans);
    return 0;
}

bool operator <(const app& a,const app& b)
{
    return a.p<b.p;
}