#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int a,b,max=8,day=0;
    for(int i=1;i<=7;i++)
    {
        cin>>a>>b;
        if((a+b)>max) {max=a+b;day=i;}
    }
    cout<<day;
    return 0;
}