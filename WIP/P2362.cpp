#include <cstdio>
using namespace std;

int a[21],max = 0,cnt=0;

void dfs(int cur,int n,int len);

int main()
{
    int m,n;
    scanf("%d",&m);
    while(m--)
    {
        max = 0,cnt=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<n;i++)
            dfs(i,n,1);
        printf("%d %d\n",max,cnt);
    }
    return 0;
}

void dfs(int cur,int n,int len)
{
    if(len > max)
    {
        max = len;
        cnt = 0;
    }
    if(len == max) cnt++;
    for(int i=cur+1;i<=n;i++)
    {
        if(a[i] >= a[cur])
            dfs(i,n,len+1);
    }
}
