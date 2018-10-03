/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
#define eps 1e-3
#define sq3 1.7320508
using namespace std;
ifstream f("triang.in");
ofstream g("triang.out");
int n,sol;
struct points
{
    double x,y;
};
points v[1502];
bool eq(double a, double b)
{
    if(max(a-b,b-a)<eps)
        return 1;
    return 0;
}
bool test(points a, points b)
{
    if(eq(a.x,a.y))
        return a.y<b.y;
    return a.x<b.x;
}
points cw(double xa, double ya, double xb, double yb)
{
    swap(xa,ya);
    xa*=-1.00000;
    xa+=xb;
    ya+=yb;
    return {xa,ya};
}
points ccw(double xa, double ya, double xb, double yb)
{
    swap(xa,ya);
    ya*=-1.00000;
    xa+=xb;
    ya+=yb;
    return {xa,ya};
}
bool binsearch(points a)
{
    int b=1;
    int e=n;
    while(b<=e)
    {
        int m=(b+e)/2;
        if(eq(v[m].x,a.x) && eq(v[m].y,a.y))
            return 1;
        else
            if(v[m].x>a.x || eq(v[m].x,a.x) && v[m].y>a.y)
                e=m-1;
            else
                b=m+1;
    }
    return 0;
}
void calculations(points a, points b)
{
    double Xmid=0.50000*(a.x+b.x);
    double Ymid=0.50000*(a.y+b.y);
    double difa=(b.x-Xmid)*sq3;
    double difb=(b.y-Ymid)*sq3;
    points x=cw(difa, difb,Xmid, Ymid);
    points y=ccw(difa, difb, Xmid, Ymid);
    sol+=binsearch(x)+binsearch(y);
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i].x>>v[i].y;
    sort(v+1,v+n+1,test);
    sol=0;
    for(int i=1;i<=n;++i)
        for(int j=i+1;j<=n;++j)
            calculations(v[i],v[j]);
    g<<sol/3;
    return 0;
}
