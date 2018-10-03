#include<fstream>
#include<cmath>
using namespace std;
ifstream f("trecere.in");
ofstream g("trecere.out");
int m,n;
int x;
int dmin=1e9;
int cmin,colmin;
struct colors
{
    int l[130],c[130];
    int d;
};
colors v[130];
void bul()
{
    for(int i=1;i<=n;++i)
    {
        bool ok=1;
        while(ok)
        {
            ok=0;
            for(int j=1;j<v[i].d;++j)
                if(v[i].l[j]>v[i].l[j+1] || v[i].l[j]==v[i].l[j+1] && v[i].c[j]>v[i].c[j+1])
                {
                    swap(v[i].l[j],v[i].l[j+1]);
                    swap(v[i].c[j],v[i].c[j+1]);
                    ok=1;
                }
        }
        int d=0;
        for(int j=1;j<=n;++j)
        {
            d=0;
            for(int a=1;a<=v[i].d;++a)
                d+=abs(v[i].l[a]-a)+abs(v[i].c[a]-j);
            if(d<dmin)
                dmin=d,colmin=i,cmin=j;
        }
    }
}
int main()
{
    f>>m>>n;
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
        {
            f>>x;
            v[x].d++;
            v[x].l[v[x].d]=i;
            v[x].c[v[x].d]=j;
        }
    bul();
    g<<dmin<<" "<<colmin<<" "<<cmin<<'\n';
    return 0;
}
