#include <iostream>
#include <string>
#include <cctype>
using namespace std;

const int CNT[] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a;
    int ans = 0;
    getline(cin,a);
    for(int i=0;i<a.size();i++)
    {
        if(islower(a[i])) ans += CNT[(unsigned)a[i] - 'a'];
        if(a[i] == ' ') ans++;
    }
    cout<<ans;
    return 0;
}