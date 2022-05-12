#include <bits/stdc++.h>
#define MOD 10000
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b,s=0;
    char ch;
    cin>>a;
    while(cin>>ch)
    {
        cin>>b;
        if(ch == '*') a=(a*b) % MOD;
        else {s=(s+a) % MOD;a=b;}
    }
    cout<<(s+a) % MOD;
    return 0;
}