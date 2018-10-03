#include<bits/stdc++.h>
using namespace std;
ifstream f("munte7.in");
ofstream g("munte7.out");
int n,v[200002];
int lmaxs[200002],lmaxd[200002];
int d[200002],k=1;
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i];
    d[1]=1;
    lmaxs[1]=lmaxd[n]=1;
    maxa[1]=v[1];
    maxb[n]=v[n];
    for(int i=2;i<=n;++i)
    {
        int b=1;
        int e=k;
        while(b<=e)
        {
            int m=(b+e)/2;
            if(v[d[m]]<=v[i])
                b=m+1;
            else
                e=m-1;
        }
        if(b==k+1)
            ++k;
        d[b]=i;
        lmaxs[i]=k;
    }
    for(int i=1;i<=k;++i)
        d[i]=0;
    d[1]=n;
    k=1;
    for(int i=n-1;i>=1;--i)
    {
        int b=1;
        int e=k;
        while(b<=e)
        {
            int m=(b+e)/2;
            if(v[d[m]]<=v[i])
                b=m+1;
            else
                e=m-1;
        }
        if(b==k+1)
            ++k;
        d[b]=i;
        lmaxd[i]=k;
    }
    int solmin=0;
    for(int i=1;i<=n;++i)
        solmin=max(solmin,lmaxd[i]+lmaxs[i]);
    g<<n-solmin+1;
    return 0;
}
