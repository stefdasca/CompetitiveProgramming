#include <fstream>
#define nmax 10
#define pmax 1000
using namespace std;
ifstream f("sumall.in");
ofstream g("sumall.out");
unsigned long long n,apar[nmax],p=1,t,suma=0;
int cifre[nmax],nc=0;
int nr[pmax];
int main()
{
    int i,j,k;
    unsigned long long t;
    f>>n;
    while(n)
    {
        cifre[n%10]++;
        n=n/10;
        nc++;
    }
    for(i=1;i<nc;i++)
        p=p*i;
    for(i=1;i<=9;i++)
        if (cifre[i])
        {
            t=p;
            for(j=1;j<=9;j++)
                for(k=1;k<cifre[j]+(i!=j);k++)
                    t/=k;
            apar[i]=t;
        }
    for(i=1;i<=9;i++)
        suma+=i*apar[i];
    k=0;t=0;
    for(i=1;i<=nc;i++)
    {
         nr[++k]=(t+suma)%10;
         t=(t+suma)/10;
    }
    if(t)
        g<<t;
    for(i=nc;i>=1;i--)
        g<<nr[i];
    return 0;
}
