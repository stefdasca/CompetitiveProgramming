#include<fstream>
using namespace std;
ifstream f("vila.in");
ofstream g("vila.out");
int n,m;
char c1[210];
int a[330][230],nrr[230][230];
int x[]={0,-1,0,1,0};
int y[]={0,0,1,0,-1};
struct lee
{
    int l,c;
};
lee v[60000];
int sz;
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
    {
        f.get();
        f>>(c1+1);
        for(int j=1;j<=m;++j)
            if(c1[j]=='1')
                a[i][j]=-1;
    }
    int nrc=0,smax=0;
     for(int i=1;i<=m;++i)
        a[0][i]=a[n+1][i]=-1;
      for(int i=1;i<=n;++i)
        a[i][0]=a[i][m+1]=-1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(a[i][j]==0)
            {
                ++nrc;
                int s=1;
                int e=1;
                v[s].l=i;
                v[s].c=j;
                a[i][j]=1;
                while(s<=e)
                {
                    for(int i=1;i<=4;++i)
                    {
                        int X=v[s].l+x[i];
                        int Y=v[s].c+y[i];
                        if(a[X][Y]==0)
                        {
                            a[X][Y]=a[v[s].l][v[s].c]+1;
                            ++e;
                            v[e].l=X;
                            v[e].c=Y;
                        }
                    }
                    ++s;
                }
                smax=max(smax,e);
                for(int q=1;q<=e;++q)
                    a[v[q].l][v[q].c]=e,nrr[v[q].l][v[q].c]=nrc;
            }
    for(int i=1;i<=m;++i)
        a[0][i]=a[n+1][i]=0;
      for(int i=1;i<=n;++i)
        a[i][0]=a[i][m+1]=0;
    int q=0,r=0,qm=-1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(a[i][j]==-1)
            {
                int nr1=0;
                if(nrr[i-1][j]>0)
                    nr1+=a[i-1][j];
                if(nrr[i+1][j]>0)
                    if(nrr[i+1][j]!=nrr[i-1][j])
                        nr1+=a[i+1][j];
                if(nrr[i][j+1]>0)
                    if(nrr[i][j+1]!=nrr[i+1][j] && nrr[i][j+1]!=nrr[i-1][j])
                        nr1+=a[i][j+1];
                if(nrr[i][j-1]>0)
                     if(nrr[i][j-1]!=nrr[i+1][j] && nrr[i][j-1]!=nrr[i-1][j])
                        if(nrr[i][j-1]!=nrr[i][j+1])
                            nr1+=a[i][j-1];
                if(nr1>qm)
                    qm=nr1,q=i,r=j;
            }
    g<<nrc<<'\n'<<smax<<'\n';
    g<<q<<" "<<r<<" "<<qm+1;
    return 0;
}
