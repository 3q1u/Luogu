#include <cstdio>
#include <cctype>
#include <numeric>
#include <random>

using ll = long long;

std::random_device rseed{};
std::mt19937 rnd(rseed());

const int MAXN = 5 * 1e5 + 6;

template <typename T>
void read(T &x)
{
    T f = 1; x = 0; char ch = getchar();
    while(!isdigit(ch))
    {
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(isdigit(ch))
    {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }

    x *= f;
}

int n, m, q;
ll sc[MAXN], w[MAXN], cur[MAXN];

int main()
{
    // freopen("data.in", "r", stdin);
    read(n), read(m);

    for(int i = 1; i <= n; ++i)
        w[i] = rnd();
    
    ll std = std::accumulate(w + 1, w + n + 1, 0LL);
    ll sum = 0LL;

    while(m--)
    {
        int u, v;
        read(u), read(v);
        cur[v] += w[u];
        sc[v] = cur[v];
        sum += w[u];
    }

    read(q);
    while(q--)
    {
        int t;
        read(t);
        switch (t)
        {
            case 1:
            {
                int u, v;
                read(u), read(v);
                cur[v] -= w[u];
                sum -= w[u];
                break;
            }
            case 2:
            {
                int v;
                read(v);
                sum -= cur[v];
                cur[v] = 0;
                break;
            }
            case 3:
            {
                int u, v;
                read(u), read(v);
                cur[v] += w[u];
                sum += w[u];
                break;
            }
            case 4:
            {
                int v;
                read(v);
                sum += sc[v] - cur[v];
                cur[v] = sc[v];
                break;
            }
            default:
            {
                break;
            }
        }

        printf("%s\n", (sum == std) ? "YES" : "NO");
    }
}
