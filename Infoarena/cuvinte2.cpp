#include<bits/stdc++.h>
using namespace std;
ifstream f("cuvinte2.in");
ofstream g("cuvinte2.out");
const int mod = 9967;
int n, d;
long long dp[30][1002], v[1002];
long long ans[1002], ans2[1002];
int main()
{
    f >> n >> d;
    for(int i = 0; i <= 25; ++i)
        dp[0][i % d]++;
    int pp = 0;
    for(int i = 1; (1 << i) <= n; ++i)
    {
        for(int j = 0; j < d; ++j)
            v[j] = dp[i-1][j];
        for(int j = 0; j < d; ++j)
        {
            int md = j;
            for(int k = 0; k < d; ++k)
            {
                dp[i][md] = (dp[i][md] + dp[i-1][j] * v[k]);
                md++;
                if(md == d)
                    md -= d;
            }
        }
        for(int j = 0; j < d; ++j)
            dp[i][j] %= mod;
        ++pp;
    }
    ans[0] = 1;
    for(int i = pp; i >= 0; --i)
        if(n & (1<<i))
        {
            memset(ans2, 0, sizeof(ans2));
            for(int j = 0; j < d; ++j)
            {
                int md = j;
                for(int k = 0; k < d; ++k)
                {
                    ans2[md] = (ans2[md] + dp[i][j] * ans[k]);
                    md++;
                    if(md == d)
                        md -= d;
                }
            }
            for(int j = 0; j < d; ++j)
                ans[j] = (ans2[j] % mod);
        }
    g << ans[0];
    return 0;
}
