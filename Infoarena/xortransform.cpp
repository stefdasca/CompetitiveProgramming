/*
                    infoarena xortransform

    After bruteforce, one can observe that the period of how matrix looks like is min(2^i, 2^i >= n && 2^i >= m).
Also, we can reduce the problem to finding the xor-sum of the elements in positions such that the number of roads from
(0, 0) to (i, j) in k steps is odd, where k is the number of transformations done.

    This is equal to C(k, i) * C(k, j), where C(n, k) is n choose k. Also, if C(n, k) is odd,
then n AND k = k(this can also be observed by brute-force).

    Also, if C(n, i) and C(n, j) are odd, then C(n, i OR j) is odd as well, so we can reduce the problem to SOS DP, where
SOS[i] = xorsum of elements which are in positions included by i.

    For each bit of the period, SOS[i] = SOS[i - 2^position] ^ SOS[i], if i has the bit on position equal to 1.
*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("xortransform.in");
ofstream g("xortransform.out");
int n, m, q, sos[5000002];
int main()
{
    f >> n >> m >> q;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            int nr;
            f >> nr;
            sos[i | j] ^= nr;
        }
    }
    int mx = 1, stp = 1;
    while(mx < n || mx < m)
        mx <<= 1, ++stp;
    for(int i = 0; i < stp; ++i)
        for(int j = 0; j < mx; ++j)
            if(j & (1<<i))
                sos[j] ^= sos[j - (1<<i)];
    int prev_ans = 0;
    for(; q; --q)
    {
        int nr;
        f >> nr;
        nr ^= prev_ans;
        nr &= (mx - 1);
        prev_ans = sos[nr];
        g << prev_ans << '\n';
    }
    return 0;
}

