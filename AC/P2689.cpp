#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int a1,a2,b1,b2,n,i,j,s=0;
    cin>>a1>>a2>>b1>>b2>>n;
    for(i=1;i<=n;i++){
        if(a1==b1&&a2==b2){cout<<s;return 0;}
        char c;cin>>c;
        if(c=='N'&&b1-a1>0)++s,++a1;
        else if(c=='E'&&b2-a2>0)++s,++a2;
        else if(c=='S'&&a1-b1>0)++s,--a1;
        else if(c=='W'&&a2-b2>0)++s,--a2;
    }cout<<-1;
    return 0;
}