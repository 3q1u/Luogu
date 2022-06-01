#include <iostream>
#include <string>
using namespace std;

struct node
{
    bool end;
    int cnt; //0表示没有，1表示出现过1次，-1表示出现过多次
    node *ch[26];
    node()
    {
        end = 0;
        cnt = 0;
        for(int i=0;i<26;i++)
            ch[i] = nullptr;
    }
}*root;

void insert(node *u,string s)
{
    for(auto c : s)
    {
        if(u->ch[c-'a'] == 0)
            u->ch[c-'a'] = new node();
        u = u->ch[c-'a'];
    }
    u->cnt = 1;
}

int query(node *u,string s)
{
    for(auto c : s)
    {
        if(u->ch[c-'a'] == 0)
            return 0;
        u = u->ch[c-'a'];
    }
    return u->cnt;
}

void del(node *u,string s)
{
    for(auto c : s)
        u = u->ch[c-'a'];
    u->cnt = -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    root = new node();
    cin>>n;
    string str;
    for(auto i=1;i<=n;i++)
    {
        cin>>str;
        insert(root,str);
    }
    cin>>m;
    for(auto i=1;i<=m;i++)
    {
        cin>>str;
        int r = query(root,str);
        if(!r) cout << "WRONG\n";
        else if(r == -1) cout << "REPEAT\n";
        else {cout << "OK\n";del(root,str);}
    }
    return 0;
}