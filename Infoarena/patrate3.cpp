#include<bits/stdc++.h>
using namespace std;
ifstream f("patrate3.in");
ofstream g("patrate3.out");
int n,sol;
double x,y;
struct pct
{
    int x,y;
};
pct v[1002];
bool test(pct a, pct b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
bool Cautbin(int x,int y)
{
    int b=1;
    int e=n;
    while(b<=e)
    {
        int m=(b+e)/2;
        if(v[m].x==x && v[m].y==y)
            return 1;
        else
            if(v[m].x<x || v[m].x==x && v[m].y<y)
                b=m+1;
            else
                e=m-1;
    }
    return 0;
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
    {
        f>>x>>y;
        v[i].x=2*round(x*10000);
        v[i].y=2*round(y*10000);
    }
    sort(v+1,v+n+1,test);
    for(int i=1;i<n;++i)
        for(int j=i+1;j<=n;++j)
        {
            int midx=(v[i].x+v[j].x)/2;
            int midy=(v[i].y+v[j].y)/2;
            int dx=midx-v[i].x;
            int dy=midy-v[i].y;
            if(Cautbin(midx-dy,midy+dx)+Cautbin(midx+dy,midy-dx)==2)
                ++sol;
        }
    g<<sol/2<<'\n';
}
