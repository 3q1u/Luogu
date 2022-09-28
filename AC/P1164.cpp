#include <cstdio>
using namespace std;
int f[10010],a[110];

int main()
{
    int n,m;
    f[0] = 1;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) {

        scanf("%d", &a[i]);
        f[i] = 0;
    }
        for(int i=1;i<=n;i++)
            for(int j=m;j>=a[i];j--)
            f[j] += f[j-a[i]];

    printf("%d",f[m]);
    return 0;
}