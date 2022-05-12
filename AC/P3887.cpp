#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int X=0,w=0; char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    return w?-X:X;
}
priority_queue<int> k,d,m,f;
int main()
{
    int K=read(),D=read(),M=read(),F=read(),q;
    for(int i=1;i<=K;i++) k.push(read());
    for(int i=1;i<=D;i++) d.push(read());
    for(int i=1;i<=M;i++) m.push(read());
    for(int i=1;i<=F;i++) f.push(read());
    q=read();
    int a,b,c;
    for(int i=1;i<=q;i++)
    {
        a=read();
        b=read();
        c=read();
        int sum=0;
        sum+=k.top();
        k.pop();
        for(int i=1;i<=a;i++) {sum+=d.top();d.pop();}
        for(int i=1;i<=b;i++) {sum+=m.top();m.pop();}
        for(int i=1;i<=c;i++) {sum+=f.top();f.pop();}
        printf("%.2lf\n",sum/11.0);
    }
    return 0;
}