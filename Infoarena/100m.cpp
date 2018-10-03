/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
#define mod 666013
using namespace std;
ifstream f("100m.in");
ofstream g("100m.out");
int n;
long long v[5002],comb[5002][3];
int main()
{
    f>>n;
    v[0]=v[1]=1;
    comb[0][0]=comb[0][1]=comb[1][0]=comb[1][1]=1;
    int ind=0;
    for(int i=2;i<=n;++i)
    {
        ind=1-ind;
        comb[0][ind]=comb[i][ind]=1;
        for(int j=1;j<=i/2;++j)
            comb[j][ind]=comb[i-j][ind]=(comb[j][1-ind]+comb[j-1][1-ind])%mod;
        for(int j=1;j<=i;++j)
            v[i]=(v[i]+(comb[j][ind]*v[i-j]))%mod;
    }
    g<<v[n];
    return 0;
}
