#include <cstdio>
#include <cstdlib>
#define reg register
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    for(reg int i=n;i>=0;i--)
    {
        reg int x;
        scanf("%d",&x);
        if(x)
        {
            if(i!=n && x>0) printf("+");
            if(i == 0) {printf("%d",x);continue;}
            if(abs(x)>1) printf("%d",x);
            if(x==-1 && i>0) printf("-");
            if(i >= 2) printf("x^%d",i);
            if(i == 1) printf("x");
        }
    }
    return 0;
}