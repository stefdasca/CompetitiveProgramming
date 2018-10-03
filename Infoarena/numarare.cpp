#include<fstream>
using namespace std;
ifstream f("numarare.in");
ofstream g("numarare.out");
int i,p,sol,n,a[1<<17],v[1<<17];
int main()
{
    f>>n>>v[1];
    for(i=2;i<=n;++i)
    {
        f>>v[i];
        v[i-1]-=v[i];
    }
    --n;
    for(i=p=1;i<=n;++i)
    {
        if(i<p+a[p])
            a[i]=min(a[2*p-i],p+a[p]-i);
        if(i+a[i]>=p+a[p])
        {
            p=i;
            while(i-a[i]>=2&&i+a[i]<n&&v[i-a[i]-1]==v[i+a[i]+1])
                ++a[i];
        }
    }
    for(i=1;i<=n;++i)
        sol+=a[i];
    g<<sol+n<<'\n';
    return 0;
}
