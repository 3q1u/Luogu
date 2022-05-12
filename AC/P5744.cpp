#include <iostream>
#include <string>
#define reg register
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    reg string name;
    reg int age,score;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>name>>age>>score;
        age++;
        if((score+score/5) >= 600) score = 600;
        else score = score/5*6;
        cout<<name<<" "<<age<<" "<<score<<endl;
    }
    return 0;
}