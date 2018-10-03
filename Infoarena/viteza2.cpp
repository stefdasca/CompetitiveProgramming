/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
ifstream f("viteza2.in");
ofstream g("viteza2.out");
int n,m;
struct pr
{
    int a,b,c;
};
pr v[5002];
bool cmp(pr a, pr b)
{
    return a.a<b.a;
}
int d[1002][1002];
int main()
{
    f>>n>>m;
    for(int i=1;i<=m;++i)
        f>>v[i].b>>v[i].c>>v[i].a;
    sort(v+1,v+m+1,cmp);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            d[i][j]=2e9;
    for(int i=1;i<=n;++i)
        d[i][i]=0;
    for(int i=1;i<=m;i++)
    {
        int cost=v[i].a,a=v[i].b,b=v[i].c;
        for(int k=1;k<=n;k++)
        {
            d[k][b]=min(d[k][b],d[k][a]+cost);
            d[k][a]=min(d[k][a],d[k][b]+cost);
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
            if(d[i][j]==2e9)
                g<<-1<<" ";
            else
                g<<d[i][j]<<" ";
        g<<'\n';
    }
    return 0;

}
