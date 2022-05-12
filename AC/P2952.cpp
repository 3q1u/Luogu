#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    deque<int> q;
    int cnt = 1;
    int s;
    char op;
    int k;

    cin>>s;

    for(int i=1;i<=s;i++)
    {
        cin>>op;
        if(op == 'A')
        {
            cin>>op;
            if(op == 'L') q.push_front(cnt++);
            else q.push_back(cnt++);
        }
        else
        {
            cin>>op>>k;
            if(op == 'L')
            {
                while(k--) q.pop_front();
            }
            else
            {
                while(k--) q.pop_back();
            }
        }
    }
    deque<int>::iterator it;
    for(it=q.begin();it!=q.end();it++) cout<<*it<<endl;
    return 0;
}