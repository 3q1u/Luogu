#include <cstdio>
#include <stack>
#include <cctype>
using namespace std;

int n;
stack<int> s;

template<typename T>
inline void read(T& s)
{
    s=0;T f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-'){f=-1;ch=getchar();}}
    while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();}
    s *= f;
}

void insert(int l,int r)
{
    for(int i=l;i<=r;i++)
        s.push(i);
}

int query(int k)
{
    int ans=0;
    for(int i=1;i<=k;i++)
    {
        ans += s.top();
        s.pop();
    }
    return ans;
}

int main()
{
    read(n);
    for(int i=1;i<=n;i++)
    {
        int op;
        read(op);
        if(op == 1)
        {
            int l,r;
            read(l),read(r);
            insert(l,r);
        }
        else
        {
            int k;
            read(k);
            printf("%d\n",query(k));
        }
    }
    return 0;
}