#include <cstdio>
using namespace std;

int main()
{
    int a,b,c,d,ans;
    char ch;
    scanf("%d-%d-%d-%c",&a,&b,&c,&ch);
    if(ch == 'X') d = 10;
    else d = ch-'0';
    ans = a;
    for(int i=4;i>=2;i--)
    {
        ans += (b%10)*i;
        ans %= 11;
        b /= 10;
    }
    for(int i=9;i>=5;i--)
    {
        ans += (c%10)*i;
        ans %= 11;
        c /= 10;
    }
    if(ans == d) printf("Right");
    else
    {
        printf("%d-%d-%d-",a,b,c);
        if(ans == 10) printf("X");
        else printf("%d",ans);
    }
    return 0;
}