#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

bool book[1001];
queue<int> q;

int main()
{
    int m,n,cnt=0,p;
    memset(book,0,sizeof(book));
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&p);
        if(book[p]) continue;
        else if(q.size() == m)
        {
            book[q.front()] = 0;
            q.pop();
        }
        book[p] = 1;
        q.push(p);
        cnt++;
    }
    printf("%d",cnt);
    return 0;
}