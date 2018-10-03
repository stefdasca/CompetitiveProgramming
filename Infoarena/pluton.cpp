#include<bits/stdc++.h>
using namespace std;
ifstream f("pluton.in");
ofstream g("pluton.out");
int n,fr[12];
struct pluton
{
    long long org,mx;
};
pluton v[4001];
bool test(pluton a, pluton b)
{
    return a.mx<b.mx;
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
    {
        f>>v[i].org;
        long long nr=v[i].org;
        while(nr)
            fr[nr%10]++,nr/=10;
        for(int j=9;j>=0;--j)
            while(fr[j])
                v[i].mx=v[i].mx*10+j,--fr[j];
    }
    sort(v+1,v+n+1,test);
    int nrp=1;
    int lmax=0,nrmax=0,l=1;
    for(int i=2;i<=n;++i)
        if(v[i].mx==v[i-1].mx)
            ++l;
        else{
            if(l>lmax)
                lmax=l,nrmax=1;
            else
                if(l==lmax)
                    ++nrmax;
            l=1;++nrp;
        }
    if(l>lmax)
        lmax=l,nrmax=1;
    else
        if(l==lmax)
            ++nrmax;
    g<<nrp<<'\n';
    g<<lmax<<'\n';
    g<<nrmax<<'\n';
    l=1;
    for(int i=2;i<=n;++i)
        if(v[i].mx==v[i-1].mx)
            ++l;
        else{
            if(l==lmax)
            {
                for(int j=i-1;l;--j,--l)
                    g<<v[j].org<<" ";
                return 0;
            }
            l=1;
        }
    if(l==lmax)
    {
        for(int j=n;l;--j,--l)
            g<<v[j].org<<" ";
        return 0;
    }
}
