#include<bits/stdc++.h>
using namespace std;
ifstream f("castel.in");
ofstream g("castel.out");
int n,m,mat[182][182],Qsize,start;
bool viz[182][182];
bool Keys[182*182],ok;
struct visited
{
    int L,C;
};
visited v[182*182];
int findnr(int L,int C)
{
    return (L-1)*m+C;
}
void verif(int L,int C)
{
    if(!viz[L-1][C] && Keys[mat[L-1][C]]==1)
        v[++Qsize].L=L-1,v[Qsize].C=C,ok=1,viz[L-1][C]=1,Keys[findnr(L-1,C)]=1;
    if(!viz[L+1][C] && Keys[mat[L+1][C]]==1)
        v[++Qsize].L=L+1,v[Qsize].C=C,ok=1,viz[L+1][C]=1,Keys[findnr(L+1,C)]=1;
    if(!viz[L][C-1] && Keys[mat[L][C-1]]==1)
        v[++Qsize].L=L,v[Qsize].C=C-1,ok=1,viz[L][C-1]=1,Keys[findnr(L,C-1)]=1;
    if(!viz[L][C+1] && Keys[mat[L][C+1]]==1)
        v[++Qsize].L=L,v[Qsize].C=C+1,ok=1,viz[L][C+1]=1,Keys[findnr(L,C+1)]=1;
}
int main()
{
    f>>n>>m>>start;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            f>>mat[i][j];
    Keys[start]=1;
    int L=start/m+(start%m>0);
    int C=start%m;
    if(C==0)
        C=m;
    viz[L][C]=1;
    v[++Qsize].L=L,v[Qsize].C=C;
    do{
        ok=0;
        for(int i=1;i<=Qsize;++i)
            verif(v[i].L,v[i].C);
    }while(ok);
    int sol=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            sol+=viz[i][j];
    g<<sol;
    return 0;
}
