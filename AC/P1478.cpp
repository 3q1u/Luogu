#include <bits/stdc++.h>
using namespace std;
const int N=5005;

int a,s,n,b,ans;

struct apple {
    int h,y;
    bool operator <(const apple& a) {
        return y<a.y;
    }
}tree[N];

int main() {
    scanf("%d %d\n%d %d",&n,&s,&a,&b);
    a += b;
    for(int i=1;i<=n;i++)
        scanf("%d %d",&tree[i].h,&tree[i].y);

    sort(tree+1,tree+1+n);
    for(int i=1;i<=n && s>=0;i++) {
        if(tree[i].h <= a) {
            if(tree[i].y <= s) {
                s -= tree[i].y;
                ans++;
            }
        }
    }
    printf("%d",ans);
    return 0;
}