#include <cstdio>
#include <cstring>

int dp[310][310];
int sum[310] = {0};

auto min = [](auto a,auto b)
{
    return a<b?a:b;
};

int main()
{
    memset(dp,0x3f,sizeof(dp));
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        sum[i] = sum[i-1]+tmp;
        dp[i][i] = 0;
    }
    
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i<=n-len+1;i++)
        {
             int j=i+len-1;
             for(int k=i;k<j;k++)
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
        }
    }
    printf("%d",dp[1][n]);
    return 0;
}