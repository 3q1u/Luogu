#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int vol,mass,n,v[55],w[55],c[55],dp[405][405];
    cin>>vol>>mass
       >>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>w[i]>>c[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=vol;j>=v[i];j--)
        {
            for(int k=mass;k>=w[i];k--)
            {
                dp[j][k]=max(dp[j][k],dp[j-v[i]][k-w[i]]+c[i]);
            }
        }
    }
    cout<<dp[vol][mass];
    return 0;
}