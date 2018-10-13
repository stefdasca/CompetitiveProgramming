/// leader of NumaNumaTei

#include<bits/stdc++.h>
using namespace std;
ifstream f("jap2.in");
ofstream g("jap2.out");
int p, q;
long long n, k;
long long st[200002], invst[200002];
long long ap(long long x)
{
    long long sol = 0;
    long long pp = p;
    while(x)
    {
        sol += x/pp;
        x /= pp;
    }
    return sol;
}
long long pw(long long b, long long e)
{
    e %= (p-1);
    long long sol = 1;
    while(e)
    {
        if(e&1)
            sol = (sol * b) % p;
        b = (b*b) % p;
        e >>= 1;
    }
    return sol;
}
int main()
{
    f >> p >> q;
    invst[0] = 1;
    st[0] = 1;
    for(int i = 1; i < p; ++i)
        st[i] = (st[i-1] * i) % p, invst[i] = pw(st[i], p-2);
    for(int i = 1; i <= q; ++i)
    {
        f >> n >> k;
        if(ap(n) > ap(n-k) + ap(k))
        {
            g << 0 << '\n';
            continue;
        }
        else
        {
            long long xx = n;
            long long sol = 1;
            while(xx)
            {
                sol = (sol * pw(st[p-1], xx/p)) % p;
                sol = (sol * st[xx%p]) % p;
                xx /= p;
            }
            xx = k;
            while(xx)
            {
                sol = (sol * pw(invst[p-1], xx/p)) % p;
                sol = (sol * invst[xx%p]) % p;
                xx /= p;
            }
            xx = n-k;
            while(xx)
            {
                sol = (sol * pw(invst[p-1], xx/p)) % p;
                sol = (sol * invst[xx%p]) % p;
                xx /= p;
            }
            g << sol << '\n';
        }
    }
    return 0;
}
