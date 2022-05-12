#include <iostream>
#include <string>
using namespace std;

void findRoot(string a,string b)
{
    if(a.size())
    {
        int p;
        char root = b[b.size()-1];
        cout << root;
        p = a.find(root);
        findRoot(a.substr(0,p),b.substr(0,p));
        findRoot(a.substr(p+1),b.substr(p,b.size()-p-1));
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a,b;
    cin>>a>>b;
    findRoot(a,b);
    return 0;
}