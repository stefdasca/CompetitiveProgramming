#include<fstream>
#include<algorithm>
using namespace std;
ifstream f("2numere.in");
ofstream g("2numere.out");
int n,a[12],b[12],nr1,nr2;
int dmin=1e9,x1,x2;
int poz1=1,poz2=1;
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
    {
        f>>a[i];
        poz1*=i;
        poz2*=i;
    }
    for(int i=1;i<=n;++i)
    {
        f>>b[i];
    }
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    for(int i=1;i<=n;++i)
        nr1=nr1*10+a[i],nr2=nr2*10+b[i];
    --poz1;
    --poz2;
    while(poz1 && poz2)
    {
        if(nr1>=nr2)
        {
            if(nr1-nr2<dmin)
                dmin=nr1-nr2,x1=nr1,x2=nr2;
            next_permutation(b+1,b+n+1);
            nr2=0;
            for(int i=1;i<=n;++i)
                nr2=nr2*10+b[i];
            --poz2;
        }
        else
        {
            next_permutation(a+1,a+n+1);
            nr1=0;
            for(int i=1;i<=n;++i)
                nr1=nr1*10+a[i];
            --poz1;
        }
    }
    while(poz2)
    {
        if(nr1-nr2<dmin && nr1>nr2)
            dmin=nr1-nr2,x1=nr1,x2=nr2;
        next_permutation(b+1,b+n+1);
        nr2=0;
        for(int i=1;i<=n;++i)
            nr2=nr2*10+b[i];
        --poz2;
    }
    g<<x1<<'\n'<<x2<<'\n'<<dmin;
    return 0;
}
