#include<fstream>
using namespace std;
ifstream f("bila.in");
ofstream g("bila.out");
unsigned short n,m,a[130][130],lmax,nrmin,scor,max1[130][130],b,e;
struct q
{
    short l,c;
};
q v[24000];
short ox[5]={0,-1,0,1,0};
short oy[5]={0,0,1,0,-1};
void coada()
{
    while(b<=e)
    {
        for(int i=1;i<=4;++i)
        {
            int X=v[b].l+ox[i];
            int Y=v[b].c+oy[i];
            scor=0;
            if(a[X][Y]>a[v[b].l][v[b].c]){
                if(a[v[b].l][v[b].c]<=a[X-1][Y])
                    ++scor;
                 if(a[v[b].l][v[b].c]<=a[X+1][Y])
                    ++scor;
                 if(a[v[b].l][v[b].c]<=a[X][Y-1])
                    ++scor;
                 if(a[v[b].l][v[b].c]<=a[X][Y+1])
                    ++scor;
                if(scor==4 && max1[X][Y]==0)
                    {
                        ++e;
                        v[e].l=X;
                        v[e].c=Y;
                        max1[X][Y]=max1[v[b].l][v[b].c]+1;
                    }
            }
        }
        ++b;
    }
}
int main()
{
    f>>n>>m;
    unsigned short maxq=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            f>>a[i][j],maxq=max(maxq,a[i][j]);
    for(int i=1;i<=n;++i)
        a[i][0]=maxq+1,a[i][m+1]=maxq+1;
    for(int i=1;i<=m;++i)
        a[0][i]=a[n+1][i]=maxq+1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(a[i][j]<a[i-1][j] && a[i][j]<a[i][j-1])
                if(a[i][j]<a[i+1][j] && a[i][j]<a[i][j+1]){
                    max1[i][j]=1;
                    v[1].l=i;
                    v[1].c=j;
                    b=e=1;
                    coada();
                }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(max1[i][j]>lmax)
                lmax=max1[i][j],nrmin=a[i][j];
            else
                if(max1[i][j]==lmax)
                    nrmin=min(nrmin,a[i][j]);
    g<<lmax<<" "<<nrmin;
    return 0;
}
