#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h,n,w[5005],dp[50005];
    memset(dp,0,sizeof(dp));
    cin>>h>>n;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=h;j>=w[i];j--)
        {
            dp[j]=max(dp[j],dp[j-w[i]]+w[i]);
        }
    }
    cout<<dp[h];
    return 0;
}