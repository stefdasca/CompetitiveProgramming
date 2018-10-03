#include<bits/stdc++.h>
using namespace std;
ifstream f("simetric.in");
ofstream g("simetric.out");
int n,m,mat[402][402];
int pd[402][402];
int sol[402];
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            f>>mat[i][j];
    for(int i=1;i<=m;++i)
        pd[1][i]=1;
    for(int i=1;i<=n;++i)
        pd[i][1]=1;
    for(int i=2;i<=n;++i)
        for(int j=2;j<=m;++j)
        {
            int z=pd[i-1][j-1];
            int q=1;
            while(q<=z)
            {
                if(mat[i-q][j]==mat[i][j-q])
                    ++q;
                else
                    break;
            }
            pd[i][j]=q;
        }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            sol[pd[i][j]]++;
    for(int i=400;i>=1;--i)
        sol[i-1]+=sol[i];
    for(int i=1;sol[i]>0;++i)
        g<<sol[i]<<'\n';
    return 0;
}
