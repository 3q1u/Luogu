#include <bits/stdc++.h>
using namespace std;
const int N=1100;
long long dp[N]={0};
int lose[N],win[N],use[N];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",lose+i,win+i,use+i);
    
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=use[i];j--)
            dp[j]=max(dp[j]+lose[i],dp[j-use[i]]+win[i]);
        for(int j=use[i]-1;j>=0;j--)
            dp[j] += lose[i];
    }
    printf("%lld",5ll*dp[m]);
    return 0;
}