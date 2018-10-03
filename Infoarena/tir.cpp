#include<bits/stdc++.h>
using namespace std;
ifstream f("tir.in");
ofstream g("tir.out");
int n,m,k;
int smax,lm,cm;
struct points
{
    int l,c;
};
points v[501];
int main()
{
    f>>n>>m>>k;
    for(int i=1;i<=k;++i)
        f>>v[i].l>>v[i].c;
    for(int i=1;i<=n-m+1;++i)
        for(int j=1;j<=n-m+1;++j)
        {
            int s=0;
            for(int z=1;z<=k;++z)
                if(v[z].l>=i && v[z].l<i+m)
                    if(v[z].c>=j && v[z].c<j+m)
                    {
                        int dn=v[z].l-i+1;
                        int dv=v[z].c-j+1;
                        int ds=i+m-v[z].l;
                        int de=j+m-v[z].c;
                        s+=min(dn,min(dv,min(ds,de)));
                    }
            if(s>smax)
                smax=s,lm=i,cm=j;
        }
    g<<smax<<'\n';
    g<<lm<<" "<<cm<<'\n';
    return 0;
}
