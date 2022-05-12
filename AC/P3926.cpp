#include <cstdio>
#define int long long
using namespace std;

signed main()
{
    int a,c,p,q,r,x;
    scanf("%lld%lld%lld%lld%lld%lld",&a,&c,&p,&q,&r,&x);
    while(a < c)
    {
        if(a < c)
        {
            if(x >= p) {x -= p;a++;}
            else {printf("%lld",a);return 0;}
        }
    }
    if(x < q) {printf("%lld",a);return 0;}
    printf("%lld",a+(x-q)/r);
    return 0;
}