#include <fstream>
#define MOD 666013
using namespace std;
ifstream f("invazie.in");
ofstream g("invazie.out");
int T;
long long n;
long long a,b,rez,k,p;
long long pw(long long x,long long p)
{
    long long rez=1;
    while(p)
    {
        if(p&1)
            rez=(rez*x)%MOD;
        x=(x*x)%MOD;
        p>>=1;
    }
    return rez;
}
int main()
{
    f>>T;
    for(;T;--T)
    {
        f>>k>>p>>n;
        k%=MOD,p%=MOD;
        a=pw((k+p)%MOD,n);
        b=pw((k-p)%MOD,n);
        rez=((a+b)%MOD+MOD)*333007%MOD;
        g<<rez<<'\n';
    }
    return 0;
}
