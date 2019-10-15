/*
        Infoarena radare - Romanian National Olympiad, 2011
    "Given a tree with n nodes, rooted at node 1, a number p and the time we need to visit each of the n towns, find the number of ways we can 
block edges in the tree such that the sum of the visiting times of the cities we can visit is exactly p modulo 31333. Two ways differ if
there is some edge (a, b) which is blocked in the first way but not in the second way"

    The obvious O(n * p^2) dp[i][j] = number of ways to block the edges in subtree of node i such that you get sum j gets 60.

    But, we can optimize the same approach by building the DFS order array and transforming the same dp recurrence, but instead of
i, dp[i][j] will memorize the states for the ith node in the DFS order.

    From a state (i, j) we can go to the following states: (i+1, j + value of node in the position i) - we don't block the edge,
or (end of subtree of node in position i + 1, j) - we block the edge and we can block every edge in the subtree of node i..

    The time limit is tight, so constant factor optimization is necessary. If you still don't get 100, then submit with cpp-32
compiler instead of the default cpp-64 compiler.


*/
#include<bits/stdc++.h>
#define mod 31333
using namespace std;
ifstream f("radare.in");
ofstream g("radare.out");

int n, p, timp[3002], dp[3002][3502];

int st[3002], sf[3002], poz[3002], m, sts[3002], pw[3002];

vector<int>v[3002];

int mul(int a, int b)
{
    return (a*b) % mod;
}

void dfs(int dad, int nod)
{
    poz[++m] = nod;
    st[nod] = m;
    sts[nod] = 1;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        dfs(nod, vecin);
        sts[nod] += sts[vecin];
    }
    sf[nod] = m;
}
int main()
{
    f >> n >> p;
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        f >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1; i <= n; ++i)
        f >> timp[i];
    pw[0] = 1;
    for(int i = 1; i <= n; ++i)
        pw[i] = mul(pw[i-1], 2);
    dfs(0, 1);
    int sum = 0;
    dp[1][0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j <= p; ++j)
        {
            if(!dp[i][j])
                continue;
            int nod = poz[i];
            dp[sf[nod] + 1][j] = dp[sf[nod] + 1][j] + mul(pw[sts[nod] - 1], dp[i][j]);
            if(dp[sf[nod] + 1][j] >= mod)
                dp[sf[nod] + 1][j] -= mod;
            if(j + timp[nod] <= p)
            {
                dp[i+1][j + timp[nod]] = dp[i+1][j + timp[nod]] + dp[i][j];
                if(dp[i+1][j + timp[nod]] >= mod)
                    dp[i+1][j + timp[nod]] -= mod;
            }
        }
    }
    g << dp[n+1][p] << '\n';
    return 0;
}
