#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin>>str;
    int pos1 = str.find("\\n");
    int pos2 = str.find("\\r");
    if(pos1 != string::npos)
        if(pos2 != string::npos) cout<<"windows";
        else cout<<"linux";
    else cout<<"mac";
    return 0;
}