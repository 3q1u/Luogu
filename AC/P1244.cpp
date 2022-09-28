#include <cstdio>
using namespace std;

int main() {
    long long h,k;
    scanf("%lld %lld",&h,&k);
    long long ans = (k+1)*(1<<h);
    printf("%lld",ans);
    return 0;
}