#include<bits/stdc++.h>
using namespace std;
ifstream f("gfact.in");
ofstream g("gfact.out");
long long b,e;
long long l;
struct diq
{
    long long nr,p;
};
diq v[1002];
int main()
{
    f>>b>>e;
    for(long long i=2;i*i<=b;++i)
        if(b%i==0)
        {
            v[++l].nr=i;
            while(b%i==0)
                b/=i,++v[l].p;
        }
    if(b>1)
        v[++l].nr=b,v[l].p=1;
    for(long long i=1;i<=l;++i)
        v[i].p*=e;
    long long sol=0;
    for(long long i=1;i<=l;++i){
        long long p=0,j;
        for(j=v[i].nr;p<v[i].p;)
            {
                long long k=j;
                while(k%v[i].nr==0)
                    ++p,k/=v[i].nr;
                if(p<v[i].p)
                    j+=v[i].nr;
            }
        sol=max(sol,j);
    }
    g<<sol<<'\n';
}
