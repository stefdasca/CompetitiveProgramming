#include<bits/stdc++.h>
using namespace std;
int n, v[22], b3[22], b2[22];
long long dp[(1<<22)][22], sol;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i];
        int a = v[i];
        b2[i] = __builtin_popcount(v[i]);
        while(a)
        {
            if(a % 3 == 1)
                ++b3[i];
            a /= 3;
        }
    }
    for(int i = 0; i < n; ++i)
        dp[(1<<i)][i] = 1;
    for(int i = 1; i < (1<<n); ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(!dp[i][j])
                continue;
            for(int k = 0; k < n; ++k)
            {
                if((i & (1<<k)))
                    continue;
                if(b2[j] == b2[k] || b3[j] == b3[k])
                    dp[i + (1<<k)][k] += dp[i][j];
            }
        }
    }
    for(int i = 0; i < n; ++i)
        sol += dp[(1<<n) - 1][i];
    cout << sol;
    return 0;
}
