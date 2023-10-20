#include <bits/stdc++.h>

constexpr double eps = 1e-6;

double coe[14];
double l, r;
int n;

double f(double x)
{
    double ret = 0;
    for(int i=n; ~i; i--)
        ret = ret*x + coe[i];
    return ret;
}

int main()
{
    std::cin >> n >> l >> r;
    for(int i=n; i>=0; i--)
        std::cin >> coe[i];

    while(fabs(r-l) > eps)
    {
        double mid = (l+r)/2;
        if(f(mid+eps)>f(mid-eps))
            l = mid;
        else r = mid;
    }
    std::cout << l;
    return 0;
}