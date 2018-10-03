#include<bits/stdc++.h>
using namespace std;
ifstream f("reactivi.in");
ofstream g("reactivi.out");
int n,sol;
struct reactivi
{
    int l,h;
};
reactivi v[8001];
bool test(reactivi a, reactivi b)
{
    if(a.l==b.l)
        return a.h>b.h;
    return a.l<b.l;
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i].l>>v[i].h;
    sort(v+1,v+n+1,test);
    sol=1;
    int poz=2;
    int l=v[1].l,h=v[1].h;
    while(poz<=n)
    {
        if(v[poz].l<=h)
            l=v[poz].l,h=min(h,v[poz].h);
        else
            ++sol,l=v[poz].l,h=v[poz].h;
        ++poz;
    }
    g<<sol<<'\n';
}
