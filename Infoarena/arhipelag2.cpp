#include<bits/stdc++.h>
using namespace std;
ifstream f("arhipelag2.in");
ofstream g("arhipelag2.out");
int n,m,nrd;
int a[1002][1002],wfr[1002][1002];
int vln[500002],vls[500002],vcn[500002],vcs[500002];
int spln[500002],spls[500002],spcn[500002],spcs[500002];
int soll[1002],solc[1002];
void read()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            f>>a[i][j];
}
void findrect()
{
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(a[i][j]==1 && wfr[i][j]==0)
            {
                ++nrd;
                vln[nrd]=i;
                vcn[nrd]=j;
                int ls=i;
                int cs=j;
                while(a[ls+1][j]==1)
                    ++ls;
                while(a[ls][cs+1]==1)
                    ++cs;
                vls[nrd]=ls;
                vcs[nrd]=cs;
                for(int qq=i;qq<=ls;++qq)
                    for(int pp=j;pp<=cs;++pp)
                        wfr[qq][pp]=1;
            }
    sort(vln+1,vln+nrd+1);
    sort(vcn+1,vcn+nrd+1);
    sort(vls+1,vls+nrd+1);
    sort(vcs+1,vcs+nrd+1);
    for(int i=1;i<=nrd;++i)
    {
        spln[i]=spln[i-1]+vln[i];
        spls[i]=spls[i-1]+vls[i];
        spcn[i]=spcn[i-1]+vcn[i];
        spcs[i]=spcs[i-1]+vcs[i];
    }
}
int BinSearch(int axa, int poz)
{
    int b=1;
    int e=nrd;
    while(b<=e)
    {
        int m=(b+e)/2;
        if(axa==1)
        {
            if(vls[m]<poz && vls[m+1]>=poz)
                return m*poz-spls[m];
            else
                if(vls[m]>poz)
                    e=m-1;
                else
                    b=m+1;
        }
        else
            if(axa==2)
            {
                if(vln[m]>poz && vln[m-1]<=poz)
                    return (spln[nrd]-spln[m-1])-poz*(nrd-m+1);
                else
                    if(vln[m]>poz)
                        e=m-1;
                    else
                        b=m+1;
            }
            else
                if(axa==3)
                {
                    if(vcs[m]<poz && vcs[m+1]>=poz)
                        return m*poz-spcs[m];
                    else
                        if(vcs[m]>poz)
                            e=m-1;
                        else
                            b=m+1;
                }
                else
                {
                    if(vcn[m]>poz && vcn[m-1]<=poz)
                        return (spcn[nrd]-spcn[m-1])-poz*(nrd-m+1);
                    else
                        if(vcn[m]>poz)
                            e=m-1;
                        else
                            b=m+1;
                }
    }
    if(axa==1)
        return e*poz-spls[e];
    if(axa==2)
        return (spln[nrd]-spln[e-1])-poz*(nrd-e+1);
    if(axa==3)
        return e*poz-spcs[e];
    if(axa==4)
        return (spcn[nrd]-spcn[e-1])-poz*(nrd-e+1);
}
void fmax()
{
    vln[nrd+1]=n+1,vls[nrd+1]=n+1,vcn[nrd+1]=m+1,vcs[nrd+1]=m+1;
    int dmin=2e9;
    int lmin=0;
    int cmin=0;
    for(int i=1;i<=n;++i)
        soll[i]=BinSearch(1,i)+BinSearch(2,i);
    for(int j=1;j<=m;++j)
        solc[j]=BinSearch(3,j)+BinSearch(4,j);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(a[i][j]==0)
            {
                int d=soll[i]+solc[j];
                if(d<dmin)
                    dmin=d,lmin=i,cmin=j;
            }
    g<<lmin<<" "<<cmin<<'\n';
}
int main()
{
    read();
    findrect();
    fmax();
    return 0;
}
