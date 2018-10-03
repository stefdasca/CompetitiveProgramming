#include<bits/stdc++.h>
using namespace std;
ifstream f("xcmmdc.in");
ofstream g("xcmmdc.out");
int n,m,k,q,v[1002],rmq[12][1002][1002],a;
int LG[1002];
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
int vf(int lat, int xs, int ys)
{
    a=LG[lat];
    int BD=gcd(rmq[a][xs][ys],gcd(rmq[a][xs][ys+lat-(1<<a)],gcd(rmq[a][xs+lat-(1<<a)][ys+lat-(1<<a)],rmq[a][xs+lat-(1<<a)][ys])));
    return BD;
}
int bsmin(int L, int C)
{
    int b=1;
    int e=min(n-L+1,m-C+1);
    while(b<=e)
    {
        int mi=(b+e)/2;
        int val=vf(mi,L,C);
        if(val>k)
            b=mi+1;
        else
        {
            if(val==k && (vf(mi-1,L,C)>k || mi==1))
                return mi;
            e=mi-1;
        }
    }
    return 0;
}
int bsmax(int L,int C)
{
    int b=1;
    int e=min(n-L+1,m-C+1);
    while(b<=e)
    {
        int mi=(b+e)/2;
        int val=vf(mi,L,C);
        if(val>=k)
        {
            if(val==k && (vf(mi+1,L,C)<k || mi==min(n-L+1,m-C+1)))
                return mi;
            b=mi+1;
        }
        else
            e=mi-1;
    }
    return 0;
}
int main()
{
    f>>n>>m>>k>>q;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            f>>rmq[0][i][j];
    for(int i=1;(1<<i)<=min(n,m);++i)
        for(int j=1;j<=n-(1<<i)+1;++j)
            for(int p=1;p<=m-(1<<i)+1;++p)
                rmq[i][j][p]=gcd(rmq[i-1][j][p],gcd(rmq[i-1][j][p+(1<<(i-1))],gcd(rmq[i-1][j+(1<<(i-1))][p+(1<<(i-1))],rmq[i-1][j+(1<<(i-1))][p])));
    for(int i=2;i<=1000;++i)
        LG[i]=LG[i/2]+1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            int a=bsmin(i,j);
            int b=bsmax(i,j);
            v[a]++;
            v[b+1]--;
        }
    for(int i=1;i<=min(n,m);++i)
        v[i]+=v[i-1];
    for(int i=1;i<=q;++i)
    {
        int nr;
        f>>nr;
        g<<v[nr]<<'\n';
    }
    return 0;
}
