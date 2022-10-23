#include <bits/stdc++.h>
using namespace std;

int dp[40][40];

int main()
{
    int m,n;
    dp[0][1] = 1;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j == 1)
                dp[i][j] = dp[i-1][n] + dp[i-1][2];
            else if(j == n)
                dp[i][j] = dp[i-1][1]+dp[i-1][n-1];
            else dp[i][j] = dp[i-1][j-1]+dp[i-1][j+1];
        }
    }
    printf("%d",dp[m][1]);
    
    return 0;
}