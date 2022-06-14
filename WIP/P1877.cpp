#include <iostream>
using namespace std;

int c[51];
bool dp[51][1001];

int main()
{
    ios::sync_with_stdio(false);
    int n,beginl,maxl;
    cin>>n>>beginl>>maxl;
    for(int i=1;i<=n;i++) cin>>c[i];
    dp[0][beginl] = 1;
    for(int i=1;i<=n;i++)
    {
        for(int j=maxl;j>=0;j--)
        {
            if(j-c[i] >= 0) dp[i][j] = dp[i][j]||dp[i-1][j-c[i]];
            if(j+c[i] <= maxl) dp[i][j] = dp[i][j]||dp[i-1][j+c[i]];
        }
    }
    for(int i=maxl;i>=1;i--)
    {
        if(dp[n][i]) {cout<<i;return 0;}
    }
    cout<<"-1";
    return 0;
}