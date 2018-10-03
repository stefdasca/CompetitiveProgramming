#include<fstream>
using namespace std;
ifstream f("fsb.in");
ofstream g("fsb.out");
int n,v[400001],s;
long long sol;
char c[200001];
int main()
{
    f>>n;
    f>>c+1;
    v[200000]=1;
    for(int i=1;i<=n;++i)
    {
        if(c[i]=='1')
            ++s;
        else
            --s;
        sol+=v[s+200000];
        ++v[s+200000];
    }
    g<<sol;
    return 0;
}
