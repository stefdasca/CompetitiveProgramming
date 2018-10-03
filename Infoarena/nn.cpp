/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("nn.in");
ofstream g("nn.out");
int n,m;
struct points
{
    long double x,y;
};
points v[100002];
bool cmp(points a, points b)
{
    return a.y/a.x<b.y/b.x;
}
long double xa,ya,xb,yb;
int nq;
int cb1(long double x, long double y)
{
    int b=1;
    int e=n;
    int mid;
    while(b<=e)
    {
        mid=(b+e)/2;
        if(v[mid].y/v[mid].x>=y/x && y/x>v[mid-1].y/v[mid-1].x)
            return mid;
        else
            if(v[mid].y/v[mid].x>=y/x)
                e=mid-1;
            else
                b=mid+1;
    }
}
int cb2(long double x, long double y)
{
    int b=1;
    int e=n;
    int mid;
    while(b<=e)
    {
        mid=(b+e)/2;
        if(v[mid].y/v[mid].x<=y/x && y/x<v[mid+1].y/v[mid+1].x)
            return mid;
        else
            if(v[mid].y/v[mid].x>y/x)
                e=mid-1;
            else
                b=mid+1;
    }
    return mid;
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        f>>v[i].x>>v[i].y;
    sort(v+1,v+n+1,cmp);
    for(int i=1;i<=m;++i)
    {
        f>>xa>>ya>>xb>>yb;
        if(ya/xa>yb/xb)
        {
            swap(xa,xb);
            swap(ya,yb);
        }
        nq=i;
        int sol1=cb1(xa,ya);
        int sol2=cb2(xb,yb);
        g<<max(0,sol2-sol1)<<'\n';
    }
    return 0;
}
