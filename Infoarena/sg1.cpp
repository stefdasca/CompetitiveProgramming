#include<fstream>
#define N 110
using namespace std;
ifstream f("sg1.in");
ofstream g("sg1.out");
void ad(int A[],int B[])
{
    int t=0,i;
    for(i=1;i<=B[0] || i<=A[0] || t;i++,t/=10)
        A[i]=(t+=A[i]+B[i])%10;
    A[0]=i-1;
}
int i,n,j,k,d1,K,d2;
int D[N][N][N],sol[N];
int main ()
{
    f>>n>>K>>d1>>d2;
    for(i=1;i<=n;++i)
        D[i][1][0]=D[i][1][1]=1;
    for(i=1;i<=n;++i)
        for(j=2;j<=K && j<=i;++j)
            for(k=max(1,i-d2-1);k<=i-d1-1;++k)
                ad(D[i][j],D[k][j-1]);
    for(i=1;i<=n;++i)
        ad(sol,D[i][K]);
    if(!sol[0])
        sol[0]=1;
    for(i=sol[0];i>=1;--i)
        g<<sol[i];
    return 0;
}
