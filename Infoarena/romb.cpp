#include<bits/stdc++.h>
using namespace std;
ifstream f("romb.in");
ofstream g("romb.out");
long long t;
long long dx,dy,k,cx,cy;
double dist(double xa, double ya, double xb, double yb)
{
    return (xa-xb)*(xa-xb)+(ya-yb)*(ya-yb);
}
long long DI(long long zona,double dx, double dy, double cx, double cy)
{
    if(k==0)
        return zona;
    --k;
    if(cx*dy < cy*dx)
    {
        if(cx*dy < (-dx)*cy)
            DI(4*zona-2,dx/2,dy/2,cx+dx/2,cy);
        else
            DI(4*zona-3,dx/2,dy/2,cx,cy-dy/2);
    }
    else
    {
        if(cx*dy > (-dx)*cy)
            DI(4*zona,dx/2,dy/2,cx-dx/2,cy);
        else
            DI(4*zona-1,dx/2,dy/2,cx,cy+dy/2);
    }
}
int main()
{
    f>>t;
    for(int i=1;i<=t;++i)
    {
        f>>dx>>dy>>k>>cx>>cy;
        g<<DI(1,dx,dy,cx,cy)<<'\n';
    }
    return 0;
}
