#include<bits/stdc++.h>
using namespace std;
ifstream f("scoici.in");
ofstream g("scoici.out");
int n,nr,v2[12],dif[12],c;
struct ee
{
    int v[12];
    int pos;
};
ee v[100002];
bool cmp(ee a, ee b)
{
    for(int i=1;i<=c;++i)
        if(a.v[i]!=b.v[i])
            return a.v[i]<b.v[i];
    return a.pos<b.pos;
}
bool eq(int a, int b)
{
    for(int i=1;i<=c;++i)
        if(v[a].v[i]!=v[b].v[i])
            return 0;
    return 1;
}
int main()
{
    f>>n>>c;
    for(int i=1;i<=n;++i)
    {
        f>>nr;
        v2[nr]++;
        int maxi=0;
        for(int j=1;j<=c;++j)
            maxi=max(maxi,v2[j]);
        for(int j=1;j<=c;++j)
            v[i].v[j]=maxi-v2[j];
        v[i].pos=i;
    }
    sort(v,v+n+1,cmp);
    int lmax=0,pmax=0;
    int pmin=0;
    for(int i=1;i<=n;++i)
    {
        if(eq(i,i-1))
        {
            if(v[i].pos-pmin>lmax)
                lmax=v[i].pos-pmin,pmax=pmin+1;
            else
                if(v[i].pos-pmin==lmax)
                    pmax=min(pmax,pmin+1);
        }
        else
            pmin=v[i].pos;
    }
    g<<lmax;
    return 0;
}
