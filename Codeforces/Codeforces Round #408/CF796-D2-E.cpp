#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

int n, P, k;
bool ok[1002], ok2[1002];
bool fct(int poz, int a, int b)
{
    bool ta = 0;
    if(ok[poz] && a)
        ta |= 1;
    if(ok2[poz] && b)
        ta |= 1;
    return ta;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> P >> k;
    P = min(P, 2 * (n/k + (n%k > 0)));
    int a;
    cin >> a;
    for(int i = 1; i <= a; ++i)
    {
        int z;
        cin >> z;
        ok[z] = 1;
    }
    cin >> a;
    for(int i = 1; i <= a; ++i)
    {
        int z;
        cin >> z;
        ok2[z] = 1;
    }
    int dp[2][P+3][k+3][k+3];
    bool viz[2][P+3][k+3][k+3];
    memset(dp, 0, sizeof(dp));
    memset(viz, 0, sizeof(viz));
    int ans = 0;
    viz[0][0][0][0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j <= P; ++j)
        {
            for(int p = 0; p < k; ++p)
            {
                for(int r = 0; r < k; ++r)
                {
                    if(!viz[0][j][p][r])
                        continue;
                    dp[1][j][max(p-1, 0)][max(r-1, 0)] = max(dp[1][j][max(p-1, 0)][max(r-1, 0)], dp[0][j][p][r] + fct(i, p, r));
                    ans = max(ans, dp[1][j][max(p-1, 0)][max(r-1, 0)]);
                    viz[1][j][max(p-1, 0)][max(r-1, 0)] = 1;
                    if(j+1 <= P)
                    {
                        dp[1][j+1][k-1][max(r-1, 0)] = max(dp[1][j+1][k-1][max(r-1, 0)], dp[0][j][p][r] + fct(i, k, r));
                        viz[1][j+1][k-1][max(r-1, 0)] = 1;
                        ans = max(ans, dp[1][j+1][k-1][max(r-1, 0)]);
                        dp[1][j+1][max(p-1, 0)][k-1] = max(dp[1][j+1][max(p-1, 0)][k-1], dp[0][j][p][r] + fct(i, p, k));
                        viz[1][j+1][max(p-1, 0)][k-1] = 1;
                        ans = max(ans, dp[1][j+1][max(p-1, 0)][k-1]);
                        if(j+2 <= P)
                        {
                            dp[1][j+2][k-1][k-1] = max(dp[1][j+2][k-1][k-1], dp[0][j][p][r] + fct(i, k, k));
                            viz[1][j+2][k-1][k-1] = 1;
                            ans = max(ans, dp[1][j+2][k-1][k-1]);
                        }
                    }
                }
            }
        }
        memcpy(dp[0], dp[1], sizeof(dp[1]));
        memset(dp[1], 0, sizeof(dp[1]));
        memcpy(viz[0], viz[1], sizeof(viz[1]));
        memset(viz[1], 0, sizeof(viz[1]));
    }
    cout << ans;
    return 0;
}
