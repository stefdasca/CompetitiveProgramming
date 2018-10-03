#include<fstream>
using namespace std;
ifstream f("raze.in");
ofstream g("raze.out");
int n,m,t;
bool a[140][140];
int dp[140][140],ds[140][140];
int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>n>>m;
        int kmax=0;
        int nrmax=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                f>>a[i][j],dp[i][j]=ds[i][j]=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                dp[i][j]=a[i][j]+dp[i-1][j-1];
        for(int i=1;i<=n;++i)
            for(int j=m;j>=1;--j)
                ds[i][j]=a[i][j]+ds[i-1][j+1];
        for(int i=2;i<n;++i)
            for(int j=2;j<m;++j)
                if(a[i][j]==0)
                {
                    int scor=0;
                    if(dp[i][j]==0)
                        ++scor;
                    int min1=min(n-i,m-j);
                    if(dp[i+min1][j+min1]-dp[i][j]==0)
                        ++scor;
                    if(ds[i][j]==0)
                        ++scor;
                    min1=min(n-i,j-1);
                    if(ds[i][j]-ds[i+min1][j-min1]==0)
                        ++scor;
                    if(scor>kmax)
                        kmax=scor,nrmax=1;
                    else
                        if(scor==kmax)
                            ++nrmax;
                }
        g<<kmax<<" "<<nrmax<<'\n';
    }
    return 0;
}
