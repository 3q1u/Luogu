#include <cstdio>
// #define DEBUG
using namespace std;

int main()
{
    int k,f=0;
    scanf("%d",&k);

    for(int i=10000;i<=30000;++i)
    {
        int sub1=i/100,sub2=((i/10)%1000),sub3=i%1000;
        #ifdef DEBUG
        printf("%d %d %d\n",sub1,sub2,sub3);
        if(i == 22555) getchar();
        #endif
        if((sub1%k==0) && (sub2%k==0) && (sub3%k==0))
            printf("%d\n",i),f=1;
    }
    if(!f) printf("No");
}