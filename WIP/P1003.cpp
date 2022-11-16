#include <bits/stdc++.h>
#include <cstdio>
#include <sched.h>
using namespace std;

inline char gc()
{
    static char buf[1<<21],*p1=buf,*p2=buf;
    return (p1==p2) && (p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;
}

int read()
{
    int s=0,f=1;char c=gc();
    while(!isdigit(c)) {if(c=='-') f=-1;c=gc();}
    while(isdigit(c)) {s=(s<<3)+(s<<1)+(c^48);c=gc();}
    return s*f;
}

struct cpt
{
    int x1,x2,y1,y2;
}a[int(1e4+5)];

int main()
{
    int n=read();
    
}