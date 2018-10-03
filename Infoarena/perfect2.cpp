/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
#define eps 1e-3
using namespace std;
ifstream f("perfect2.in");
ofstream g("perfect2.out");
int c,n;
int xx,yy;
int minl,maxl,minc,maxc;
struct pd
{
    double p;
    int xz,yz;
};
pd v[200002];
int gcd(int a, int b)
{
    while(b)
    {
        int c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int main()
{
    f>>c;
    f>>n;
    f>>xx>>yy;
    minl=maxl=xx;
    minc=maxc=yy;
    int nrp=0;
    for(int i=2;i<=n;++i)
    {
        f>>v[i-1].xz>>v[i-1].yz;
        if(v[i-1].xz==xx)
            v[i-1].p=10000000.0;
        else
            v[i-1].p=(double)(v[i-1].yz-yy+0.0)/(0.0+v[i-1].xz-xx);
        minl=min(minl,v[i-1].xz);
        maxl=max(maxl,v[i-1].xz);
        minc=min(minc,v[i-1].yz);
        maxc=max(maxc,v[i-1].yz);
        if(gcd(abs(xx-v[i-1].xz),abs(yy-v[i-1].yz))==1)
            ++nrp;
    }
    if(c==1){
        g<<minl<<" "<<minc<<" "<<maxl<<" "<<maxc<<'\n';
        return 0;
    }
    g<<nrp;
    return 0;
}
