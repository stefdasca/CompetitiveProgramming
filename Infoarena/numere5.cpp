#include<fstream>
#include<bitset>
using namespace std;
ifstream f("numere5.in");
ofstream g("numere5.out");
int n,nr;
bitset<500101>v;
int main()
{
    f>>n;
    for(int i=1;i<=n*n;++i)
    {
        f>>nr;
        if(nr>0 && nr<500010)
            v[nr]=1;
    }
    if(v[1]==0)
        g<<1<<" ";
    for(int i=1;i<=min(500010,n*n);++i)
        if(v[i]==1 && v[i+1]==0)
            g<<i+1<<" ";
        else
            if(v[i]==0 && v[i+1]==1){
                g<<i;
                return 0;
            }
}
