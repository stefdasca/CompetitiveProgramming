#include<fstream>
using namespace std;
ifstream f("paralelograme.in");
ofstream g("paralelograme.out");
int i,j,n,m,s,x,C[2009][2009];
long long sol;
int main()
{
    f>>n>>m;
    for(i=1;i<=2000;++i)
        C[1][i]=C[i][1]=1;
    for(i=2;i<=2000;++i)
        for(x=i;x<=2000;x+=i)
            for(j=i;j<=2000;j+=i)
                C[x][j]=i;
    for(i=2;i<=n+1;++i)
        for(j=2;j<=m+1;++j)
        {
            s=(i-2)*(j-2)+i*j-(C[i-1][j-1]?C[i-1][j-1]:1)-2;
            sol+=1LL*(n-i+2)*(m-j+2)*s;
        }
    g<<sol;
    return 0;
}
