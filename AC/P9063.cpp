#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a;
    int t;
    scanf("%d\n",&t);
    while(t--) {
        scanf("%lld",&a);
        puts(a%2?"Yes":"No");
    }
    return 0;
}