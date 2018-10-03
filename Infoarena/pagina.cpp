#include <fstream>
using namespace std;
ifstream f("pagina.in");
ofstream g("pagina.out");
int n,i,elm,v[1<<17];
long long sum,d[1<<17];
bool verif(long long x)
{
    long long sumi=0;
    for(int i=1;i<=n;++i)
    {
        sumi+=v[i];
        if(sumi>x)
            return 0;
        if(sumi==x)
            sumi-=x;
    }
    return 1;
}
int main()
{
    f>>n;
    for(i=1;i<=n;++i)
    {
        f>>v[i];
        sum+=v[i];
        elm=max(elm,v[i]);
    }
    for(i=1;i<=n;++i)
        if(sum%i==0)
            d[++d[0]]=sum/i;
    for(i=d[0];i>1;--i)
        if(d[i]>=elm)
            if(verif(d[i]))
            {
                g<<d[i];
                return 0;
            }
    g<<d[i];
    return 0;
}
