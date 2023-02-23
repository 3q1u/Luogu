#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>

using std::fread;
using std::printf;
using std::isdigit;
using std::vector;

const int MAXN = 1e5 + 5, MAXM = 2 * 1e6 + 5;

struct FastIn
{

    char buf[1<<21];
    char *p1 = buf, *p2 = buf;
    
    char getchar()
    {
        if(p1 == p2)
            p2 = (p1 = buf) + fread(buf, 1, 1<<21, stdin);
        return *(p1++);
    }

    template <typename T = int>
    T operator () ()
    {
        T s = 0, f = 1;
        char ch = getchar();
        while(!isdigit(ch))
        {
            if(ch == '-')
                f = -1;
            ch = getchar();
        }
        while(isdigit(ch))
        {
            s = (s << 3) + (s << 1) + (ch ^ 48);
            ch = getchar();
        }
        return s * f;
    }
} read;

class STable
{
    public:

        int n;
        int dp[MAXN][20];
        int log[MAXN];

        STable() : STable(0) {}

        STable(const int& n) : n(n)
        {
            memset(dp, 0, sizeof dp);
            memset(log, 0, sizeof log);

            log[1] = 0;
            for(int i = 2; i <= n; i++)
                log[i] = log[i >> 1] + 1;
        }

        void work(int container[])
        {
            for(int i = 1; i <= n; i++)
                dp[i][0] = container[i];

            for(int j = 1;j <= log[n]; j++)
            for(int i = 1;i <= n - (1 << j) + 1; i++)
                dp[i][j] = std::max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
        }

        int query(int k, int r)
        {
            int l = log[r - k + 1];
            return std::max(dp[k][l], dp[r - (1 << l) + 1][l]);
        }
};

int main()
{
    int a[MAXN];
    int n = read(), m = read();
    STable st(n);

    for(int i = 1; i <= n; i++)
        a[i] = read();
    
    st.work(a);

    while(m--)
    {
        int l = read(), r = read();
        printf("%d\n", st.query(l, r));
    }
}