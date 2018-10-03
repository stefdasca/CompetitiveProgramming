#include <fstream>
using namespace std;
ifstream f("joc14.in");
ofstream g("joc14.out");
int n,tip,x,y,i,j,ok,ind;
char M[2][60][60];
int main()
{
    f>>n>>tip;
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            M[0][i][j]='.';
    ok=1;
    if(tip==1)
    {
        f>>x>>y;
        M[0][x][y]='o';
        if(x==1||x==n||y==1||y==n)
            ok=0;
    }
    else
    {
        f>>x>>y;
        M[0][x][y]='o';
        if(x==1||x==n||y==1||y==n)
            ok=0;
        f>>x>>y;
        M[0][x][y]='o';
        if(x==1||x==n||y==1||y==n)
            ok=0;
    }
    for(i=1;i<=n;++i)
        g<<(M[0][i]+1)<<'\n';
    g<<'\n';
    while(ok)
    {
        ++ind;
        for(i=1;i<=n;++i)
            for(j=1;j<=n;++j)
                M[ind&1][i][j]='.';
        for(i=1;i<=n;++i)
            for(j=1;j<=n;++j)
                if(M[(ind-1)&1][i][j]=='.')
                {
                    int vec=(M[(ind-1)&1][i-1][j]=='*')+(M[(ind-1)&1][i][j-1]=='*')+(M[(ind-1)&1][i+1][j]=='*')+(M[(ind-1)&1][i][j+1]=='*')+(M[(ind-1)&1][i-1][j]=='o')+(M[(ind-1)&1][i][j-1]=='o')+(M[(ind-1)&1][i+1][j]=='o')+(M[(ind-1)&1][i][j+1]=='o');
                    if(vec==1)
                    {
                        M[ind&1][i][j]='o';
                        if(j==1||j==n||i==1||i==n)
                            ok=0;
                    }
                }
                else
                    if(M[(ind-1)&1][i][j]=='o')
                        M[ind&1][i][j]='*';
        for(i=1;i<=n;++i)
            g<<(M[ind&1][i]+1)<<'\n';
        g<<'\n';
    }
    return 0;
}
