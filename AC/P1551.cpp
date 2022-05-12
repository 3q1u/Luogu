#include <cstdio>
using namespace std;

const int MAXN = 1e4+5;
int parent[MAXN];

void init(int);
int findParent(int);
void mergeSet(int,int);
void isInTheSameSet(int,int);

int main()
{
    int n,m,p,x,y;
    scanf("%d%d%d",&n,&m,&p);
    init(n);
    for(int i = 1;i <= m;i++) {scanf("%d%d",&x,&y);mergeSet(x,y);}
    for(int i = 1;i <= p;i++) {scanf("%d%d",&x,&y);isInTheSameSet(x,y);}
    return 0;
}

void init(int num)
{
    for(int i = 1;i <= num;i++)
    {
        parent[i] = i;
    }
}

int findParent(int key)
{
    if(parent[key] == key) return key;
    return parent[key] = findParent(parent[key]);
}

void mergeSet(int x,int y)
{
    parent[findParent(y)] = findParent(x);
}

void isInTheSameSet(int x,int y)
{
    if(findParent(x) == findParent(y)) printf("Yes\n");
    else printf("No\n");
}