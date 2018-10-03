#include<bits/stdc++.h>
using namespace std;
ifstream f("partitie1.in");
ofstream g("partitie1.out");
long long n;
long long srq,nr;
int m[1002][1002],s[1002];
int main()
{
    f>>n;
    srq=n*(n*n+1)/2;
    int nr=-1;
    for(int i=1;i<=n/2+n%2;++i){
        nr+=2;
        for(int j=i;j>=1;--j)
            m[j][i-j+1]=nr+n*(i-j),s[j]+=m[j][i-j+1];
    }
    nr=0;
    for(int i=n/2+n%2+1;i<=n;++i)
    {
        nr+=2;
        for(int j=i;j>=1;--j)
            m[j][i-j+1]=nr+n*(i-j),s[j]+=m[j][i-j+1];
    }
    for(int i=2;i<=n;++i)
    {
        int z=srq-s[i];
        for(int j=n;j>=i;--j)
            m[i+n-j][j]=z-n*(n-j),s[i+n-j]+=m[i+n-j][j];
    }
    for(int i=1;i<=n;g<<'\n',++i)
        for(int j=1;j<=n;++j)
            g<<m[i][j]<<" ";
    return 0;
}
