#include<bits/stdc++.h>
#define INF 2000000000
#define ll long long
using namespace std;
ifstream f("zero2.in");
ofstream g("zero2.out");
ll sol(ll n, ll p)
{
    ll k,rez=0;
    for(ll i=p;i<=n;i*=p)
    {
        k=n/i;
        rez+=(ll)i*k*(k-1)/2;
        rez+=(ll)(n-k*i+1)*k;
    }
    return rez;
}
int main()
{
    for(int q=0;q<10;q++)
    {
        ll n,b;
        f>>n>>b;
        ll rez=INF;
        rez=rez*rez;
        for(ll p=2;p*p<=b;p++)
        {
            if(b%p)
                continue;
            int e;
            for(e=0;!(b%p);b/=p)
                e++;
            rez=min(rez,sol(n,p)/e);
        }
        if(b>1)
            rez=min(rez,sol(n,b));
        g<<rez<<'\n';
    }
    return 0;
}
