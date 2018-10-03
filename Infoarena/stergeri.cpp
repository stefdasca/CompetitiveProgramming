#include <fstream>
using namespace std;
int n,m,k,i,poz;
int x[100001],y[100001];
ifstream fi("stergeri.in");
ofstream fo("stergeri.out");
int main()
{
    fi>>n>>m>>k;
    poz=k;
    for(i=1;i<=m;i++)
        fi>>x[i]>>y[i];
    for(i=m;i>=1;i--)
        if(x[i]<=poz)
        poz+=y[i]-x[i]+1;
    fo<<poz;
    return 0;
}
