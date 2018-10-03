#include<fstream>
using namespace std;
ifstream f("rland.in");
ofstream g("rland.out");
int n,l,c;
int a[200][200];
int sum[200][200];
int main()
{
    f>>n>>l>>c;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            f>>a[i][j];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            sum[i][j]=a[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
    int sol1=-4900394;
    int sol2=-4200005;
    for(int i=l;i<=n;++i)
        for(int j=c;j<=n;++j)
        {
            int sol=sum[i][j]-sum[i-l][j]-sum[i][j-c]+sum[i-l][j-c];
            sol1=max(sol1,sol);
        }
    for(int i=1;i<=n;++i)
        for(int j=c;j<=n;++j)
            for(int k=1;k<=l && k<=i;++k)
            {
                int sol=sum[i][j]-sum[i-k][j]-sum[i][j-c]+sum[i-k][j-c];
                sol2=max(sol2,sol);
            }
    g<<sol1<<'\n';
    g<<sol2<<'\n';
    return 0;
}
