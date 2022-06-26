#include <cstdio>
using namespace std;
int ans,n,x;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&x),ans ^= x;
    printf("%d",ans);
}