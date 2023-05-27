#include <bits/stdc++.h>
using namespace std;

int nums[5005], n;
vector<int> g;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &nums[i]);
    
    for(int i = 0; i < n; i++)
    {
        auto x = lower_bound(g.begin(), g.end(), nums[i]);
        if(x == g.end()) g.push_back(nums[i]);
        else *x = nums[i];
    }
    printf("%d", g.size());
    return 0;
}