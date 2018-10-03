#include<bits/stdc++.h>
using namespace std;
ifstream f("nrcuv.in");
ofstream g("nrcuv.out");
char c1[7];
int sol,n,k;
char c,d;
bool mat[30][30];
long long ar[1002][30];
int main()
{
    f>>n>>k;
    for(int i=1;i<=k;++i)
    {
        f>>c>>d;
        mat[c-'a'+1][d-'a'+1]=1;
    }
    for(int i=1;i<=26;++i)
        ar[1][i]=1;
    for(int i=2;i<=n;++i)
        for(int j=1;j<=26;++j)
            for(int k=1;k<=26;++k)
                ar[i][j]+=(max(0,1-mat[j][k]-mat[k][j])*ar[i-1][k])%104659;
    long long sol=0;
    for(int i=1;i<=26;++i)
        sol=(sol+ar[n][i])%104659;
    g<<sol;
    return 0;
}
