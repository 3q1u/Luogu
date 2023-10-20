#include <bits/stdc++.h>
using namespace std;

int a[8], b[8], tot, n, t;

int main()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i] >> b[i];
        tot += 100 / a[i] * b[i];
    }
    cin >> t;
    if(tot >= t)
    {
        cout << "Already Au." << endl;
        return 0;
    }
    for(int i=1; i<=n; i++)
    {
        if(tot + 100 - 100/a[i] * b[i] < t)
        {
            cout << "NaN" << endl;
            continue;
        }
        cout << (t-tot - 1) / (100/a[i]) + 1 << endl;
    }
    return 0;
}
