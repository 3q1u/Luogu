#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string::iterator it;
    string a;
    cin>>a;
    for(it=a.begin();it!=a.end();it++) cout<<(char)toupper(*it);
    return 0;
}