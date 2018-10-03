#include<bits/stdc++.h>
using namespace std;
ifstream f("cumpanit.in");
ofstream g("cumpanit.out");
long long v[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
long long nr=1;
long long sol;
long long a,b;
int fr[15];
long long sl[10002];
void bkt(int sb, int se, int le)
{
    if(nr>b || sb>50)
        return;
    if(sb==se && a<=nr && nr<=b)
        ++sol,sl[sol]=nr;
    for(int i=le;i<=14;++i)
    {
        if(!fr[i])
        {
            nr*=v[i];
            fr[i]=1;
            bkt(sb+v[i],se+1,i);
            --fr[i];
            nr/=v[i];
        }
        else
        {
            nr*=v[i];
            fr[i]++;
            bkt(sb,se+1,i);
            --fr[i];
            nr/=v[i];
        }
    }
}
int main()
{
    f>>a>>b;
    bkt(0,0,0);
    sort(sl+1,sl+sol+1);
    for(int i=1;i<=sol;++i)
        g<<sl[i]<<'\n';
    return 0;
}
