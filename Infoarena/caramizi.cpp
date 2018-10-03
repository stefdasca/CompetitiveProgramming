#include<bits/stdc++.h>
using namespace std;
ifstream f("caramizi.in");
ofstream g("caramizi.out");
int n,m;
int frq[1000002],maxx,nr;
long long s,max1[1000002],ct,cp[1000002];
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        f>>nr,frq[nr]++,maxx=max(maxx,nr);
    ct=0;
    for(int i=1;i<=maxx;++i)
    {
        max1[i]=max1[i-1];
        ct+=frq[i-1];
        s+=1ll*frq[i-1]*(i-1);
        max1[i]=max(max1[i],1ll*(n-ct)*i+s-s%i);
    }
    s+=1ll*frq[maxx]*maxx;
    for(int i=maxx+1;i<=1000000;++i)
        max1[i]=max(max1[i-1],s-s%i);
    for(int i=s/maxx;i>=1;--i)
        cp[i]=max(cp[i+1],s-s%i);
    for(int i=1;i<=m;++i){
        int x;
        f>>x;
        if(x<=1000000)
            g<<max1[x]<<'\n';
        else
            g<<cp[s/x+1]<<'\n';
    }
    return 0;
}
