/*
            Infoarena shgraf

    "Find out the number of simple undirected graphs having N vertices with the property that in each
connected component the number of vertices is equal to the number of edges. In addition, every cycle's length must be at least K."

    We are going to use several formulas in order to find the required answer.

    // comb[i][j] = i choose j
    // prufer[i] = number of labeled trees with i vertexes = i^(i-2)
    // dp[i][j] = number of ways to choose the j nodes which are not in the cycle if the length of the cycle is i,
this can be computed based on the two previous precalculations
    // cic[i] = number of cycles with i nodes
    // cgraf[i] = number of connected graphs with i nodes which respect the given requirement
    // graf[i] = number of graphs with i nodes which respect the given requirement

    After we compute the answers in all the arrays mentioned above, we will find the answer in O(n^3) - graf[n]

*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("shgraf.in");
ofstream g("shgraf.out");

int n, k;
int dp[302][302], comb[302][302], prufer[302], cic[302], cgraf[302], graf[302];

const int mod = 30011;

int pw(int a, int b)
{
    int ans = 1;
    while(b)
    {
        if(b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
int main()
{
    f >> n >> k;

    prufer[0] = prufer[1] = prufer[2] = 1;
    for(int i = 3; i <= n+1; ++i)
        prufer[i] = pw(i, i-2);

    for(int i = 0; i <= n; ++i)
    {
        comb[i][0] = 1;
        for(int j = 1; j <= i; ++j)
        {
            comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
            if(comb[i][j] >= mod)
                comb[i][j] -= mod;
        }
    }

    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j <= n; ++j)
            for(int x = 0; j + x <= n; ++x)
                dp[i][j + x] = (dp[i][j + x] + (((dp[i-1][j] * prufer[x+1]) % mod) * comb[j+x][x])) % mod;

    cic[3] = 1;
    for(int i = 4; i <= n; ++i)
        cic[i] = (cic[i-1] * (i - 1)) % mod;

    cgraf[0] = 1;
    for(int i = k; i <= n; ++i)
        for(int j = 0; i+j <= n; ++j)
            cgraf[i+j] = (cgraf[i+j] + ((dp[i][j] * cic[i]) % mod) * comb[i+j][i]) % mod;

    graf[0] = 1;
    for(int i = 3; i <= n; ++i)
        for(int j = 3; j <= i; ++j)
            graf[i] = (graf[i] + ((graf[i - j] * cgraf[j]) % mod) * comb[i-1][j-1]) % mod;

    g << graf[n] << '\n';
    return 0;
}
