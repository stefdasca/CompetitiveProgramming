#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;

typedef long long ll;

ll n, v[302], ngr, pus[302], a[302];
vector<ll> groups[302];

ll comb[302][302], fct[302];

void calc()
{
    fct[0] = 1;
    for(int i = 1; i <= n; ++i)
        fct[i] = (fct[i-1] * i) % mod;
    for(int i = 0; i <= n; ++i)
    {
        comb[i][0] = 1;
        for(int j = 1; j <= i; ++j)
        {
            comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]);
            if(comb[i][j] >= mod)
                comb[i][j] -= mod;
        }
    }
}

ll dp[302][302];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    calc();
    for(int i = 1; i <= n; ++i)
    {
        if(!pus[i])
        {
            ++ngr;
            for(int j = i; j <= n; ++j)
            {
                ll pr = v[i] * v[j];
                ll x = sqrt(pr);
                if(x * x == pr)
                    pus[j] = ngr, groups[ngr].push_back(j);
            }
        }
    }
    ll ans = 1;
    for(int i = 1; i <= ngr; ++i)
    {
        ans = ans * fct[groups[i].size()];
        ans %= mod;
        a[i-1] = groups[i].size();
    }
    dp[0][0] = 1;
    ll sum = 1;
    for(int i = 0; i < ngr; sum += a[i], i++)
        for (int j = 0; j <= sum; j++)
            for (int g = 0; g <= min(a[i], sum - j); g++)
                for (int b = 0; b <= min(a[i] - g, 1LL * j); b++)
                {
                    dp[i + 1][j - b + a[i] - b - g] += (dp[i][j] * comb[j][b] % mod * comb[sum - j][g] % mod * comb[max(b + g - 1 + a[i] - g - b, 0LL)][a[i] - g - b] % mod);
                    dp[i + 1][j - b + a[i] - b - g] %= mod;
                }
    ans = (ans * dp[ngr][0]) % mod;
    cout << ans;
    return 0;
}

