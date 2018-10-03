/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("go.in");
ofstream g("go.out");
int n,m,a[1002][1002],mr;
int hmg[1002][1002],alc[1002][1002];
bool mrk[1002][1002];
struct areas
{
    int nrf,sz;
    int x,y;
};
areas vv[300002];
deque<pair<int,int> >d;
int ox[]={-1,0,1,0};
int oy[]={0,1,0,-1};
void vf(int i, int j)
{
    int v[5]={0};
    int len=0;
    for(int k=0;k<=3;++k)
        if(a[i+ox[k]][j+oy[k]]==2)
            v[++len]=alc[i+ox[k]][j+oy[k]];
    sort(v+1,v+len+1);
    for(int k=1;k<=len;++k)
        if(v[k]!=v[k-1])
        {
            ++vv[v[k]].nrf;
            if(vv[v[k]].nrf==1)
                vv[v[k]].x=i,vv[v[k]].y=j;
        }
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            f>>a[i][j];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(a[i][j]==2 && !mrk[i][j])
            {
                d.push_back({i,j});
                ++mr;
                mrk[i][j]=1;
                alc[i][j]=mr;
                ++vv[mr].sz;
                while(!d.empty())
                {
                    int X=d[0].first;
                    int Y=d[0].second;
                    d.pop_front();
                    for(int q=0;q<=3;++q)
                    {
                        int X2=X+ox[q];
                        int Y2=Y+oy[q];
                        if(a[X2][Y2]==2 && !mrk[X2][Y2])
                        {
                            mrk[X2][Y2]=1;
                            d.push_back({X2,Y2});
                            alc[X2][Y2]=mr;
                            ++vv[mr].sz;
                        }
                    }
                }
            }
    int mxl=0,mxc=0,hm=-1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(a[i][j]==0)
                vf(i,j);
    for(int i=1;i<=mr;++i)
        if(vv[i].nrf==1)
            hmg[vv[i].x][vv[i].y]+=vv[i].sz;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(a[i][j]==0 && hmg[i][j]>hm)
                hm=hmg[i][j],mxl=i,mxc=j;
    g<<mxl-1<<" "<<mxc-1<<'\n';
    return 0;
}
