#include <cstdio>


int main()
{
    int n;
    scanf("%d", &n);

    if(n % 2)
    {
        puts("-1");
        return 0;
    }

    for(int i = 25; i >= 1 && n; i--)
    {
        int q = 1 << i;
        if(q <= n)
        {
            n -= q;
            printf("%d ", q);
        }
    }

    return 0;
}