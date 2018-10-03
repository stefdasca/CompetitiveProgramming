#include<bits/stdc++.h>
using namespace std;
ifstream f("sah3.in");
ofstream g("sah3.out");
int n,m,mat[1002][1002],pd[1002][1002];
long long lat[1002];
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            f>>mat[i][j];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            if(mat[i][j]!=mat[i-1][j] && mat[i-1][j]==mat[i][j-1] && mat[i][j]==mat[i-1][j-1])
                pd[i][j]=min(pd[i-1][j],min(pd[i-1][j-1],pd[i][j-1]))+1;
            else
                pd[i][j]=1;
            lat[pd[i][j]]++;
        }
    long long sol=0;
    for(int i=n;i>=1;--i)
        sol+=lat[i],lat[i-1]+=lat[i];
    g<<sol;
    return 0;
}
