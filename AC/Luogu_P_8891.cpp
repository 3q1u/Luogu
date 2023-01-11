#include <bits/stdc++.h>
#include <climits>
using namespace std;

int n,m;
long long a[1000010];

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",a+i);
    while(m--)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        if(x == 0) continue;
        a[x] -= y;
    }
    for(int i=1;i<=n;i++)
        printf("%lld ",a[i]);
    return 0;
}