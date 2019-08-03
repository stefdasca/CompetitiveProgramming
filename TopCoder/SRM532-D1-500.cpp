/*
        SRM532-D1-500

    Let's fix the vertex from where we are going to draw new edges. For simplicity, we are going to use vertexes in order 1, 2, 3, ..., n.

    Let's also define dp[i][j][q] = # of ways to draw a graph such that last node used was i,
the bitmask among the next K vertexes is j and we have drawn q edges. In order to do the transition from a mask to another,
we have to check if we can actually reach it and use some combinatorics formulas to deal with multi-edges

*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;


int add(int a, int b)
{
    ll x = a+b;
    if(x >= mod)
        x -= mod;
    if(x < 0)
        x += mod;
    return x;
}
ll mul(ll a, ll b)
{
    return (a*b) % mod;
}
class DengklekBuildingRoads
{
     public:
        int numWays(int N, int M, int K)
        {

            int dp[32][1200][33];
            int combi[52][52];
            K = min(N-1, K) + 1;
            memset(dp, 0, sizeof(dp));
            memset(combi, 0, sizeof(combi));
            for(int i = 0; i <= 40; ++i)
            {
                combi[i][0] = 1;
                for(int j = 1; j <= i; ++j)
                    combi[i][j] = add(combi[i-1][j], combi[i-1][j-1]);
            }
            dp[0][0][0] = 1;
            int nnr = 0;
            for(int i = 1; i < N; ++i)
            {
                if(i + K - 1 > N)
                    nnr = nnr * 2 + 1;
                for(int j = 0; j < (1<<K); ++j)
                {
                    for(int ed = 0; ed <= M; ++ed)
                    {
                        if(!dp[i-1][j][ed])
                            continue;
                        for(int p = 0; p < (1<<(K-1)); ++p)
                        {
                            if(p & nnr)
                                continue;
                            int z = ((j & (1<<(K-1))) != 0);
                            int extr = 0;
                            for(int bt = (K-2); bt >= 0; --bt)
                                if((j & (1<<bt)) != (p & (1<<bt)))
                                    ++extr;
                            if(((z & 1) != (extr & 1)) || ed + extr > M)
                                continue;
                            for(int op = ed + extr, df = 0; op <= M; op += 2, ++df)
                                dp[i][(p << 1)][op] = add(dp[i][(p << 1)][op], mul(dp[i-1][j][ed], combi[df + min(N - i, (K-1)) - 1][df]));
                        }
                    }
                }
            }
            return dp[N-1][0][M];
        }
};
