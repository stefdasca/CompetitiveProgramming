#include<bits/stdc++.h>
using namespace std;
ifstream f("invsort.in");
ofstream g("invsort.out");
int n;
int v[32002];
bool good[32002];
void Merge(int l, int r)
{
    if(l>=r)
        return;
    int mid=(l+r)/2;
    Merge(l,mid);
    Merge(mid+1,r);
    int i=l,j=r;
    while(good[i]==0 && i<=r)
        ++i;
    while(good[j]==1 && j>=l)
        --j;
    if(i<j)
    {
        g<<i<<" "<<j<<'\n';
        reverse(v+i,v+j+1);
        reverse(good+i,good+j+1);
    }
}
void solve(int l, int r, int b)
{
    if(b==-1)
        return;
    int nr=0;
    for(int i=l;i<=r;++i)
        if(v[i]&(1<<b))
            good[i]=1;
        else
            good[i]=0,++nr;
    Merge(l,r);
    if(nr)
        solve(l,l+nr-1,b-1);
    if(nr!=r-l+1)
        solve(l+nr,r,b-1);
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i];
    solve(1,n,14);
    return 0;
}
