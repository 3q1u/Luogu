#include <bits/stdc++.h>
using namespace std;
char num[14];
int main()
{
    scanf("%s",num);
    int sum=0,i=0;
    bool f=0;
    for(auto c:num)
    {
        if(i == 9) break;
        if(isdigit(c))
        {
            i++;
            sum += (c^48)*i;
        }
    }
    if((sum%=11) == 10)
    {
        if(num[12] == 'X') f=1;
        else num[12] = 'X';
    }
    else
    {
        if((num[12]^48) == sum) f=1;
        else num[12] = sum+48;
    }
    printf("%s",f?"Right":num);
    return 0;
}