#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mk std::make_pair

using node = std::pair<int,int>;
using namespace __gnu_pbds;
tree<int, null_type, std::greater<int>, rb_tree_tag, tree_order_statistics_node_update> tr, x;

int n, min, gap = 0, ans = 0;

int main()
{
    scanf("%d %d", &n, &min);
    while(n--)
    {
        char op; int k;
        scanf("%c %d", &op, &k);
        switch(op)
        {
            case 'I':
            {
                if((k += gap) >= min)
                    tr.insert(k);
            }
            case 'A':
            {
                gap -= k;
                min -= k;
                break;
            }
            case 'S':
            {
                gap += k;
                min += k;
                tr.split(min, x);
                ans += x.size();
                break;
            }
            case 'F':
            {
                printf(k > tr.size() ? "-1\n" : "%d\n", *tr.find_by_order(k-1) - gap);
                break;
            }
            default:
                break;
        }
        // printf("%d\n", static_cast<int>(tr.size()));
    }
    printf("%d", ans);
}