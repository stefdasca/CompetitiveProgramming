#include<bits/stdc++.h>
using namespace std;
ifstream f("dreptunghiuri2.in");
ofstream g("dreptunghiuri2.out");
int n,m;
bool mat[1002][1002];
int nz,zm,hm;
int ox[]={0,1,0,-1};
int oy[]={1,0,-1,0};
void pr(int Lcx,int Lcy,int Rcx,int Rcy,int ord)
{
    for(int i=Lcx;i<=Rcx;++i)
        for(int j=Lcy;j<=Rcy;++j)
            if(mat[i][j]==1)
            {
                int x=i;
                int y=j;
                int dir=0;
                int R=0;
                int O=0;
                while(mat[x][y]==1)
                {
                    mat[x][y]=0;
                    if(mat[x+ox[dir]][y+oy[dir]]==0 && dir!=3){
                        ++dir;
                        if(dir==2)
                            R=x,O=y;
                    }
                    x+=ox[dir];
                    y+=oy[dir];
                    if(mat[x][y]==0 && (x!=i || y!=j))
                    {
                        R=x-ox[dir];
                        O=y-oy[dir];
                    }
                }
                ++nz;
                if(ord+1>zm)
                    zm=ord+1,hm=1;
                else
                    if(ord+1==zm)
                        ++hm;
                if(R-i>3 && O-j>3)
                    pr(i+2,j+2,R-2,O-2,ord+1);
            }
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            f>>mat[i][j];
    pr(1,1,n,m,0);
    g<<nz<<" "<<zm<<" "<<hm<<'\n';
    return 0;
}
