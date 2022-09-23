#include <cstdio>
using namespace std;

int dp[21][21],n,m,hx,hy;

int main()
{
    scanf("%d %d %d %d",&n,&m,&hx,&hy);
    dp[hx][hy] = 0;
    dp[hx+2][hy+1] = 0;
    dp[hx+2][hy-1] = 0;
    dp[hx+1][hy+2] = 0;
    dp[hx+1][hy-2] = 0;
    dp[hx-1][hy+2] = 0;
    dp[hx-1][hy-2] = 0;
    dp[hx-2][hy+1] = 0;
    dp[hx-2][hy-1] = 0;
    for(int i=1;i<=n;i++) dp[i][0] = 0;
    for(int i=1;i<=m;i++) dp[0][i] = 0;
    dp[0][0] = 1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i-)
        }
    }
}