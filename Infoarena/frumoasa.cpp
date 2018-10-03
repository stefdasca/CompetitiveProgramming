#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
ifstream f("frumoasa.in");
ofstream g("frumoasa.out");
long long n,k;
int main()
{
    f>>n>>k;
    if(k>=26){
        g<<0;
        return 0;
    }
    long long sol=1;
    for(int i=0;i<k;++i)
        sol=(sol*(26-i))%mod;
    n-=k;
    long long sol2=1;
    long long q=26-k;
    for(;n;n>>=1)
    {
        if(n&1)
            sol2=(sol2*q)%mod;
        q=(q*q)%mod;
    }
    sol=(sol*sol2)%mod;
    g<<sol;
    return 0;
}
