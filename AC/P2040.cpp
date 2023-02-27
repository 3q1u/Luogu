#include <cstdio>
#include <algorithm>

static int lit[4][4], min = 9;

void press(const int &x, const int &y)
{
    lit[x][y] ^= 1;
    lit[x+1][y] ^= 1;
    lit[x-1][y] ^= 1;
    lit[x][y+1] ^= 1;
    lit[x][y-1] ^= 1;
}

void dfs(int step)
{
    if(step >= min)
        return ;

    int l = 0;
    for(int i = 1; i <= 3; i++)
    for(int j = 1; j <= 3; j++)
    {
        if(lit[i][j]) l++;
    }

    if(l == 9)
    {
        min = std::min(min, step);
        return ;
    }

    for(int i = 1; i <= 3; i++)
    {
        for(int j = 1; j <= 3; j++)
        {
            press(i,j);
            dfs(step + 1);
            press(i,j);
        }
    }
}

int main()
{
    for(int i = 1; i <= 3; i++)
    for(int j = 1; j <= 3; j++)
        scanf("%d", &lit[i][j]);

    dfs(0);

    printf("%d", min);
}