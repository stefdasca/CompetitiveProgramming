#include<bits/stdc++.h>
using namespace std;
ifstream f("euclid4.in");
ofstream g("euclid4.out");
char c1[202];
int cmp[202],a[202],b[202],c[202],sol=1;
int La, Lb, Lc;
int l;
void init()
{
    f>>c1;
    l=strlen(c1);
    for(int i=l-1;i>=0;--i)
        cmp[l-i]=c1[i]-'0';
    a[1]=1;
    b[1]=1;
    La=1;
    Lb=1;
}
int cp()
{
    if(l>Lc)
        return -1;
    for(int i=Lc;i>=1;--i)
        if(cmp[i]>c[i])
            return -1;
        else
            if(c[i]>cmp[i])
                return 1;
    return 0;
}
void tr()
{
    for(int i=Lb;i>=1;--i)
        a[i]=b[i];
    La=Lb;
     for(int i=Lc;i>=1;--i)
        b[i]=c[i];
    Lb=Lc;
}
void sum()
{
    for(int i=1;i<=Lb;++i)
            c[i]=a[i]+b[i];
    Lc=Lb;
    for(int i=1;i<=Lc;++i)
        if(c[i]>=10){
            ++c[i+1],c[i]-=10;
            if(i==Lc)
                ++Lc;
        }
}
void solve()
{
    while(1)
    {
        sum();
        if(cp()!=1)
            ++sol;
        else
            break;
        tr();
    }
}
void afis()
{
    g<<sol<<'\n';
    for(int i=La;i>=1;--i)
        g<<a[i];
    g<<'\n';
    for(int i=Lb;i>=1;--i)
        g<<b[i];
}
int main()
{
    init();
    solve();
    afis();
    return 0;
}
