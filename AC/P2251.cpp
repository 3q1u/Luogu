#include <iostream>
#define MAXN static_cast<unsigned long long>(10e5+5)
using namespace std;

int e[MAXN];
int q[MAXN],head,tail;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    for(int i =1 ;i <= n;i++)
    {
        cin >> e[i];
    }
    head = 1;
    tail = 0;
    for(int i = 1;i <= n;i++)
    {
        while(head<=tail && e[q[tail]]>=e[i]) tail--;
        q[++tail] = i;
        while((q[head]+m) <= i) head++;
        if(i >= m) cout<<e[q[head]]<<endl;
    }
    return 0;
}