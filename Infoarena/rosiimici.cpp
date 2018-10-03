#include<bits/stdc++.h>
using namespace std;
ifstream f("rosiimici.in");
ofstream g("rosiimici.out");
int n,m,a[1002][1002];
int q,nr;
int fr[1002];
int Sol[1002];
struct queries
{
    int nr;
    int pozinit;
    int ans;
};
queries v[100002];
bool cmp(queries a, queries b)
{
    return a.nr<b.nr;
}
bool cmp2(queries a, queries b)
{
    return a.pozinit<b.pozinit;
}
inline void cb(int maxx)
{
    for(int i=1;i<=m;++i)
        if(Sol[i]<n)
        {
            --fr[Sol[i]];
            while(Sol[i]<n && a[Sol[i]+1][i]<=maxx)
                ++Sol[i];
            ++fr[Sol[i]];
        }
}
inline int solve()
{
    int qt=m;
    int sol=0;
    for(int i=0;i<=n;++i)
    {
        sol=max(sol,qt*i);
        qt-=fr[i];
    }
    return sol;
}
int main()
{
    f>>n>>m>>q;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            f>>a[i][j];
    for(int i=1;i<=q;++i)
    {
        f>>v[i].nr;
        v[i].pozinit=i;
    }
    sort(v+1,v+q+1,cmp);
    fr[0]=m;
    for(int i=1;i<=q;++i)
    {
        cb(v[i].nr);
        v[i].ans=solve();
    }
    sort(v+1,v+q+1,cmp2);
    for(int i=1;i<=q;++i)
        g<<v[i].ans<<'\n';
    return 0;
}
