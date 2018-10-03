// this is eggball, not football
// true football is played with round ball
#include<bits/stdc++.h>
using namespace std;
ifstream f("football.in");
ofstream g("football.out");
int t,n;
long long pd[26];
void cstd()
{
    pd[1]=pd[2]=pd[3]=pd[6]=1;
    for(int i=2;i<=25;++i)
    {
        if(i>1)
            pd[i]+=pd[i-1];
        if(i>2)
            pd[i]+=pd[i-2];
        if(i>3)
            pd[i]+=pd[i-3];
        if(i>6)
            pd[i]+=pd[i-6];
    }
}
int main()
{
    f>>t;
    cstd();
    for(int i=1;i<=t;++i)
    {
        f>>n;
        g<<"Case "<<i<<": "<<pd[n]<<'\n';
    }
    return 0;
}
