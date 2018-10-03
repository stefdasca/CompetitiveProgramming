#include<bits/stdc++.h>
using namespace std;
ifstream f("castel3.in");
ofstream g("castel3.out");
int c,n,a[102][102],vis[102][102];
int Area,NrRooms, HighestArea,xa,ya,xb,yb;
int MaxX,MaxY;
int ox[]={-1,0,1,0};
int oy[]={0,1,0,-1};
int bts[]={8,4,2,1};
void Fill(int L, int C)
{
    vis[L][C]=1;
    ++Area;
    MaxX=max(MaxX,L);
    MaxY=max(MaxY,C);
    for(int j=0;j<=3;++j)
    {
        int X=L+ox[j];
        int Y=C+oy[j];
        if(vis[X][Y])
            continue;
        if(!(a[L][C]&bts[j]))
            Fill(X,Y);
    }
}
int main()
{
    f>>c;
    f>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            f>>a[i][j];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        {
            if(vis[i][j])
                continue;
            if(a[i][j]&1 && a[i][j]&8)
            {
                Area=0;
                ++NrRooms;
                MaxX=0;
                MaxY=0;
                Fill(i,j);
                if(Area>HighestArea)
                {
                    HighestArea=Area;
                    xa=i;
                    ya=j;
                    xb=MaxX;
                    yb=MaxY;
                }
            }
        }
    if(c==1)
        g<<NrRooms;
    if(c==2)
        g<<HighestArea;
    if(c==3)
        g<<xa<<" "<<ya<<" "<<xb<<" "<<yb<<'\n';
    return 0;
}
