#include <iostream>
#include <string>
using namespace std;

bool book[1001]; //默认为0

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string tmp,dif[1001];
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>dif[i];
    for(int i=2;i<=m;i++)
    {
        for(int j=1;j<=n;j++) 
        {
            cin>>tmp;
            if(dif[j] != tmp) book[j] = true;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(book[i]) cout<<"* ";
        else cout<<dif[i]<<" ";
    }
    return 0;
}