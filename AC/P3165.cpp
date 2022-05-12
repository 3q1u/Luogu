#include <cstdio>
#define r register
using namespace std;
int arr[2000001];

int main()
{
    int n,m;
    r int p;
    scanf("%d%d",&n,&m);
    for(r int i=1;i<=n;i++) scanf("%d",&arr[i]);
    for(r int i=1;i<=m;i++)
    {
        scanf("%d",&p);
        printf("%d\n",arr[p]);
    }
    return 0;
}