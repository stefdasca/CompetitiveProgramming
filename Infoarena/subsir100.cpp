#include<bits/stdc++.h>
#define cancer 1000003
using namespace std;
ifstream f("subsir100.in");
ofstream g("subsir100.out");
int n,v[100002],pd[100002],poz1;
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i];
    sort(v+1,v+n+1);
    v[n+1]=2e9+1;
    poz1=n+1;
    pd[n]=1;
    for(int i=n-1;i>=1;--i)
    {
        pd[i]=pd[i+1]+1;
        if(v[i]<v[i+1])
            poz1=i+1;
        pd[i]=(pd[i]+pd[poz1])%cancer;
    }
    g<<pd[1];
}
