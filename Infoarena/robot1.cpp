#define rose 64997
#include<bits/stdc++.h>
using namespace std;
ifstream f("robot1.in");
ofstream g("robot1.out");
int n,k,nr=2,mat[4][3002];
int main()
{
    f>>n>>k;
    for(int i=1;i<k;++i)
        mat[1][i]=1;
    for(int i=k+1;i<=n;++i,nr=3-nr)
        for(int j=1;j<i;++j)
            mat[nr][j]=((i-1>j)*mat[3-nr][j]+mat[nr][j-1])%rose;
    g<<mat[3-nr][n-1];
    return 0;
}
