#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
const int MAXN = 1500;
using namespace std;

int n,k;
int pos[10]; 
string str,ans = "0";

bool cmp(string a,string b) 
{
	
	if(a.size() < b.size())	return true;
	else if(a.size() > b.size()) return false;
	else return a<b;
}
string mul(string a,string b)
{
	string ans;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int c[1000]={0}, k = a.size()+b.size()+1;
    for(int i = 0; i < a.size(); i++)
        for(int j = 0; j < b.size(); j++){
            c[i+j] += (a[i]-'0')*(b[j]-'0');
            c[i+j+1] += c[i+j]/10;
            c[i+j] %= 10;
        }
    while(c[k]==0 && k>=0) k--;
    while(k >= 0)
        ans.push_back(c[k--]+'0');
    return ans;
}

void dfs(int p,int x)
{
	if(x == 0)
	{
		pos[k+1] = str.size();
		string m="1";
		for(int i=0;i<=k;i++) m = mul(m,str.substr(pos[i],pos[i+1]-pos[i]));
		if(cmp(ans,m)) ans = m;
	}
	else
	{
		for(int i=pos[p-1]+1;i<str.size();i++)
		{
			pos[p] = i;
			dfs(p+1,x-1);
		}
	}
}

int main()
{
	memset(pos,0,sizeof(pos));
	cin>>n>>k;
	cin>>str;
	pos[0] = 0;
	dfs(1,k);
	cout << ans;
	return 0;
}