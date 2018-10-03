#include<bits/stdc++.h>
using namespace std;
ifstream f("drum6.in");
ofstream g("drum6.out");
int n,m,X,Y,z,i,pp,j,bur;
char a[1002][1002],cmin1,zz;
bool waiq[1002][1002];
struct q
{
    short l,c;
};
q v[1000002];
int stu=1,eu=1;
int ox[]={0,1};
int oy[]={1,0};
int main()
{
    f>>n>>m;
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            f>>zz,a[i][j]=zz;
    g<<a[1][1];
    v[1].l=1;
    v[1].c=1;
    for(pp=2;pp<n+m;++pp)
    {
        bur=eu;
        cmin1='z'+1;
        for(z=stu;z<=eu;++z)
            for(int i=0;i<=1;++i)
            {
                X=v[z].l+ox[i];
                Y=v[z].c+oy[i];
                if(X<=n && Y<=m)
                    if(a[X][Y]<cmin1)
                        cmin1=a[X][Y];
            }
        for(z=stu;z<=eu;++z)
            for(i=0;i<=1;++i)
            {
                X=v[z].l+ox[i];
                Y=v[z].c+oy[i];
                if(X<=n && Y<=m)
                    if(a[X][Y]==cmin1 && waiq[X][Y]==0)
                    {
                        ++bur;
                        v[bur].l=X;
                        v[bur].c=Y;
                        waiq[X][Y]=1;
                    }
            }
        stu=eu+1;
        eu=bur;
        g<<cmin1;
    }
    return 0;
}
