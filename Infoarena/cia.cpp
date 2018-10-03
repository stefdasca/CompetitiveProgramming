#include<bits/stdc++.h>
using namespace std;
ifstream f("cia.in");
ofstream g("cia.out");
int n, t, k, mod, a[70002], b[70002];
int prefix[10000002], sufix[10000002], st[10000002];
int sol, pr;
int val(int pos)
{
    int q = a[pos%t] ^ b[pos/t];
    q %= mod;
    return q;
}
int main()
{
    f >> n >> t >> k >> mod;
    for(int i = 0; i < t; ++i)
        f >> a[i];
    for(int i = 0; i < t; ++i)
        f >> b[i];
    for(int i = 0; i < n; i += k)
    {
        for(int j = i; j < min(i+k, n); ++j)
            st[j] = i;
        for(int j = i; j < min(i+k, n); ++j)
            if(j == i)
                prefix[j] = val(j);
            else
            {
                long long pp = (1LL * prefix[j-1] * val(j)) % mod;
                prefix[j] = pp;
            }
        for(int j = min(n-1, i+k-1); j >= i; --j)
            if(j == min(n-1, i+k-1))
                sufix[j] = val(j);
            else
            {
                long long pp = (1LL * sufix[j+1] * val(j)) % mod;
                sufix[j] = pp;
            }
    }
    for(int i = 0; i <= n-k; ++i)
    {
        int ss = i;
        int dd = i+k-1;
        if(st[ss] == st[dd])
            sol ^= prefix[dd];
        else
        {
            long long prod = 1LL * sufix[ss] * prefix[dd];
            prod %= mod;
            sol ^= prod;
        }
    }
    g << sol;
    return 0;
}
