/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("aiacuxor.in");
ofstream g("aiacuxor.out");
unsigned n,q,m,v[1002],True[10000002],Len[1000002],XorL[1000002],SumLen[1000002],x,y,a,b,c,d,ans,xx,yy;
int main()
{
    f>>n>>q>>m;
    for(int i=0;i<m;++i)
        f>>v[i];
    for(int i=0;i<n;++i)
        True[i]=(v[i/m]^v[i%m])+i;
    for(int i=1;i<=n;++i)
        Len[i]=Len[i-1]^True[i-1];
    for(int i=1;i<=n;++i)
        XorL[i]=XorL[i-1]^Len[i-1]^Len[n-i+1],SumLen[i]=SumLen[i-1]^XorL[i];
    f>>x>>y>>a>>b>>c>>d;
    for(;q;--q)
    {
        ans=SumLen[y]^SumLen[x-1];
        g<<ans<<'\n';
        xx=(x*a+y*b)%n+1;
        yy=(y*c+(ans%n)*d)%n+1;
        if(xx>yy)
            swap(xx,yy);
        x=xx;
        y=yy;
    }
    return 0;
}
