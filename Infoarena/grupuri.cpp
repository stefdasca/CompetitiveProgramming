#include<fstream>
using namespace std;
ifstream f("grupuri.in");
ofstream g("grupuri.out");
long long k,n,a[100010],s;
int main()
{
    f>>k>>n;
    for(int i=1;i<=n;i++)
    {
        f>>a[i];
        s+=a[i];
    }
    while(s/k<a[n])
    {
        s-=a[n];
        n--;
        k--;
    }
    g<<s/k<<'\n';
    return 0;
}
