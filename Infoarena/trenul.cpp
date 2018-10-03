#include<bits/stdc++.h>
using namespace std;
ifstream f("trenul.in");
ofstream g("trenul.out");
int n,m;
int max1=1,t;
struct nr
{
    int nr;
    int poz;
    int ar[5];
};
nr v[100002];
bool test(nr a, nr b)
{
    return a.nr<b.nr;
}
bool bac(nr a, nr b)
{
    return a.poz<b.poz;
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=m;++i)
    {
        f>>v[i].nr;
        v[i].poz=i;
    }
    sort(v+1,v+m+1,test);
    int ind=1;
    while(v[ind].nr==1)
        ++ind;
    for(int i=ind;i<=m;max1+=v[i].nr,++i)
        for(int j=1;j<=v[i].nr;++j)
            v[i].ar[j]=max1+j-1;
    for(int i=1;i<ind;++i)
        v[i].ar[1]=max1,++max1;
    sort(v+1,v+m+1,bac);
    for(int i=1;i<=m;g<<'\n',++i)
        for(int j=1;j<=v[i].nr;++j)
            g<<v[i].ar[j]<<" ";
    return 0;
}
