#include <stdio.h>
#include <algorithm>
#define MAXN 1005
using namespace std;

const int mod[] = {1,10,100,1000,10000,100000,1000000,10000000};
int book[MAXN],size,reader;

int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(auto i=1;i<=n;i++)
        scanf("%d",&book[i]);
    sort(book+1,book+n+1);
    for(auto i=1;i<=q;i++)
    {
        bool flag=0;
        scanf("%d%d",&size,&reader);
        for(auto j=1;j<=n;j++)
        {
            if(book[j]%mod[size] == reader)
            {
                printf("%d\n",book[j]);
                flag = true;
                break;
            }
        }
        if(!flag)
            printf("-1\n");
    }
    return 0;
}