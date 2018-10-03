#include <fstream>
using namespace std;
ifstream f("intersort.in");
ofstream g("intersort.out");
int n,i,x,poz,sol,v[1<<17];
void rez_cycle()
{
    int x=poz,lung=0;
    while(v[x]!=x)
    {
        ++lung;
        int ult=x;
        x=v[x];
        v[ult]=ult;
    }
    sol+=lung-1;
}
int main()
{
    f>>n;
    for(i=1;i<=n;++i)
    {
        f>>v[i];
        if(v[i]==1)
            poz=i;
    }
    rez_cycle();
    for(i=2;i<=n;++i)
        if(v[i]!=i)
        {
            poz=i;
            swap(v[1],v[i]);
            rez_cycle();
            sol++;
        }
    g<<sol;
    return 0;
}
