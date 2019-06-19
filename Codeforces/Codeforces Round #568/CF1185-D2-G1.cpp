#include<bits/stdc++.h>
#define mod 1000000007
#pragma GCC optimize("O3")
using namespace std;
int n, t;
int dp[(1<<15)][256][4];
struct songs
{
    int time, type;
};
songs v[20];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> t;
    for(int i = 0; i < n; ++i)
        cin >> v[i].time >> v[i].type;
    for(int i = 0; i < n; ++i)
        dp[(1<<i)][v[i].time][v[i].type] = 1;
    long long ans = 0;
    for(int i = 0; i < (1<<n); ++i)
    {
        for(int time = 0; time < 225; ++time)
            for(int j = 0; j < n; ++j)
            {
                if((i & (1<<j)))
                    continue;
                long long tba = dp[i][time][1] + dp[i][time][2] + dp[i][time][3];
                if(v[j].type == 1)
                    tba -= dp[i][time][1];
                if(v[j].type == 2)
                    tba -= dp[i][time][2];
                if(v[j].type == 3)
                    tba -= dp[i][time][3];
                tba += dp[i + (1<<j)][time + v[j].time][v[j].type];
                tba %= mod;
                dp[i + (1<<j)][time + v[j].time][v[j].type] = tba;
            }
        ans = ans + dp[i][t][1] + dp[i][t][2] + dp[i][t][3];
        ans %= mod;
    }
    cout << ans;
    return 0;
}

