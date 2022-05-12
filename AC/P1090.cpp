#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int X=0,w=0; char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    return w?-X:X;
}
inline void write(int x)
{
     if(x<0) putchar('-'),x=-x;
     if(x>9) write(x/10);
     putchar(x%10+'0');
}
int main()
{
    priority_queue<int,vector<int>,greater<int>> q;
    int n=read(),c,d,t=0;
    for(int i=1;i<=n;i++)
    {
        c=read();
        q.push(c);
    }
    while(q.size()>1)
    {
        c=q.top();
        q.pop();
        d=q.top();
        q.pop();
        t+=c+d;
        q.push(c+d);
    }
    write(t);
    return 0;
}