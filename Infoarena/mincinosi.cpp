#include<fstream>
using namespace std;
ifstream f("mincinosi.in");
ofstream g("mincinosi.out");
int n,v[1000002],fr[1000002];
int nrmax,nr;
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i],fr[v[i]]++;
    for(int i=0;i<n;++i)
        if(fr[i]==n-i)
            if(fr[i]>nrmax)
                nrmax=fr[i],nr=i;
    g<<nrmax<<'\n';
    for(int i=1;i<=n;++i)
        if(v[i]==nr)
            g<<i<<'\n';
    return 0;
}
