#include<fstream>
#include<algorithm>
using namespace std;
ifstream f("light.in");
ofstream g("light.out");
int n,nrmax;
struct s
{
    int b,e;
};
s v[100002];
bool test(s a, s b)
{
    return a.b<b.b;
}
int rmin=2e9,nrmin;
int main()
{
    f>>n>>nrmax;
    for(int i=1;i<=n;++i)
    {
        f>>v[i].b>>v[i].e;
        v[i].e+=v[i].b;
    }
    sort(v+1,v+n+1,test);
    int b=1;
    int e=2000000000;
    // raza posibila
    while(b<=e)
    {
        int m=(b+e)/2;
        int nrs=0;
        int poz=v[1].b;
        for(int i=1;i<=n;++i)
        {
            if(poz<=v[i].b)
            {
                poz=v[i].b;
                nrs+=(v[i].e-v[i].b)/m;
                poz+=((v[i].e-v[i].b)/m)*m;
                if((v[i].e-v[i].b)%m)
                    ++nrs,poz+=m;
            }
            else
                if(poz<=v[i].e)
                {
                    nrs+=(v[i].e-poz)/m;
                    poz+=((v[i].e-poz)/m)*m;
                    if((v[i].e-poz)%m)
                        ++nrs,poz+=m;
                }
        }
        if(nrs<=nrmax)
        {
            e=m-1;
            if(m<rmin)
                rmin=m,nrmin=nrs;
        }
        else
            b=m+1;
    }
    g<<rmin<<" "<<nrmin<<'\n';
    return 0;
}
