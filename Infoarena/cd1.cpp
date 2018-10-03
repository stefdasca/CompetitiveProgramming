#include<fstream>
using namespace std;
ifstream f("cd.in");
ofstream g("cd.out");
long long n,k,p=1,v[302];
long long nr,d;
int main()
{
    f>>n>>k;
    for(int i=1;i<=n;++i)
        v[i]=k/n;
    for(int i=1;i<=n;++i)
    {
        f>>nr>>d;
        v[i]+=nr;
        v[d]-=nr;
    }
    for(int i=1;i<=n;++i)
        p=(p*(v[i]-1))%9901;
    g<<p;
    return 0;
}
