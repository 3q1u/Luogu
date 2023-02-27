#include <climits>
#include <iostream>
#include <string>
#define min(x, y) x < y ? x : y

const int MAXN = 55;

int color(const std::string& buf, const char& c)
{
    int ret = 0;
    for(auto ch : buf)
    {
        if(ch != c)
            ret++;
    }
    return ret;
}

int main()
{
    using std::cin;
    using std::cout;

    int w[MAXN] = {0}, b[MAXN] = {0}, r[MAXN] = {0};
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++)
    {
        std::string tmp = "";
        cin >> tmp;

        w[i] = w[i - 1] + color(tmp, 'W');
        b[i] = b[i - 1] + color(tmp, 'B');
        r[i] = r[i - 1] + color(tmp, 'R');
    }

    int ans = 0x3f3f3f3f;

    for(int i = 1; i <= n - 2; i++)
    {
        for(int j = i + 1; j <= n - 1; j++)
        {
            int cur = w[i] + b[j] - b[i] + r[n] - r[j];
            ans = min(ans, cur);
        }
    }

    cout << ans;
}