#include <stdio.h>
#include <cctype>
using namespace std;

inline int read(){
	int f=1,sum=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))sum=sum*10+(ch^48),ch=getchar();
	return f*sum;
}

int main()
{
    int n=read(),ans=read();
    for(int i=2;i<=n;i++)
        ans ^= read();
    printf("%d",ans);
    return 0;
}