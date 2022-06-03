#include <iostream>
#include <string>
using namespace std;

inline char FBI(string str)
{
    int one=0,zero=0;
    for(auto c : str)
    {
        if(c == '1') one++;
        else zero++;
    }
    if(!one && zero) return 'B';
    else if(one && !zero) return 'I';
    else return 'F';
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