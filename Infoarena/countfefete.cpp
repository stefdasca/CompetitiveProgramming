/*
                Infoarena countfefete(https://www.infoarena.ro/problema/countfefete)
                
It is obvious that we will solve the problem separately for each bit. We will fix the minimum value that will appear in a certain subtree
and using disjoint set union we will find for each node with minimal value the numbers of subsets which have that fixed value as minimal
which were also not computed from before and we will keep those answers for future computations. Despite the fact that this approach has
O(N log valMAX) running time, it is not good enough because iterating through edges in a vector is very slow. That's why I used another 
optimization, I ran the algorithm just once, but I was computing the answers for all bits at once, in a certain state. Even though this
algorithm has the same complexity as the previous one, it will be much faster because we won't iterate through std::vector lists

*/

#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
ifstream f("countfefete.in");
ofstream g("countfefete.out");
int n, val[200002];
int szc[200002];
long long ans = 0;
vector<int>v[200002];
long long doi[200002];
long long fact[200002], inv[200002];
long long pw(long long b, long long e)
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
int nr[200002];
bool cmp(int a, int b)
{
    return val[a] < val[b];
}
long long zeroes[200002][30], ones[200002][30];
int tt[200002], rg[200002];
int Find(int a)
{
    if(tt[a] == a)
        return a;
    return tt[a] = Find(tt[a]);
}
void Union(int a, int b)
{
    if(rg[a] > rg[b])
    {
        tt[b] = a, rg[a] += rg[b];
        for(int i = 29; i >= 0; --i)
            zeroes[a][i] += zeroes[b][i], ones[a][i] += ones[b][i];
    }
    else
    {
        tt[a] = b, rg[b] += rg[a];
        for(int i = 29; i >= 0; --i)
            zeroes[b][i] += zeroes[a][i], ones[b][i] += ones[a][i];
    }
}
bool viz[200002];
long long sumzeroes[32], sumones[32], dropodd[32], dropeven[32];
int main()
{
    f >> n;
    fact[0] = 1;
    inv[0] = 1;
    for(int i = 1; i <= n; ++i)
        fact[i] = (fact[i-1] * i) % mod, inv[i] = pw(fact[i], mod - 2);
    doi[0] = 1;
    for(int i = 1; i <= n; ++i)
        doi[i] = (doi[i-1] * 2) % mod;
    for(int i = 1; i <= n; ++i)
        f >> val[i];
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        f >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1; i <= n; ++i)
        nr[i] = i;
    sort(nr + 1, nr + n + 1, cmp);
    for(int j = 1; j <= n; ++j)
    {
        tt[j] = j, rg[j] = 1;
        viz[j] = 0;
        for(int i = 29; i >= 0; --i)
            if((val[j] & (1<<i)))
                ones[j][i]++;
            else
                zeroes[j][i]++;
    }
    for(int x = n; x >= 1; --x)
    {
        for(int i = 29; i >= 0; --i)
        {
             sumzeroes[i] = zeroes[nr[x]][i];
             sumones[i] = ones[nr[x]][i];
             dropodd[i] = 0;
             dropeven[i] = 0;
        }
        viz[nr[x]] = 1;
        for(int j = 0; j < v[nr[x]].size(); ++j)
        {
            int vecin = v[nr[x]][j];
            if(!viz[vecin])
                continue;
            for(int i = 29; i >= 0; --i)
            {
                sumzeroes[i] += zeroes[Find(vecin)][i];
                sumones[i] += ones[Find(vecin)][i];
                if(!ones[Find(vecin)][i])
                {
                    dropeven[i] += doi[zeroes[Find(vecin)][i]] - 1;
                    while(dropeven[i] >= mod)
                        dropeven[i] -= mod;
                }
                else
                {
                    dropodd[i] += doi[ones[Find(vecin)][i] - 1] * doi[zeroes[Find(vecin)][i]];
                    dropodd[i] %= mod;
                    dropeven[i] += doi[ones[Find(vecin)][i] - 1] * doi[zeroes[Find(vecin)][i]] - 1;
                    dropeven[i] %= mod;
                }
            }
            if(Find(vecin) != Find(nr[x]))
                Union(Find(vecin), Find(nr[x]));
        }
        for(int i = 29; i >= 0; --i)
        {
            int z = ((val[nr[x]] & (1<<i)) > 0);
            long long evencount = 0;
            long long oddcount = 0;
            if(!sumones[i])
            {
                evencount += doi[sumzeroes[i]] - 1;
                while(evencount >= mod)
                    evencount -= mod;
            }
            else
            {
                oddcount += doi[sumones[i] - 1] * doi[sumzeroes[i]];
                oddcount %= mod;
                evencount += doi[sumones[i] - 1] * doi[sumzeroes[i]] - 1;
                evencount %= mod;
            }
            evencount = (evencount - dropeven[i] + mod);
            oddcount = (oddcount - dropodd[i] + mod);
            if(z)
            {
                ans += 1LL * (1<<i) * evencount;
                ans %= mod;
            }
            else
            {
                ans += 1LL * (1<<i) * oddcount;
                ans %= mod;
            }
        }
    }
    g << ans;
    return 0;
}
