#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <sys/types.h>

using namespace __gnu_pbds;
using std::cin;
using std::greater;
struct node
{
    int sal, id;
    node(int s, int i) : sal(s), id(i) {}
    bool operator >(node j) const
    {
        return sal == j.sal ? id > j.id : sal > j.sal;
    }
};

tree<node, null_type, greater<node>, rb_tree_tag, tree_order_statistics_node_update> Tr, tmp;

int main()
{
    int n, m, ans = 0;
    cin >> n >> m;
    int s = 0, k;
    char x;
    while(n--)
    {
        cin >> x;
        cin >> k;
        if(x == 'I')
        {
            k += s;
            if(k >= m)
                Tr.insert(node(k, n));
        }
        else if(x == 'A')
        {
            s -= k;
            m -= k;
        }
        else if(x == 'S')
        {
            s += k;
            m += k;
            Tr.split(node(m, -1), tmp);
            ans += tmp.size();
        }
        else if(x == 'F')
            printf(k > Tr.size() ? "-1\n" : "%d\n",Tr.find_by_order(k-1)->sal - s);
    }
    printf("%d\n", ans);
    return 0;
}