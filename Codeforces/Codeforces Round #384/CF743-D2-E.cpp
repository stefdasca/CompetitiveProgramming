#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define eps 1e-9

using namespace std;

typedef long long ll;

int n, v[1002];

int dp[1002][258];
bool viz[1002][258];

vector<int> frq[10];

int poz[1002][10];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i], --v[i], frq[v[i]].pb(i);
    for(int i = 0; i <= 7; ++i)
        poz[0][i] = -1;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j <= 7; ++j)
            poz[i][j] = poz[i-1][j];
        poz[i][v[i]]++;
    }
    int ans = 0;
    for(int mn = 0; mn <= 130; ++mn)
    {
        memset(dp, 0, sizeof(dp));
        memset(viz, 0, sizeof(viz));
        viz[0][0] = 1;
        for(int j = 0; j <= n; ++j)
            for(int msk = 0; msk <= 255; ++msk)
            {
                if(msk == 255)
                    ans = max(ans, dp[j][msk]);
                if(!viz[j][msk])
                    continue;
                for(int nxt = 0; nxt <= 7; ++nxt)
                {
                    if(msk & (1<<nxt))
                        continue;
                    int lpoz = poz[j][nxt];
                    if(mn == 0)
                    {
                        dp[j][msk + (1<<nxt)] = max(dp[j][msk + (1<<nxt)], dp[j][msk] + mn);
                        viz[j][msk + (1<<nxt)] = 1;
                    }
                    else
                        if(lpoz + mn < frq[nxt].size())
                        {
                            dp[max(j, frq[nxt][lpoz + mn])][msk + (1<<nxt)] = max(dp[max(j, frq[nxt][lpoz + mn])][msk + (1<<nxt)], dp[j][msk] + mn);
                            viz[max(j, frq[nxt][lpoz + mn])][msk + (1<<nxt)] = 1;
                        }
                    if(lpoz + mn + 1 < frq[nxt].size())
                    {
                        dp[max(j, frq[nxt][lpoz + mn + 1])][msk + (1<<nxt)] = max(dp[max(j, frq[nxt][lpoz + mn + 1])][msk + (1<<nxt)], dp[j][msk] + mn + 1);
                        viz[max(j, frq[nxt][lpoz + mn + 1])][msk + (1<<nxt)] = 1;

                    }
                }
            }
    }
    cout << ans << '\n';
    return 0;
}
