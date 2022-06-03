#include <stdio.h>
#define ll long long

int n,k;
ll dat[21],ans=0;

inline bool isPrime(ll n)
{
    for(auto i=2;i*i<=n;i++)
        if(n%i == 0) return false;
    return true;
}

void dfs(int p,int len,ll sum)
{
    if(len == k+1)
    {
        if(isPrime(sum)) ans++;
        return;
    }
    else
    {
        for(auto i=p;i<=n;i++)
            dfs(i+1,len+1,sum+dat[i]);
    }
}

int main()
{
    scanf("%d %d",&n,&k);
    for(auto i=1;i<=n;i++)
        scanf("%lld",&dat[i]);
    dfs(1,1,0);
    printf("%lld",ans);
    return 0;
}