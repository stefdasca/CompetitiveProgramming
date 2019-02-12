/*
                Infoarena bitcost(https://www.infoarena.ro/problema/bitcost)

    // Google translate's English translation looks fine for this problem

    * We can use divide and conquer approach and precomputed prefix maximums to solve each query, for a runtime of (Q * K)

*/

#include<bits/stdc++.h>
using namespace std;
ifstream f("bitcost.in");
ofstream g("bitcost.out");
int k, q;
int cost[62], mx[62];
long long a, b;
long long solve(long long s, long long d, int lvl, long long ad)
{
    if(s >= a && s + (1LL<<(lvl + 1)) - 1 <= b)
        return ad + mx[lvl];
    if(d < a || s > b)
        return -(1<<30);
    if(lvl == -1)
        return ad;
    return max(solve(s, d - (1LL<<lvl), lvl - 1, ad), solve(s + (1LL<<lvl), d, lvl - 1, ad + cost[lvl]));
}
int main()
{
    f >> k >> q;
    for(int i = 0; i < k; ++i)
        f >> cost[i];
    for(int i = 0; i < k; ++i)
    {
        mx[i] = max(0, cost[i]);
        if(i > 0)
            mx[i] += mx[i-1];
    }
    for(int i = 1; i <= q; ++i)
    {
        f >> a >> b;
        g << solve(0, (1LL<<k) - 1, k - 1, 0) << '\n';
    }
    return 0;
}
