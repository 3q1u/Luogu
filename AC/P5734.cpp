#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    int num;
    cin>>num>>a;
    for(int i=1;i<=num;i++)
    {
        int aa;
        string temp;
        cin>>aa;
        if(aa == 1)
        {
            cin>>temp;
            a += temp;
            cout<<a<<endl;
        }
        else if(aa == 2)
        {
            int b,c;
            cin>>b>>c;
            a=a.substr(b,c);
            cout<<a<<endl;
        }
        else if(aa == 3)
        {
            int b;
            cin>>b>>temp;
            a.insert(b,temp);
            cout<<a<<endl;
        }
        else if(aa == 4)
        {
            cin>>temp;
            if(a.find(temp) < a.length())
                cout<<a.find(temp)<<endl;
            else
                cout<<"-1\n"; 
        }
    }
    return 0;
}