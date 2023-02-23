#include <cstdio>

const int MAXN = 110;

int work(int h[], const int& n)
{
    int f[MAXN], g[MAXN];
    for(int i = 1; i <= n; i++)
        f[i] = 1, g[i] = 1;

    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j < i; j++)
        {
            if(h[i] > h[j])
                f[i] = f[j] + 1;
        }
    }
    for(int i = n - 1; i >= 1; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            if(h[i] > h[j])
                g[i] = g[j] + 1;
        }
    }
    
    int out = 0;
    for(int i = 1; i <= n; i++)
    {
        int tmp = f[i] + g[i] - 1;
        out = out < tmp ? tmp : out;
    }

    return out;
}

int main()
{
    int n = 8;
    
    int a[MAXN] = {0,186,186,150,200,160,120,197,200};

    int ans = work(a, n);

    printf("%d", n - ans);
}