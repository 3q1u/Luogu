#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T,M,w[108],v[108],dp[1008]={0};
    scanf("%d%d",&T,&M);
    for(int i=1;i<=M;i++) scanf("%d%d",&w[i],&v[i]);
    for(int i=1;i<=M;i++) 
    {
        for(int j=T;j>=0;j--)
        {
            if(j>=w[i])
                dp[j]=max(dp[j-w[i]]+v[i],dp[j]);
        }
    }
    printf("%d",dp[T]);
    return 0;
}