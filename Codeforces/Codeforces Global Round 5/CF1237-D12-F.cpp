#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 998244353

using namespace std;

typedef long long ll;


int add(int a, int b)
{
    ll x = a+b;
    if(x >= mod)
        x -= mod;
    if(x < 0)
        x += mod;
    return x;
}
ll mul(ll a, ll b)
{
    return (a*b) % mod;
}

ll pw(ll a, ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

int h, w, n, comb[4002][4002];
ll fact[4002];
void pascal()
{
    comb[0][0] = 1;
    fact[0] = 1;
    for(int i = 1; i <= 4000; ++i)
    {
        fact[i] = mul(fact[i-1], i);
        comb[i][0] = 1;
        for(int j = 1; j <= i; ++j)
            comb[i][j] = add(comb[i-1][j], comb[i-1][j-1]);
    }
}

int n2, m2, linie[4002], coloana[4002];
ll dp[4002][4002], dpc[4002][4002];
int has[4002], hasc[4002];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> h >> w >> n;
    for(int i = 1; i <= n; ++i)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        has[a] = has[c] = hasc[b] = hasc[d] = 1;
    }
    pascal();
    for(int i = 1; i <= h; ++i)
        n2 += (1 - has[i]);
    for(int i = 1; i <= w; ++i)
        m2 += (1 - hasc[i]);

    dp[0][0] = 1;
    for(int i = 1; i <= h; ++i)
        for(int j = 0; j <= w; ++j)
        {
            dp[i][j] = dp[i-1][j];
            if(j && i >= 2 && !has[i] && !has[i-1])
                dp[i][j] = add(dp[i][j], dp[i - 2][j - 1]);
        }

    dpc[0][0] = 1;
    for(int i = 1; i <= w; ++i)
        for(int j = 0; j <= w; ++j)
        {
            dpc[i][j] = dpc[i-1][j];
            if(j && i >= 2 && !hasc[i] && !hasc[i-1])
                dpc[i][j] = add(dpc[i][j], dpc[i - 2][j - 1]);
        }

    ll ans = 0;
    for(int i = 0; i * 2 <= n2; ++i)
        for(int j = 0; j * 2 <= m2; ++j)
        {
            int pos = n2 - 2 * i;
            int pos2 = m2 - 2 * j;
            ll added = 0;
            added = mul(fact[i], fact[j]);
            added = mul(added, mul(comb[pos][j], comb[pos2][i]));
            added = mul(added, mul(dp[h][i], dpc[w][j]));
            ans = add(ans, added);
        }
    cout << ans << '\n';
    return 0;
}

