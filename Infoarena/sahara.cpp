#include<bits/stdc++.h>
using namespace std;
ifstream f("sahara.in");
ofstream g("sahara.out");
int n,m,Q,q,s;
int a[1002][1002];
int U[1002][1002];
int ax,ay,bx,by;
int lmax=0;
struct coada
{
    int l,c;
};
coada v[1000002];
int ox[]={0,-1,0,1,0};
int oy[]={0,0,1,0,-1};
void lee(int l,int c)
{
    v[1].l=l;
    v[1].c=c;
    int b=1;
    int e=1;
    U[l][c]=0;
    while(b<=e)
    {
        for(int i=1;i<=4;++i)
        {
            int X=v[b].l+ox[i];
            int Y=v[b].c+oy[i];
            if(U[X][Y]>=Q)
            {
                U[X][Y]=0;
                ++e;
                v[e].l=X;
                v[e].c=Y;
            }
        }
        ++b;
    }
    lmax=max(lmax,e);
}
int main()
{
    f>>n>>m>>Q;
    f>>q;
    for(int i=1;i<=q;++i)
    {
        f>>ax>>ay>>bx>>by>>s;
        a[ax][ay]+=s;
        a[bx+1][ay]-=s;
        a[ax][by+1]-=s;
        a[bx+1][by+1]+=s;
    }
    for (int i=1; i<=n; ++i)
    {
        int aux = 0;
        for (int j=1; j<=m; ++j)
        {
            a[i][j] += a[i-1][j];
                aux += a[i][j];
            U[i][j]  = aux;
        }
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(U[i][j]>=Q)
                lee(i,j);
    g<<lmax<<'\n';
    return 0;
}
