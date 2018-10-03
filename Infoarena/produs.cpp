/// #bettercoderthanshebeautiful
#define eps 1e-7
#include<bits/stdc++.h>
using namespace std;
ifstream f("produs.in");
ofstream g("produs.out");
int stsir,sfsir,L=1,R=1,sf;
char c[10002];
bool prim[100002];
int a[10002],v[10002],aux[10002];
double LogN, LogA;
inline bool gut(int nr)
{
    int md=0;
    for(int i=v[0];i;--i)
    {
        md=(md*10000+v[i]);
        aux[i]=md/nr;
        md%=nr;
    }
    if(md)
        return 0;
    md=0;
     for(int i=a[0];i;--i)
        v[i]=aux[i];
    while(v[v[0]]==0)
        --v[0];
    return 1;
}
void Sieve()
{
    for(int i=2;i<=100000;i++)
        if(!prim[i])
        {
            while(gut(i))
                LogN+=log10(0.0+(double)i);
            for(int j=i+i;j<=100000;j+=i)
                prim[j]=1;
        }
}
int main()
{
    f>>c+1;
    stsir=1;
    sfsir=strlen(c+1);
    for(int i=1;i<=sfsir;++i)
        a[i]=c[i]-'0';
    a[0]=sfsir;
    for(int i=a[0]; i>0; i-=4){
        v[0]++;
        for(int j=max(1, i-3); j<=i; j++)
            v[v[0]]=10*v[v[0]]+a[j];
    }
    Sieve();
    int L=1,R=1;
    while(abs(LogN-LogA)>eps)
        if(LogN>LogA)
            LogA+=log10(0.0+(++R));
        else
            LogA-=log10(0.0+(++L));
    g<<L+1<<" "<<R<<'\n';
    return 0;
}
