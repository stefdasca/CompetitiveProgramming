#include<fstream>
#include<algorithm>
using namespace std;
ifstream f("pba.in");
ofstream g("pba.out");
long long n,v[50002];
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i];
    sort(v+1,v+n+1);
    g<<(((v[n]*v[n-1])%1000000007)*(v[n-2]%1000000007))%1000000007;
    return 0;
}
