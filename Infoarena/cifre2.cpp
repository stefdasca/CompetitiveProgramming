#include<bits/stdc++.h>
using namespace std;
ifstream f("cifre2.in");
ofstream g("cifre2.out");
int n,k,nr;
int sol[200005];
int fr[12];
struct q
{
    int v[100002];
    int l;
};
q v[102];
int main()
{
    f>>n>>k;
    for(int i=1;i<=n;++i)
        f>>nr,fr[nr]++;
    int lmax=n/k+((n%k)>0);
    int z=1;
    while(fr[z]==0)
        ++z;
    for(int i=1;i<=k;++i){
        v[i].v[1]=z,--fr[z];
        while(fr[z]==0)
            ++z;
        v[i].l=1;
    }
    int poz=1;
    for(int z=0;z<=9;++z)
        for(;fr[z];--fr[z])
        {
            ++v[poz].l;
            v[poz].v[v[poz].l]=z;
            ++poz;
            if(poz>k)
                poz=1;
        }
    int nr=200000;
    for(int i=0;i<lmax;++i)
        for(int j=1;j<=k;++j)
            if(v[j].l-i>0)
                sol[nr-i]+=v[j].v[v[j].l-i];
    nr=200000-lmax+1;
    for(int i=200000;i>=nr;--i)
    {
        sol[i-1]+=sol[i]/10;
        sol[i]%=10;
        if(sol[nr-1]>0)
            --nr;
    }
    nr=1;
    while(sol[nr]==0)
        ++nr;
    for(int i=nr;i<=200000;++i)
        g<<sol[i];
    return 0;
}
