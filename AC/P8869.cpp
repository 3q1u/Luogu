#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b;
    scanf("%lld %lld",&a,&b);
    a = (a > 0)?a:-a;
    printf("%lld",b>0?a:-a);
    return 0;
}