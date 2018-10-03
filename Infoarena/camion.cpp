#include<bits/stdc++.h>
using namespace std;
ifstream f("camion.in");
ofstream g("camion.out");
int n,m,k,c;
int poz[602];
struct qu
{
    int a,b,c,d;
};
qu v[30002];
int main()
{
    f>>n>>m>>k>>c;
    for(int i=1;i<=n;++i)
        poz[i]=c;
    for(int i=1;i<=k;++i)
        f>>v[i].a>>v[i].b>>v[i].c>>v[i].d;
    for(int i=k;i>=1;--i)
        for(int j=v[i].a;j<=v[i].c;++j)
            if(v[i].b<=poz[j])
                poz[j]+=v[i].d-v[i].b+1;
    for(int i=1;i<=n;++i)
        if(poz[i]<=m)
            g<<poz[i]<<'\n';
        else
            g<<0<<'\n';
    return 0;
}
