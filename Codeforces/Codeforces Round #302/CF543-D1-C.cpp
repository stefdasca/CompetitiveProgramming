#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
char a[22][22];
int n, m, cc[22][22], dp[(1<<20)], bt[22][22], cost[22][22];
int mx[27], lft[27], frq[27];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> cc[i][j];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
        {
            int mxx = 0;
            int ss = 0;
            for(int k = 0; k < n; ++k)
                if(a[k][j] == a[i][j])
                    mxx = max(mxx, cc[k][j]), ss += cc[k][j], bt[i][j] += (1<<k);
            cost[i][j] = ss - mxx;
        }
    for(int i = 1; i < (1<<n); ++i)
    {
        int low = -1;
        for(int j = 0; j < n; ++j)
            if(i & (1<<j))
            {
                low = j;
                break;
            }
        dp[i] = 100000000;
        for(int j = 0; j < m; ++j)
        {
            dp[i] = min(dp[i], dp[i ^ (1<<low)] + cc[low][j]);
            dp[i] = min(dp[i], dp[i & (i ^ bt[low][j])] + cost[low][j]);
        }
    }
    cout << dp[(1<<n) - 1] << '\n';
    return 0;
}

