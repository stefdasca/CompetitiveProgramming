#include<bits/stdc++.h>
using namespace std;
ifstream f("plaja.in");
ofstream g("plaja.out");
int n,m,u;
int x,y,nt,nl,sol1,sol2;
bool pu[2002][2002];
int du[2002][2002];
int dt[2002][2002],s[2002][2002];
int xa,ya,xb,yb;
int main()
{
    f>>n>>m>>u;
    for(int i=1;i<=u;++i)
        f>>x>>y,pu[x][y]=1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            du[i][j]=pu[i][j]+du[i-1][j]+du[i][j-1]-du[i-1][j-1];
    f>>nt;
    for(int i=1;i<=nt;++i)
    {
        f>>xa>>ya>>xb>>yb;
        if(du[xb][yb]-du[xb][ya-1]-du[xa-1][yb]+du[xa-1][ya-1]==0){
            ++sol1;
            dt[xa][ya]++;
            dt[xb+1][yb+1]++;
            dt[xa][yb+1]--;
            dt[xb+1][ya]--;
        }
    }
    g<<sol1<<" ";
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            s[i][j]=dt[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            s[i][j]=min(s[i][j],1);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
    f>>nl;
    for(int i=1;i<=nl;++i)
    {
        f>>xa>>ya>>xb>>yb;
        if(du[xb][yb]-du[xb][ya-1]-du[xa-1][yb]+du[xa-1][ya-1]==0 && s[xb][yb]-s[xb][ya-1]-s[xa-1][yb]+s[xa-1][ya-1]==0)
            ++sol2;
    }
    g<<sol2;
    return 0;
}
