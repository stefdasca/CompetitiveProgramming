#include<bits/stdc++.h>
using namespace std;
ifstream f("ferma2.in");
ofstream g("ferma2.out");
int n,k,s,min1=1e9;
int d[1002][1002],l[1002][1002],c[1002][1002],a[1002][1002];
int main()
{
    f>>n>>k;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=i;++j)
            f>>a[i][j],s+=a[i][j];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=i;++j)
            d[i][j]=a[i][j]+d[i-1][j-1];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=i;++j)
            d[i][j]+=d[i-1][j];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=i;++j)
            c[i][j]=a[i][j]+c[i-1][j];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=i;++j)
            c[i][j]+=c[i][j-1];
    k=n-k;
    for(int i=k;i<=n;++i)
        for(int j=k;j<=i;++j)
        {
           int ts=c[i][j]-d[i-1][j]-c[i][j-k]+(i>k)*d[i-k-1][j-k];
            min1=min(min1,ts);
        }
    g<<s-min1;
    return 0;
}
