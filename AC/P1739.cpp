#include <string>
#include <iostream>
using namespace std;

int main()
{
    string in;
    int cnt=0;
    getline(cin,in);
    for(auto c:in)
    {
        if(c=='(') cnt++;
        if(c==')')
        {
            if(cnt==0)
            {
                puts("NO");
                return 0;
            }
            cnt--;
        }
    }
    puts(cnt==0?"YES":"NO");
    return 0;
}