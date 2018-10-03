#include<bits/stdc++.h>
using namespace std;
ifstream f("biperm.in");
ofstream g("biperm.out");
int n;
int v[3][10002],countt[3][10002];
bool ok[3][10002];
int sol=1;
struct pp
{
    int pa[3];
    int pb[3];
};
pp v2[10002];
bool viz[10002];
int op,st;
void cycle(int l, int c)
{
    ++op;
    viz[v[l][c]]=1;
    if(op%2==1)
        cycle(3-l,c);
    else
    {
        if(v[l][c]==st)
            return;
        int val=v[l][c];
        int aa=v2[val].pa[1];
        int bb=v2[val].pa[2];
        if(l==aa && bb==c)
            cycle(v2[val].pb[1],v2[val].pb[2]);
        else
            cycle(aa,bb);
    }
}
void solvea()
{
    for(int i=1;i<=n;++i)
    {
        int val=v[1][i];
        if(!viz[val])
        {
            op=0;
            st=val;
            cycle(1,i);
            if(op>2)
                sol*=2;
        }
    }
    g<<sol<<" ";
}
void dfs(int y, int x)
{
    if(v[y][x] == v[3-y][x])
    {
        ok[y][x]=ok[3-y][x]=1;
        return;
    }
    int a=0,b=0;
    while(!ok[y][x])
    {
        ++a;
        int y1, x1, z1, z2;
        y1=v2[v[3-y][x]].pa[1];
        x1=v2[v[3-y][x]].pa[2];
        ok[y][x]=ok[3-y][x]=1;
        z2 = 0;
        if(x==x1 && 3-y==y1)
        {
            y1=v2[v[3-y][x]].pb[1];
            x1=v2[v[3-y][x]].pb[2];
            z2=1;
        }
        z1=0;
        if(v2[v[3-y1][x1]].pa[1] != 3-y1 || v2[v[3-y1][x1]].pa[2]!=x1)
            z1 = 1;
        if(3-y==y1)
        {
            ++b;
            if(z1==1)
                v2[v[3-y1][x1]].pb[1]=3-v2[v[3-y1][x1]].pb[1];
            else
                v2[v[3-y1][x1]].pa[1]=3-v2[v[3-y1][x1]].pa[1];
            if(z2==1)
                v2[v[3-y][x]].pb[1]=3-v2[v[3-y][x]].pb[1];
            else
                v2[v[3-y][x]].pa[1]=3-v2[v[3-y][x]].pa[1];
            swap(v[y1][x1],v[3-y1][x1]);
        }
        x = x1;
        y = y;
    }
    sol+=min(b,a-b);
}
void solveb()
{
    for(int i=1;i<=2;++i)
        for(int j=1;j<=n;++j)
            if(!ok[i][j])
                dfs(i,j);
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
    {
        f>>v[1][i];
        ++countt[1][v[1][i]];
        if(v2[v[1][i]].pa[1])
            v2[v[1][i]].pb[1]=1,v2[v[1][i]].pb[2]=i;
        else
            v2[v[1][i]].pa[1]=1,v2[v[1][i]].pa[2]=i;
    }
    for(int i=1;i<=n;++i)
    {
        f>>v[2][i];
        ++countt[2][v[2][i]];
        if(v2[v[2][i]].pa[1])
            v2[v[2][i]].pb[1]=2,v2[v[2][i]].pb[2]=i;
        else
            v2[v[2][i]].pa[1]=2,v2[v[2][i]].pa[2]=i;
    }
    solvea();
    sol=0;
    solveb();
    g<<sol<<'\n';
    for(int i=1;i<=2;g<<'\n',++i)
        for(int j=1;j<=n;++j)
           g<<v[i][j]<<" ";
    return 0;
}
