#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<double> male,female;
vector<double>::iterator it;
bool sex[10004];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t,n;
    double tmp;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        male.clear(),female.clear();
        for(int i=0;i<n;i++) cin>>sex[i];
        for(int i=0;i<n;i++)
        {
            cin>>tmp;
             if(sex[i] == 1) male.push_back(tmp);
             else female.push_back(tmp);
        }
        sort(male.begin(),male.end()),sort(female.begin(),female.end());
        for(it = female.begin();it!=female.end();it++) cout<<*it<<" ";
        cout<<endl;
        for(it = male.begin();it!=male.end();it++) cout<<*it<<" ";
        cout<<endl;
    }
    return 0;
}