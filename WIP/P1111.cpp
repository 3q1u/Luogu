#include <cstdio>
#include <queue>
using namespace std;

struct edge
{
    int u,v,time;
    edge(){};
    edge(int u,int v,int time):u(u),v(v),time(time){};
    bool operator<(edge a) {return this->time > a.time;}
};

class djset
{
    public:
        void init();
};

priority_queue<edge> q;

int main()
{
    return 0;
}