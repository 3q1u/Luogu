#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> a;
    int b;
    while(cin>>b)
    {
        if(b == 0)
            break;
        a.push(b);
    }
    while(!a.empty())
    {
        cout<<a.top()<<" ";
        a.pop();
    }
    return 0;
}