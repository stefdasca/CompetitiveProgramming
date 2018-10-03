#include<bits/stdc++.h>
using namespace std;
ifstream f("expozitie.in");
ofstream g("expozitie.out");
int n,d,k;
struct Nmare
{
    int v[302],len;
};
Nmare vsus[502];
Nmare vjos[502];
void Adun(int indsus, int indjos, int q)
{
    if(q==2){
        for(int i=1;i<=vsus[indsus].len;++i)
            vjos[indsus].v[i]+=vsus[indsus].v[i];
        for(int i=1;i<=vjos[indjos].len;++i)
            vjos[indsus].v[i]+=vjos[indjos].v[i];
        vjos[indsus].len=max(vsus[indsus].len,vjos[indjos].len);
        for(int i=1;i<=vjos[indsus].len;++i)
            if(vjos[indsus].v[i]>9)
            {
                vjos[indsus].v[i+1]+=vjos[indsus].v[i]/10;
                vjos[indsus].v[i]%=10;
                if(i==vjos[indsus].len)
                    ++vjos[indsus].len;
            }
    }
    else
    {
        for(int i=1;i<=vsus[indsus].len;++i)
            vsus[indjos].v[i]+=vsus[indsus].v[i];
        for(int i=1;i<=vjos[indjos].len;++i)
            vsus[indjos].v[i]+=vjos[indjos].v[i];
        vsus[indjos].len=max(vsus[indsus].len,vjos[indjos].len);
        for(int i=1;i<=vsus[indjos].len;++i)
            if(vsus[indjos].v[i]>9)
            {
                vsus[indjos].v[i+1]+=vsus[indjos].v[i]/10;
                vsus[indjos].v[i]%=10;
                if(i==vsus[indjos].len)
                    ++vsus[indjos].len;
            }
    }
}
int main()
{
    f>>n>>d>>k;
    n-=d*k;
    if(n<0)
        g<<0;
    else
        if(n==0)
            g<<1;
        else
        {
            for(int i=1;i<=d;++i)
                vsus[i].v[1]=i,vsus[i].len=1;
            for(int i=2;i<=n;++i)
                if(i%2==0){
                    for(int j=1;j<=d;++j)
                        memset(vjos[j].v,0,sizeof(vjos[j].v)),vjos[j].len=0;
                    for(int j=1;j<=d;++j)
                        Adun(j,j-1,2);
                }
                else
                {
                    for(int j=1;j<=d;++j)
                        memset(vsus[j].v,0,sizeof(vsus[j].v)),vsus[j].len=0;
                    for(int j=1;j<=d;++j)
                        Adun(j-1,j,1);
                }
            if(n%2==0)
                for(int j=vjos[d].len;j>=1;--j)
                    g<<vjos[d].v[j];
            else
                for(int j=vsus[d].len;j>=1;--j)
                    g<<vsus[d].v[j];
        }
    return 0;
}
