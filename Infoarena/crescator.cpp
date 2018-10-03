#include<bits/stdc++.h>
using namespace std;
ifstream f("crescator.in");
ofstream g("crescator.out");
long long n,v[100002];
long long s,e,lmax,sol;
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i];
    long long s=1,e=2;
    v[n+1]=v[n]-1;
    while(s<=n)
    {
        if(v[e]<v[e-1])
        {
            sol+=(e-s)*(e-s+1)/2;
            lmax=max(lmax,e-s);
            s=e;
        }
        ++e;
    }
    g<<sol<<" "<<lmax<<'\n';
}
