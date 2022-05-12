#include <cstdio>
using namespace std;

const int MAXN = 2*1e6+5;
int e[MAXN];
int q[MAXN],head,tail;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&e[i]);
    head = 1;
    tail = 0;
    printf("0\n");
    for(int i=1;i<n;i++)
    {
        while(head<=tail && (q[head]+m)<=i) head++;
        while(head<=tail && e[q[tail]]>=e[i]) tail--;
        q[++tail] = i;
        printf("%d\n",e[q[head]]);
    }
    return 0;
}