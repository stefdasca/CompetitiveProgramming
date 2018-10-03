#include<bits/stdc++.h>
using namespace std;
ifstream f("banana.in");
ofstream g("banana.out");
int nr,k;
bitset<10002>R[10002];
struct ar
{
    int l,c;
};
ar v[17002];
int nrcomp[20002],comp;
void normal(int L,int C) /// Sorry
{
    ++nrcomp[comp];
    R[L][C]=0;
    if(R[L-1][C]==1)
        normal(L-1,C);
    if(R[L+1][C]==1)
        normal(L+1,C);
    if(R[L][C+1]==1)
        normal(L,C+1);
    if(R[L][C-1]==1)
        normal(L,C-1);
}
int main()
{
    f>>nr>>k;
    for(int i=1;i<=nr;++i)
    {
        f>>v[i].l>>v[i].c;
        R[v[i].l][v[i].c]=1;
    }
    for(int i=1;i<=nr;++i)
        if(R[v[i].l][v[i].c]==1)
        {
            ++comp;
            normal(v[i].l,v[i].c);
        }
    sort(nrcomp+1,nrcomp+comp+1);
    int s=0;
    while(k)
    {
        s+=nrcomp[comp];
        --comp;
        --k;
    }
    g<<s;
    return 0;
}
