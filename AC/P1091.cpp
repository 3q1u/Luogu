#include <bits/stdc++.h>
using std::lower_bound;
using std::max;

const int MAXN = 105;

int n;
int h[MAXN], lis[MAXN], lds[MAXN];

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &h[i]);
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j < i; j++)
        {
            if(h[j] < h[i])
                 lis[i] = max(lis[j], lis[i]);
        }
        lis[i]++;
    }

    for(int i = n; i >= 1; i--)
    {
        for(int j = n; j > i; j--)
        {
            if(h[j] < h[i])
                 lds[i] = max(lds[j], lds[i]);
        }
        lds[i]++;
    }

    int ans = n;
    for(int i = 1; i <= n; i++)
    {
        ans = std::min(ans, n - lis[i] - lds[i] + 1);
    }
    printf("%d", ans);
    return 0;
}