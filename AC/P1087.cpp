#include <iostream>
#include <string>
using namespace std;

inline char FBI(string str)
{
    auto one = str.find('1');
    auto zero = str.find('0');
    if(one != string::npos)
    {
        if(zero != string::npos) return 'F';
        else return 'I';
    }
    else return 'B';
}

void print(string str)
{
    auto s = str.size();
    if(s > 1)
    {
        print(str.substr(0,s/2));
        print(str.substr(s/2,s/2));
        cout<<FBI(str);
    }
    else cout<<FBI(str);

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    string s;
    cin>>s;
    print(s);
    return 0;
}