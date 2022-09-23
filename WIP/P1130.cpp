#include <cstdio>
#include <cctype>
using namespace std;

inline int read()
{
    int s=0,f=1;char ch=getchar();
    while(!isdigit(ch)) {if(ch=='-') f=-1;ch=getchar();}
    while(isdigit(ch)) {s=(s<<3)+(s<<1)+(ch^48);ch=getchar();}
    return s*f;
}



int main()
{

}
