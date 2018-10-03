#include<bits/stdc++.h>
using namespace std;
ifstream f("tsunami.in");
ofstream g("tsunami.out");
int n,m,max1;
int a[1002][1002];
bool af[1002][1002];
int sol;
int ox[]={-1,0,1,0};
int oy[]={0,1,0,-1};
struct coada
{
    int l,c;
};
coada v[1000002];
int main()
{
    f>>n>>m>>max1;
    int st=1;
    int sf=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            f>>a[i][j];
            if(a[i][j]==0)
                ++sf,v[sf].l=i,v[sf].c=j,af[i][j]=1;
        }
    for(int i=1;i<=n;++i)
        a[i][0]=a[i][m+1]=12;
    for(int i=1;i<=m;++i)
        a[0][i]=a[n+1][i]=12;
    while(st<=sf)
    {
        for(int i=0;i<=3;++i)
        {
            int X=v[st].l+ox[i];
            int Y=v[st].c+oy[i];
            if(a[X][Y]<max1 && af[X][Y]==0)
            {
                ++sf;
                v[sf].l=X;
                v[sf].c=Y;
                af[X][Y]=1;
            }
        }
        ++st;
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(a[i][j]>0 && af[i][j]==1)
                ++sol;
    g<<sol<<'\n';
    return 0;
}
