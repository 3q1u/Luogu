#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int i;
    ll num=0;
    string a;
    getline(cin,a);
    for(i=0;i<a.length();i++)
    {
        if(a[i] == ' ')
            continue;
        num++;
    }
    cout<<num;
    return 0;
}