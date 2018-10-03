#include<bits/stdc++.h>
using namespace std;
ifstream f("pescari.in");
ofstream g("pescari.out");
int n,m,p;
int a[1002][1002];
int pd[1002][1002];
void nrml(int &a, int &b, int &c, int &d)
{
    if(a>n)
        a=n;
    if(b>m)
        b=m;
    if(c<1)
        c=1;
    if(d<1)
        d=1;
}
int dmin(int l, int c)
{
    int l1=l;
    int c1=c;
    int k=1;
    while(1)
    {
        l++,c++,c1--,l1--;
        nrml(l,c,c1,l1);
        int x1=pd[l][c]-pd[l][c1-1]-pd[l1-1][c]+pd[l1-1][c1-1];
        if(x1)
            return k;
        else
            ++k;
    }
}
void init()
{
    f>>n>>m>>p;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            f>>a[i][j];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            pd[i][j]=(a[i][j]==2)+pd[i-1][j]+pd[i][j-1]-pd[i-1][j-1];
}
void solve()
{
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(a[i][j]==1)
                g<<dmin(i,j)<<'\n';
}
int main()
{
    init();
    solve();
    return 0;
}
