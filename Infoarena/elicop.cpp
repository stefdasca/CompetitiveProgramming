#include<bits/stdc++.h>
using namespace std;
ifstream f("elicop.in");
ofstream g("elicop.out");
int n,m;
bool a[102][102];
int k;
int x1,yyy,x2,y2,s;
int nrp,nrr;
int v[42];
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            f>>a[i][j];
    f>>k;
    for(int i=1;i<=k;++i)
    {
        f>>x1>>yyy>>x2>>y2>>s;
        if(x2<x1)
        {
            swap(x1,x2);
            swap(yyy,y2);
        }
        if(s==-1){
            int ar=0,nr0=0;
            if(yyy<y2)
                for(int j=x1;j<=x2;++j)
                    for(int k=yyy;k<=yyy+j-x1;++k)
                    {
                        ++ar;
                        if(a[j][k]==0)
                            ++nr0;
                    }
            else
                for(int j=x1;j<=x2;++j)
                    for(int k=yyy;k>=yyy-j+x1;--k)
                    {
                        ++ar;
                        if(a[j][k]==0)
                            ++nr0;
                    }
            if(nr0>ar/2)
                v[i]=1,++nrr;
            else
                if(nr0==0)
                    ++nrp;
        }
        else
        {
            int ar=0,nr0=0;
            if(yyy<y2)
                for(int j=x1;j<=x2;++j)
                    for(int k=yyy+j-x1;k<=y2;++k)
                    {
                        ++ar;
                        if(a[j][k]==0)
                            ++nr0;
                    }
            else
                for(int j=x1;j<=x2;++j)
                    for(int k=y2;k<=yyy-j+x1;++k)
                    {
                        ++ar;
                        if(a[j][k]==0)
                            ++nr0;
                    }
            if(nr0>ar/2)
                v[i]=1,++nrr;
            else
                if(nr0==0)
                    ++nrp;
        }
    }
    g<<nrp<<'\n';
    g<<nrr<<" ";
    for(int i=1;i<=k;++i)
        if(v[i]==1)
            g<<i<<" ";
    return 0;
}
