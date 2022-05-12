#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
priority_queue<string, vector<string>, greater<string>> q;

bool match(string a,string b)
{
    int len=b.size(),cnt=0;
    for(int i=0;i<len;i++)
    {
        if(a[i]==b[i]) cnt++;
    }
    return (cnt==len);
}

int main()
{
    int n;
    string temp,t;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>temp;
        q.push(temp);
    }
    cin>>t;
    while(!q.empty())
    {
        if(match(q.top(),t))
        cout<<q.top()<<endl;
        q.pop();
    }
    return 0;
}