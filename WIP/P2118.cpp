#include <iostream>
using std::cout;
using std::cin;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b,l;
    cin>>a>>b>>l;
    int num = l,den = 1;

    int i = 1,j = 1;
    while(i<=l && j<=l)
    {
        if(i*b <= j*a)
        {
            if(i*den < j*num) {den = j;num = i;}
            i++;
        }
        else j++;
    }
    cout<<num<<" "<<den;
    return 0;
}