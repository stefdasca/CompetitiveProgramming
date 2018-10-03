#include<fstream>
#include<algorithm>
using namespace std;
ifstream f("concurs2.in");
ofstream g("concurs2.out");
int nj,j[52],n;
int pb[52];
struct stud
{
    int a,b;
};
stud v[502];
bool test(stud a, stud b)
{
    if(a.a==b.a)
        return a.b<b.b;
    return a.a<b.a;
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
    {
        f>>v[i].a>>v[i].b;
        j[v[i].a]++;
    }
    sort(v+1,v+n+1,test);
    for(int i=1;i<=50;++i)
        if(j[i])
            ++nj;
    g<<nj<<'\n';
    for(int i=1;i<=50;++i)
        if(j[i])
            g<<j[i]<<" ";
    g<<'\n';
    for(int i=1;i<=n;++i)
        if(v[i].a!=v[i-1].a)
            pb[v[i].a]=i;
    int prvj=0;
    for(;n;--n)
    {
        int jmax=0;
        int pmax=0;
        for(int i=1;i<=50;++i)
            if(j[i]>jmax && i!=prvj)
                jmax=j[i],pmax=i;
        prvj=pmax;
        g<<v[pb[prvj]].a<<" "<<v[pb[prvj]].b<<'\n';
        ++pb[prvj];
        --j[prvj];
    }
    return 0;
}
