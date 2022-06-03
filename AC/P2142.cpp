#include <bits/stdc++.h>
using namespace std;
string sub(string a,string b);
int main()
{
    string m,n;
    cin>>m>>n;
    cout<<sub(m,n);
    return 0;   
}
string sub(string a,string b)
{
    int l=max(a.length(),b.length());
    while(a.length()<l)
        a='0'+a;
    while(b.length()<l)
        b='0'+b;
    int flag=0;
    if(a<b)
    {
        swap(a,b);
        flag=1;
    }
    int p=0;
    string ans="";
    for(int i=l-1;i>=0;i--)
    {
        p=a[i]-b[i]-p;
        if(p<0)
        {
            ans=static_cast<char>(p+48+10);
            p=1;
        }
        else
        {
            p=static_cast<char>(p+48);
            p=0;
        }
    }
    while(ans.length()>1&&ans[0]=='0')
        ans.erase(0,1);
    if(flag)
        ans='-'+ans;
    return ans;
}