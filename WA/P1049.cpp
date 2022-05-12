#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m/*就是v*/,n,w[35],dp[20005];
    cin>>m>>n;
    for(int i=1;i<=n;i++) {cin>>w[i];}
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=0;j--)
        {
            if(j>=w[i])
                dp[j]=max(dp[j],dp[j-w[i]]+w[i]);
        }
    }
    cout<<m-dp[m];
    return 0;
}