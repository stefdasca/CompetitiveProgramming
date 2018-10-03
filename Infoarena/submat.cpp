#include<fstream>
#include<bitset>
using namespace std;
ifstream f("submat.in");
ofstream g("submat.out");
int n,m,solmax,nr;
int v[1002];
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            f>>nr,v[j]+=1-nr;
    for(int j=1;j<=m;++j)
        solmax=max(solmax,j*v[j]);
    g<<solmax<<'\n';
    return 0;
}
