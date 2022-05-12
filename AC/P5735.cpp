#include <cstdio>
#include <cmath>
#define d double
using namespace std;

inline d qPow(d w) {return w*w;}
inline d dis(d x1,d x2,d y1,d y2) {return sqrt(qPow(x1-x2) + qPow((y1-y2)));}

int main()
{
    d x1,x2,x3,y1,y2,y3,sum = 0;
    scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
    sum += dis(x1,x2,y1,y2);
    sum += dis(x1,x3,y1,y3);
    sum += dis(x2,x3,y2,y3);
    printf("%.2lf",sum);
    return 0;
}