#include<fstream>
using namespace std;
ifstream f("sudest.in");
ofstream g("sudest.out");
int n,k;
int vv[203],a[102][102],mxs[102][102];
struct lm
{
    short l,c,d;
};
lm v[90000];
bool ox[]={0,1};
bool oy[]={1,0};
lm z[302];
void init()
{
    f>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            f>>a[i][j];
    mxs[1][1]=a[1][1];
    v[1].l=1;
    v[1].c=1;
    v[1].d=1;
    f>>k;
    for(int i=1;i<=k;++i)
        f>>vv[i];
}
int main()
{
    init();
    int b=1;
    int e=1;
    while(b<=e)
    {
        if(v[b].d<=k)
            for(int j=0;j<=1;++j)
            {
                int x=v[b%88000].l+ox[j]*vv[v[b%88000].d];
                int y=v[b%88000].c+oy[j]*vv[v[b%88000].d];
                if(x<=n && y<=n)
                    if(mxs[v[b%88000].l][v[b%88000].c]+a[x][y]>mxs[x][y])
                    {
                        mxs[x][y]=mxs[v[b%88000].l][v[b%88000].c]+a[x][y];
                        ++e;
                        v[e%88000].l=x;
                        v[e%88000].c=y;
                        v[e%88000].d=v[b].d+1;
                    }
            }
        ++b;
    }
    z[1].l=n;
    z[1].c=n;
    for(int i=2;i<=k+1;++i)
    {
        if(mxs[z[i-1].l][z[i-1].c]-a[z[i-1].l][z[i-1].c]==mxs[z[i-1].l][z[i-1].c-vv[k-i+2]])
            z[i].l=z[i-1].l,z[i].c=z[i-1].c-vv[k-i+2];
        else
            z[i].l=z[i-1].l-vv[k-i+2],z[i].c=z[i-1].c;
    }
    g<<mxs[n][n]<<'\n';
    for(int i=k+1;i>=1;--i)
        g<<z[i].l<<" "<<z[i].c<<'\n';
    return 0;
}
