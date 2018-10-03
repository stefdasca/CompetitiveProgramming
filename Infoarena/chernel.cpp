#include <fstream>
using namespace std;
ifstream f("chernel.in");
ofstream g("chernel.out");
int n,m,i,j,sol,a,act,fact[25],fr[25],e[25];
bool is_good()
{
    for(int k=1;k<=fact[0];++k)
        if(fr[k]<e[k])
            return 0;
    return 1;
}
int main()
{
    f>>n>>m;
    for(i=2;i*i<=m;i++)
        if(m%i==0)
        {
            fact[++fact[0]]=i;
            while(m%i==0)
                m/=i,++e[fact[0]];
        }
    if(m>1)
        ++fact[0],fact[fact[0]]=m,++e[fact[0]];
    for(i=1;i<n;++i)
    {
        a=(n-i);
        for(j=1;j<=fact[0];++j)
            while(a%fact[j]==0)
            {
                ++fr[j];
                a/=fact[j];
            }
        a=i;
        for(j=1;j<=fact[0];++j)
            while(a%fact[j]==0)
        {
            --fr[j];
            a/=fact[j];
        }
        sol+=is_good();
    }
    g<<sol;
    return 0;
}
