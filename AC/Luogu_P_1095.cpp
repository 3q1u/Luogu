#include <bits/stdc++.h>
using namespace std;

int m,s,t;
using res = pair<bool,int>;

res work()
{
    int mgc=0,run=0;
    bool esc=0;
    for(int i=1;i<=t;i++)
    {
        run += 17;
        if(m >= 10) 
        {
            mgc += 60;
            m -= 10;
        }
        else m += 4;
        run = max(run,mgc);
        if(run > s)
        {
            esc = 1;
            return make_pair(esc,i);
        }
    }
    return make_pair(esc,run);
}

int main()
{
    scanf("%d %d %d",&m,&s,&t);
    res out=work();

    printf("%s\n%d",out.first?"Yes":"No",out.second);
    return 0;
}