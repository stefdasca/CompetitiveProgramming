#include <fstream>
#define inf 1<<30
using namespace std;
ifstream f("valentin.in");
ofstream g("valentin.out");
long long sum[2][2],pos[2][2];
int n,v[600005],i,j,k,p;
void cit()
{
    f>>p>>n;
    for(i=1;i<=n;++i)
        f>>v[i];
    for(j=0;j<2;++j)
        sum[0][j]=sum[1][j]=-inf;
}
void possible(long long &x,long long &p,long long y,long long posi)
{
    if(y>x)
        x=y,p=posi;
    else
        if(y==x)
            p+=posi;
}
int main()
{
    cit();
    for(i=1;i<=n;++i)
    {
        for (j=0;j<2;++j)
            if(sum[0][j]!=-inf)
            {
                k=(j+v[i])&1;
                k+=2;k&=1;
                possible(sum[1][k],pos[1][k],sum[0][j]+v[i],pos[0][j]);
            }
        k=v[i]&1;
        k+=2;k&=1;
        possible(sum[1][k],pos[1][k],v[i],1);
        for(j=0;j<2;++j)
        {
            possible(sum[0][j],pos[0][j],sum[1][j],pos[1][j]);
            sum[1][j]=-inf;
            pos[1][j]=0;
        }
    }
    if(p==1)
        g<<sum[0][0];
    else
        g<<pos[0][0];
    return 0;
}
