#include<bits/stdc++.h>
#define Orez 1000003
using namespace std;
ifstream f("intrus.in");
ofstream g("intrus.out");
int frq[Orez],n,mat[1002][1002],c,lat,m;
bool Prime[Orez];
inline void Ciur()
{
    Prime[0]=Prime[1]=1;
    for(int i=4;i<=Orez;i+=2)
        Prime[i]=1;
    for(int i=3;i<=Orez;i+=2)
        if(!Prime[i])
            for(int j=i+i;j<=Orez;j+=i)
                Prime[j]=1;
}
inline void read()
{
    f>>c;
    f>>n>>m>>lat;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            f>>mat[i][j],frq[mat[i][j]]++;
}
inline void first()
{
    int sol=0;
    for(int i=1;i<Orez;++i)
        if(frq[i]>1)
            sol+=frq[i];
    g<<sol;
}
struct orange
{
    int l,c,nrsus,maxsus;
};
orange v[100002];
bool test(orange a, orange b)
{
    if(a.nrsus!=b.nrsus)
        return a.nrsus>b.nrsus;
    if(a.maxsus!=b.maxsus)
        return a.maxsus>b.maxsus;
    if(a.l!=b.l)
        return a.l<b.l;
    return a.c<b.c;
}
inline void second()
{
    int rrr=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(mat[i][j]!=0 && frq[mat[i][j]]>1)
            {
                ++rrr;
                v[rrr].l=i;
                v[rrr].c=j;
                for(int pp=i-lat/2;pp<=i+lat/2;++pp)
                    for(int qq=j-lat/2;qq<=j+lat/2;++qq)
                        if(pp>=1 && pp<=n && qq>=1 && qq<=m)
                            if(Prime[mat[pp][qq]]==0)
                            {
                                ++v[rrr].nrsus;
                                v[rrr].maxsus=max(v[rrr].maxsus,mat[pp][qq]);
                            }
            }
    if(rrr==0){
        g<<-1;
        return;
    }
    sort(v+1,v+rrr+1,test);
    for(int i=1;i<=rrr;++i)
        g<<mat[v[i].l][v[i].c]<<" "<<v[i].l<<" "<<v[i].c<<'\n';
}
int main()
{
    read();
    Ciur();
    if(c==1)
        first();
    else
        second();
    return 0;
}
