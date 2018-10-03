#include<bits/stdc++.h>
using namespace std;
ifstream f("padure.in");
ofstream g("padure.out");
int n,m;
int a[1002][1002];
bool isv[1002][1002];
int cmin[1002][1002];
int xs,ys,xe,ye;
int ox[]={-1,0,1,0};
int oy[]={0,1,0,-1};
deque<pair<int,int>>d;
pair<int,int>z;
int st,sf,st1,sf1;
int main()
{
    f>>n>>m>>xs>>ys>>xe>>ye;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            f>>a[i][j];
    for(int i=1;i<=n;++i){
        isv[i][0]=isv[i][m+1]=1;
        cmin[i][0]=cmin[i][m+1]=-1e9;
    }
    for(int i=1;i<=m;++i){
        isv[0][i]=isv[n+1][i]=1;
        cmin[0][i]=cmin[n+1][i]=-1e9;
    }
    isv[xs][ys]=1;
    z=make_pair(xs,ys);
    d.push_back(z);
    for(int pp=0;pp<=1000 && !isv[xe][ye];++pp){
        int stp=st;
        while(st<=sf)
        {
            for(int i=0;i<=3;++i)
            {
                int x=ox[i]+d[st].first;
                int y=oy[i]+d[st].second;
                if(isv[x][y]==0 && a[d[st].first][d[st].second]==a[x][y])
                {
                    isv[x][y]=1;
                    cmin[x][y]=cmin[d[st].first][d[st].second];
                    z=make_pair(x,y);
                    d.push_back(z);
                    ++sf;
                }
            }
            ++st;
        }
        st1=stp;
        sf1=sf;
        while(st1<=sf1)
        {
            for(int i=0;i<=3;++i)
            {
                int x=ox[i]+d[st1].first;
                int y=oy[i]+d[st1].second;
                if(isv[x][y]==0 && a[d[st1].first][d[st1].second]!=a[x][y] && cmin[d[st1].first][d[st1].second]==pp)
                {
                    isv[x][y]=1;
                    cmin[x][y]=cmin[d[st1].first][d[st1].second]+1;
                    z=make_pair(x,y);
                    d.push_back(z);
                    ++sf;
                }
            }
            ++st1;
        }
        st=st1;
    }
    g<<cmin[xe][ye]<<'\n';
    return 0;
}
