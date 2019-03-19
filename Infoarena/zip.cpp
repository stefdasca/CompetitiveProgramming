
#include<bits/stdc++.h>
using namespace std;
ifstream f("zip.in");
ofstream g("zip.out");
int n, m, k;
int cost[102][102], dp[102][102];
struct s
{
    string a;
    long long hsh[102];
};
s v[102];
int pi[102], q;
char qq[102];
int main()
{
    f >> n >> m >> k;
    for(int i = 1; i <= n; ++i)
        f >> v[i].a, v[i].a = ' ' + v[i].a;
    for(int j = 1; j <= n; ++j)
        for(int kk = 1; kk <= n; ++kk)
            cost[j][kk] = k;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= k; ++j)
            v[i].hsh[j] = (v[i].hsh[j-1] * 26 + (v[i].a[j] - 'a')) % 1000000007;
    for(int i = 1; i <= n; ++i)
    {
        for(int q = 1; q < k; ++q)
        {
            long long pp = 0;
            for(int p = k - q + 1; p <= k; ++p)
                pp = (pp * 26 + (v[i].a[p] - 'a')) % 1000000007;
            for(int z = 1; z <= n; ++z)
                if(v[z].hsh[q] == pp)
                    cost[i][z] = min(cost[i][z], k - q);
        }
    }
    for(int i = 1; i <= n; ++i)
        dp[1][i] = k;
    for(int i = 1; i < m; ++i)
        for(int j = 1; j <= n; ++j)
            for(int k = 1; k <= n; ++k)
                if(dp[i+1][k] == 0)
                    dp[i+1][k] = dp[i][j] + cost[j][k];
                else
                    dp[i+1][k] = min(dp[i+1][k], dp[i][j] + cost[j][k]);
    int mn = (1<<30);
    for(int i = 1; i <= n; ++i)
        mn = min(mn, dp[m][i]);
    g << mn;
    return 0;
}
