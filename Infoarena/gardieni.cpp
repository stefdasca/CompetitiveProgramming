#include<fstream>
using namespace std;
ifstream f("gardieni.in");
ofstream g("gardieni.out");
int n,i,t,j,a,b,c,v[1000002];
long long s;
int main()
{
    f>>n>>t;
    for(i=1;i<=n;++i)
    {
        f>>a>>b>>c;
        for(j=a;j<=b;++j)
            if(!v[j]||v[j]>c) v[j]=c;
    }
    for(i=1;i<=t;++i)
        s+=v[i];
    g<<s;
    return 0;
}
