#include <bits/stdc++.h>
using namespace std;

int f[10010],p[110][110];

int main()
{
    int t,n,m,ans;
    scanf("%d%d%d",&t,&n,&m);

    for(int i=1;i<=t;i++)
    for(int j=1;j<=n;j++)
        scanf("%d",&p[i][j]);
    
    ans=m;

    for(int i=1;i<t;i++)
    {
        memset(f,~0x3f,sizeof(f));
        f[ans]=ans;
        for(int j=1;j<=n;j++)
        for(int k=ans;k>=p[i][j];k--)
            f[k-p[i][j]]=max(f[k-p[i][j]],f[k]+p[i+1][j]-p[i][j]);
        auto mx=0;
        for(int j=0;j<=ans;j++)
            mx=max(mx,f[j]);

        ans = mx;
    }

    printf("%d",ans);
    return 0;
}