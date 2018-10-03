/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("euclid.in");
ofstream g("euclid.out");
int T,n,m,h,w,a[25][405][405],x[405][405],b[25][405][405],de,d[405],r;
int cmmdc(int a,int b)
{
    if(b==0)
        return a;
    return cmmdc(b,a%b);
}
int main()
{
    f>>T;
    for(int i=1;i<=400;i++)
        for(int j=0;j<=10;j++)
            if((1<<j)<=i)
                d[i]=j;
    for(int t=1;t<=T;t++)
    {
        f>>n>>m>>h>>w;
        r=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                f>>b[0][i][j];
        for(int k=1;k<=10;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j+(1<<k)-1<=m;j++)
                    b[k][i][j]=cmmdc(b[k-1][i][j],b[k-1][i][j+(1<<(k-1))]);
        for(int k=0;k<=10;k++)
            if((1<<k)<=w)
                de=k;
        for(int i=1;i<=n;i++)
            for(int j=1;j+w-1<=m;j++)
                a[0][i][j]=cmmdc(b[de][i][j],b[de][i][j+w-(1<<de)]);
        for(int k=1;k<=10;k++)
            for(int i=1;i+(1<<k)-1<=n;i++)
                for(int j=1;j+w-1<=m;j++)
                    a[k][i][j]=cmmdc(a[k-1][i][j],a[k-1][i+(1<<(k-1))][j]);
        for(int k=0;k<=10;k++)
            if((1<<k)<=h)
                de=k;
        for(int i=1;i+h-1<=n;i++)
            for(int j=1;j+w-1<=m;j++)
                r=max(r,cmmdc(a[de][i][j],a[de][i+h-(1<<de)][j]));
        g<<"Case #"<<t<<": "<<r<<'\n';
    }
    return 0;
}
