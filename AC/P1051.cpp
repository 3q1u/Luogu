#include <iostream>
#include <memory>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string name,maxName;
    int f,r,a;
    char w,c;
    int n,sum=0,max=0;
    cin>>n;
    while(n--)
    {
        int p=0;
        cin>>name>>f>>r>>c>>w>>a;
        if(f>80 && a>=1) p+=8000;
        if(f>85 && r>80) p+=4000;
        if(f > 90) p+=2000;
        if(f>85 && w=='Y') p+=1000;
        if(r>80 && c=='Y') p+=850;
        if(p > max)
        {
            max = p;
            maxName = name;
        }
        sum += p;
    }
    cout<<maxName<<endl<<max<<endl<<sum;
    return 0;
}