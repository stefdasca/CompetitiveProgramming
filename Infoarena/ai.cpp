/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
#define eps 1e-3
using namespace std;
ifstream f("ai.in");
ofstream g("ai.out");
int n,m;
int XT,YT,XR1,YR1,XR2,YR2;
int SX1,SY1,SX2,SY2;
bool mat[1002][1002];
bool ipots1[1002][1002];
bool ipots2[1002][1002];
inline bool IPOTS(int xa, int ya, int xb, int yb, int xc, int yc)
{
    if(xa==xc)
        if(xa==xb && min(ya,yc)<=yb && yb<=max(ya,yc))
            return 1;
        else
            return 0;
    if(ya==yc)
        if(ya==yb && min(xc,xa)<=xb && xb<=max(xc,xa))
            return 1;
        else
            return 0;
    if(xb==xc)
        return 0;
    double rap=1.0*(xa-xb+0.0)/(xb-xc+0.0);
    double poz=1.0*(ya+rap*yc)/(rap+1.0);
    if(abs(poz-yb)<=eps)
        return 1;
    return 0;
}
void Read()
{
    f>>n;
    f>>XT>>YT>>SX1>>SY1>>SX2>>SY2>>XR1>>YR1>>XR2>>YR2;
    f>>m;
    mat[XT][YT]=1;
    for(int i=1;i<=m;++i)
    {
        int x,y;
        f>>x>>y;
        mat[x][y]=1;
    }
    for(int i=1;i<=n;++i)
        mat[0][i]=mat[i][0]=mat[n+1][i]=mat[i][n+1]=1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        {
            if(i>=min(SX1,XT) && i<=max(XT,SX1))
                ipots1[i][j]=IPOTS(SX1,SY1,i,j,XT,YT);
            if(i>=min(SX2,XT) && i<=max(XT,SX2))
                ipots2[i][j]=IPOTS(SX2,SY2,i,j,XT,YT);
        }
}
void LenMax()
{
    int lenmax=0;
    for(int i=1;i<=n;++i)
    {
        int l=0;
        int l2=0;
        for(int j=1;j<=n;++j)
        {
            if(mat[i][j]==1)
                ++l;
            else
                l=0;
            lenmax=max(lenmax,l);
            if(mat[j][i]==1)
                ++l2;
            else
                l2=0;
            lenmax=max(lenmax,l2);
        }
    }
    g<<lenmax<<'\n';
}
deque<pair<int, int> >d;
int viz[1002][1002];
int ox[]={-1,0,1,0};
int oy[]={0,1,0,-1};
inline void True()
{
    int fr1=1e9,sr1=1e9,fr2=1e9,sr2=1e9;
    d.push_back({XR1,YR1});
    mat[XR1][YR1]=1;
    if(ipots1[XR1][YR1])
        fr1=0;
    if(ipots2[XR1][YR1])
        sr1=0;
    if(ipots1[XR2][YR2])
        fr2=0;
    if(ipots2[XR2][YR2])
        sr2=0;
    while((fr1==1e9 || sr1==1e9) && !d.empty())
    {
        int X=d[0].first;
        int Y=d[0].second;
        d.pop_front();
        for(int i=0;i<=3;++i)
        {
            int x2=X+ox[i];
            int y2=Y+oy[i];
            if(!mat[x2][y2] && !viz[x2][y2])
            {
                d.push_back({x2,y2});
                viz[x2][y2]=viz[X][Y]+1;
                if(fr1==1e9 && ipots1[x2][y2])
                    fr1=viz[x2][y2];
                if(sr1==1e9 && ipots2[x2][y2])
                    sr1=viz[x2][y2];
            }
        }
    }
    mat[XR1][YR1]=0;
    mat[XR2][YR2]=1;
    memset(viz,0,sizeof(viz));
    d.clear();
    d.push_back({XR2,YR2});
    while((fr2==1e9 || sr2==1e9) && !d.empty())
    {
        int X=d[0].first;
        int Y=d[0].second;
        d.pop_front();
        for(int i=0;i<=3;++i)
        {
            int x2=X+ox[i];
            int y2=Y+oy[i];
            if(!mat[x2][y2] && !viz[x2][y2])
            {
                d.push_back({x2,y2});
                viz[x2][y2]=viz[X][Y]+1;
                if(fr2==1e9 && ipots1[x2][y2])
                    fr2=viz[x2][y2];
                if(sr2==1e9 && ipots2[x2][y2])
                    sr2=viz[x2][y2];
            }
        }
    }
    g<<min(max(fr1,sr2),max(fr2,sr1))<<'\n';
}
int main()
{
    Read();
    LenMax();
    True();
    return 0;
}
