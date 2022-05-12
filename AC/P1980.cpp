#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,x;
    cin>>n>>x;
    stringstream s;
    for(int i=1;i<=n;i++) s<<i;
    string st=s.str();
    cout<<count(st.begin(),st.end(),x+'0');
    return 0;
}