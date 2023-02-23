#include <cstdio>
#include <cctype>

using std::fread;
using std::printf;
using std::isdigit;

struct FastIn
{

    static char buf[1<<21];
    char *p1 = buf, *p2 = buf;
    
    char getchar()
    {
        if(p1 == p2)
            p2 = (p1 = buf) + fread(buf, 1, 1<<21, stdin);
        return *(p1++);
    }

    template <typename T>
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