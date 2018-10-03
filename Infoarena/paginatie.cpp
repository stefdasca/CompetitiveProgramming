// I hate 3 things
// First one is communism
// Second one is Biology
// Third and the most important one is backbiter people
#include<bits/stdc++.h>
using namespace std;
ifstream f("paginatie.in");
ofstream g("paginatie.out");
int lp,x;
struct sc
{
    char c[52];
};
sc v[1002];
char c[53];
int main()
{
    f>>lp>>x;
    int nrsf=0;
    int lc=0;
    int nrr=0;
    while(f>>c)
    {
        if(lc+nrsf+strlen(c)<=x)
        {
            ++nrsf;
            strcpy(v[nrsf].c,c);
            lc+=strlen(c);
        }
        else
        {
            if(nrsf==1)
                g<<v[1].c<<'\n';
            else
            {
                int xtsp=x-strlen(c)-lc-nrsf;
                int mod=xtsp%(nrsf-1);
                xtsp/=(nrsf-1);
                for(int i=1;i<nrsf;++i)
                {
                    g<<v[i].c<<" ";
                    if(mod)
                        g<<" ",--mod;
                    for(int j=1;j<=xtsp;++j)
                        g<<" ";
                }
                g<<v[nrsf].c<<'\n';
            }
            ++nrr;
            nrsf=1;
            lc=strlen(c);
            if(nrr==lp)
                g<<'\n',nrr=0;
            strcpy(v[nrsf].c,c);
        }
    }
    for(int i=1;i<nrsf;++i)
        g<<v[i].c<<" ";
    g<<v[nrsf].c;
    return 0;
}
