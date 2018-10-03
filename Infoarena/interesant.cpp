#include<bits/stdc++.h>
using namespace std;
ifstream f("interesant.in");
ofstream g("interesant.out");
int c,n,lmax,sol;
struct sir
{
    char c[5002];
    int l;
    bool isI;
};
sir v[202];
bool test(sir a, sir b)
{
    return strcmp(a.c,b.c)<0;
}
int main()
{
    f>>c>>n;
    for(int i=0;i<n;++i)
    {
        f>>v[i].c;
        v[i].l=strlen(v[i].c);
        lmax=max(lmax,v[i].l);
    }
    if(c==1)
    {
        sort(v,v+n,test);
        int i=0;
        while(v[i].l<lmax)
            ++i;
        g<<v[i].c<<'\n';
    }
    else
    {
        for(int i=0;i<n;++i)
        {
            bool ok=1;
            for(int j=0;j<n;++j)
                if(j!=i && v[i].l<=v[j].l)
                {
                    int poz=0;
                    for(int z=0;z<v[j].l;++z)
                        if(v[i].c[poz]==v[j].c[z]){
                            ++poz;
                            if(poz==v[i].l)
                                break;
                        }
                    if(poz==v[i].l)
                        ok=0,j=n;
                }
            v[i].isI=ok;
            sol+=ok;
        }
        g<<sol<<'\n';
        for(int i=0;i<n;++i)
            if(v[i].isI)
                g<<v[i].c<<'\n';
    }
    return 0;
}
