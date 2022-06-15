#include <iostream>
#include <cmath>
#include <cstring>
#define ll long long
using namespace std;

ll dp[1001];
int prime[1001],cnt = 0;
bool isPrime[1001];

void getPrime(int n)
{
    memset(isPrime,1,sizeof(isPrime));
    isPrime[1]=0;
    isPrime[0]=0;
    for(int i=2;i<=n;i++)
    {
        if(isPrime[i]) prime[++cnt]=i;
        for(int j=1;j<=cnt && i*prime[j]<=n;j++)
        {
            isPrime[i*prime[j]]=0;
            if(i%prime[j]==0) break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    getPrime(n);
    dp[0] = 1;
    for(int i=1;i<=cnt;i++)
            for(int j=prime[i];j<=n;j++)
                dp[j] += dp[j-prime[i]];
    cout<<dp[n];
    return 0;
}