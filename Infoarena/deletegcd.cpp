/*
                                            https://infoarena.ro/problema/deletegcd

(Given an array of n(n <= 1e6, v[i] <= 1e6) numbers and q(q <= 1e6) queries, find for each query if we can remove at most 1 element such that gcd of the range is > 1)

    We can solve this task using 2 pointers and precomputing an array, extend,
such that extend[i] = the biggest position such that range [i, extend[i]] is a good one. We will speed up the process by using a sieve.

    Then, we can answer to queries in O(1), and the total runtime will be O(valmax log valmax + q).

*/
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
ifstream f("deletegcd.in");
ofstream g("deletegcd.out");
int n, v[1000002], q, divprim[1000008][8], sz[1000008];
int fr[1000002], frq[1000002], extend[1000002];
void ciur()
{
    for(int i = 2; i <= 1000000; ++i)
        if(!sz[i])
            for(int j = i; j <= 1000000; j += i)
                divprim[j][++sz[j]] = i;
}
int szz;
int main()
{
    f >> n >> q;
    for(int i = 1; i <= n; ++i)
        f >> v[i];
    ciur();
    string ans;
    int L = 1, R = 1;
    frq[0] = 1045043;
    while(L <= n)
    {
        while(R <= n)
        {
            for(int i = 1; i <= sz[v[R]]; ++i)
            {
                int nr = divprim[v[R]][i];
                frq[fr[nr]]--;
                ++fr[nr];
                frq[fr[nr]]++;
            }
            ++R;
            if(frq[R - L] == 0 && frq[R - L - 1] == 0)
            {
                --R;
                for(int i = 1; i <= sz[v[R]]; ++i)
                {
                    int nr = divprim[v[R]][i];
                    frq[fr[nr]]--;
                    --fr[nr];
                    frq[fr[nr]]++;
                }
                break;
            }
        }
        extend[L] = R - 1;
        for(int i = 1; i <= sz[v[L]]; ++i)
        {
            int nr = divprim[v[L]][i];
            frq[fr[nr]]--;
            --fr[nr];
            frq[fr[nr]]++;
        }
        ++L;
    }
    for(int i = 1; i <= q; ++i)
    {
        int st, dr;
        f >> st >> dr;
        if(extend[st] >= dr)
            szz = 1;
        else
            szz = 0;
        char q = '0' + (szz > 0);
        ans += q;
    }
    g << ans;
    return 0;
}
