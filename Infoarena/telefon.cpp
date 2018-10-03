#include<bits/stdc++.h>
using namespace std;
ifstream f("telefon.in");
ofstream g("telefon.out");
long long nr,li,ci;
deque<int>pz;
struct poz
{
    int l,c;
};
poz v[14];
void init()
{
    v[0].l=4;v[0].c=2;
    v[1].l=1;v[1].c=1;
    v[2].l=1;v[2].c=2;
    v[3].l=1;v[3].c=3;
    v[4].l=2;v[4].c=1;
    v[5].l=2;v[5].c=2;
    v[6].l=2;v[6].c=3;
    v[7].l=3;v[7].c=1;
    v[8].l=3;v[8].c=2;
    v[9].l=3;v[9].c=3;
}
int main()
{
    f>>nr;
    do
    {
        pz.push_back(nr%10);
        nr/=10;
    }while(nr);
    init();
    li=4,ci=1;
    while(pz.size())
    {
       //s g<<li<<" "<<ci<<'\n';
        int l=li-v[pz.back()].l;
        int c=ci-v[pz.back()].c;
        if(l>0)
            g<<"S ";
        else
            if(l<0)
                g<<"J ";
        if(l!=0)
            g<<abs(l)<<" ";
        if(c>0)
            g<<"ST ";
        else
            if(c<0)
                g<<"DR ";
        if(c!=0)
            g<<abs(c)<<" ";
        g<<"A ";
        li=v[pz.back()].l;
        ci=v[pz.back()].c;
        pz.pop_back();
    }
    int l=li-4;
    int c=ci-3;
    if(l>0)
        g<<"S ";
    else
        if(l<0)
            g<<"J ";
    if(l!=0)
        g<<abs(l)<<" ";
    if(c>0)
        g<<"ST ";
    else
        if(c<0)
            g<<"DR ";
    if(c!=0)
        g<<abs(c)<<" ";
    return 0;
}
