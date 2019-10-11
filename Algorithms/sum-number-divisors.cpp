// https://www.infoarena.ro/problema/ssnd

#include<bits/stdc++.h>
#define mod 9973
using namespace std;
ifstream f("ssnd.in");
ofstream g("ssnd.out");
int t;
int pr[100002], nr;
bool prim[1000002];
void ciur()
{
    for(int i = 2; i <= 1000000; ++i)
    {
        if(prim[i])
            continue;
        for(int j = i + i; j <= 1000000; j += i)
            prim[j] = 1;
        pr[++nr] = i;
    }
}
long long modpow(long long b, long long e)
{
    long long ans = 1;
    while(e)
    {
        if(e & 1)
            ans = (ans * b) % mod;
        b = (b * b) % mod;
        e >>= 1;
    }
    return ans;
}
int main()
{
    f >> t;
    ciur();
    for(; t; --t)
    {
        long long n;
        f >> n;
        long long nrdiv = 1;
        long long sumdiv = 1;
        for(int a = 1; a <= nr && 1LL * pr[a] * pr[a] <= n; ++a)
        {
            if(n % pr[a] == 0)
            {
                long long sum = pr[a];
                sumdiv = (sumdiv * modpow(pr[a] - 1, mod - 2)) % mod;
                int nrr = 1;
                while(n % pr[a] == 0)
                {
                    sum *= pr[a], n /= pr[a], ++nrr;
                    sum %= mod;
                }
                nrdiv = (nrdiv * nrr) % mod;
                sumdiv = (sumdiv * (sum - 1)) % mod;
            }
        }
        if(n > 1)
        {
            nrdiv = (nrdiv * 2) % mod;
            sumdiv = (sumdiv * modpow(n - 1, mod - 2)) % mod;
            sumdiv = (sumdiv * (n * n - 1)) % mod;
        }
        g << nrdiv << " " << sumdiv << '\n';
    }
    return 0;
}
