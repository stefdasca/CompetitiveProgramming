/// Because i love you <3


#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 998244353
using namespace std;
long long L, R, k;
int nrb[1028];
long long dp[19][1025][10], cati[19][1025][10];
int nrc(long long numar)
{
    int sol = 0;
    while(numar)
        ++sol, numar = numar/10;
    return sol;
}
long long recc(long long nrmax)
{
    if(nrmax == 0)
        return 0;
    int nc = nrc(nrmax);
    if(nc > 1)
        for(int i = 1; i <= 9; ++i)
            dp[1][(1<<i)][i] = i, cati[1][(1<<i)][i] = 1;
    long long sol = 0;
    for(int i = 2; i < nc; ++i)
    {
        for(int j = 0; j < (1<<10); ++j)
            for(int q = 0; q <= 9; ++q)
            {
                if(!dp[i-1][j][q])
                    continue;
                for(int z = 0; z <= 9; ++z)
                {
                    long long add = (dp[i-1][j][q] * 10 + cati[i-1][j][q] * z)%mod;
                    cati[i][(j | (1<<z))][z] = (cati[i][(j | (1<<z))][z] + cati[i-1][j][q])%mod;
                    dp[i][(j | (1<<z))][z] = (dp[i][(j | (1<<z))][z] + add)%mod;
                }
            }
    }
    for(int i = 1; i < nc; ++i)
        for(int j = 0; j < (1<<10); ++j)
        {
            if(nrb[j] > k)
                continue;
            for(int q = 0; q <= 9; ++q)
                sol = (sol + dp[i][j][q])%mod;
        }
    long long copie = nrmax;
    memset(dp, 0, sizeof(dp));
    memset(cati, 0, sizeof(cati));
    deque<int>d;
    while(nrmax)
    {
        d.push_front(nrmax%10);
        nrmax /= 10;
    }
    int bitsum = 0;
    long long nr = 0;
    for(int Rose = 0; Rose < d.size(); ++Rose)
    {
        memset(dp, 0, sizeof(dp));
        memset(cati, 0, sizeof(cati));
        for(int j = 0 + (Rose == 0); j < d[Rose]; ++j)
        {
            dp[Rose+1][(bitsum | (1<<j))][j] = (nr * 10 + j) % mod;
            cati[Rose+1][(bitsum | (1<<j))][j] = 1;
        }
        for(int i = Rose+2; i <= nc; ++i)
        {
            for(int j = 0; j < (1<<10); ++j)
                for(int q = 0; q <= 9; ++q)
                {
                    if(!dp[i-1][j][q])
                        continue;
                    for(int z = 0; z <= 9; ++z)
                    {
                        long long add = (dp[i-1][j][q] * 10 + cati[i-1][j][q] * z)%mod;
                        cati[i][(j | (1<<z))][z] = (cati[i][(j | (1<<z))][z] + cati[i-1][j][q])%mod;
                        dp[i][(j | (1<<z))][z] = (dp[i][(j | (1<<z))][z] + add)%mod;
                    }
                }
        }
        for(int j = 0; j < (1<<10); ++j)
        {
            if(nrb[j] > k)
                continue;
            for(int q = 0; q <= 9; ++q)
            {
                sol = (sol + dp[nc][j][q])%mod;
            }
        }
        bitsum |= (1<<d[Rose]);
        nr = (nr * 10 + d[Rose])%mod;
    }
    if(nrb[bitsum] <= k)
        sol = (sol + copie) % mod;
    return sol;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin>>L>>R>>k;
    for(int i = 0; i <= 1024; ++i)
        nrb[i] = __builtin_popcount(i);
    long long ans = recc(R) - recc(L-1);
    if(ans < 0)
        ans += mod;
    cout << ans << '\n';
    return 0;
}
