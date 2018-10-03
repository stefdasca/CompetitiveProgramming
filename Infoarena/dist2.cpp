#include<bits/stdc++.h>
using namespace std;
ifstream f("dist2.in");
ofstream g("dist2.out");
int n;
struct axx
{
    int x,y;
};
axx v[100002];
int maxi[100002];
int mini[100002];
bool cmp(axx a, axx b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
bool check(int dist)
{
    int a=1;
    for(int i=1;i<=n;++i)
    {
        while(a<=n && v[a].x-v[i].x<dist)
            ++a;
        if(a>n)
            return 0;
        int xx=abs(v[i].y-maxi[a]);
        int yy=abs(v[i].y-mini[a]);
        if(xx>=dist || yy>=dist)
            return 1;
    }
    return 0;
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i].x>>v[i].y;
    sort(v+1,v+n+1,cmp);
    maxi[n]=mini[n]=v[n].y;
    for(int i=n-1;i>=1;--i)
        maxi[i]=max(maxi[i+1],v[i].y),mini[i]=min(mini[i+1],v[i].y);
    int b=0;
    int e=2000000;
    int sol=0;
    while(b<=e)
    {
        int mid=(b+e)/2;
        if(check(mid))
            sol=mid,b=mid+1;
        else
            e=mid-1;
    }
    g<<sol;
    return 0;
}
