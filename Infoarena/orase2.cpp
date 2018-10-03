/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("orase2.in");
ofstream g("orase2.out");
long long n,x,c,D[50002],V[50002];
long double sum,ld,u,rez;
long long imbunatatire(int ind,long double vt)
{
    return max(0LL, (long long)(0.5 + sqrt(1.0 + 4.0 * D[ind] / vt) / 2.0)-V[ind]);
}
long long numarimbunatatiri(long double vt)
{
    long long rez=0;
    for(int i=1;i<=n;i++)
        rez+=imbunatatire(i,vt);
    return rez;
}
int main()
{
    f>>c>>n>>x;
    for(int i=1;i<=n;i++)
        f>>D[i];
    for(int i=1;i<=n;i++)
        f>>V[i];
    for(int i=1;i<=n;i++)
        ld=max(ld,(long double)(1.0*D[i]/V[i]/(V[i]+1)));
    long double st=0,dr=ld;
    for(int it=1;it<=100;it++)
    {
        long double mid=(st+dr)/2;
        long long nro=numarimbunatatiri(mid);
        if(x==nro)
        {
            u=mid;
            break;
        }
        else
            if(nro<x)
            {
                u=mid;
                dr=mid;
            }
            else
                st=mid;
    }
    for(int i=1;i<=n;i++)
    {
        long long in=imbunatatire(i,u);
        V[i]+=in;
        sum+=in;
    }
    x-=sum;
    for(int i=1;i<=n;i++)
        rez+=(long double)D[i]/V[i];
    rez-=1.0*u*x;
    g<<(long long)rez;
    return 0;
}
