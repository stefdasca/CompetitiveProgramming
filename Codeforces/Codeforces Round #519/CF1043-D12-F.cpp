#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;

typedef long long ll;

ll n, frq[300002], fct[300002], inv[300002];
ll lgput(ll a, ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b&1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
void ciur()
{
    for(int i = 1; i <= 300000; ++i)
        for(int j = i+i; j <= 300000; j += i)
            frq[i] += frq[j];
}
ll dp[8][300002];
ll comb(int n, int k)
{
    ll ans = (fct[n] * inv[k]) % mod;
    return ((ans * inv[n-k]) % mod);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int dc = 0;
    for(int i = 1; i <= n; ++i)
    {
        int nr;
        cin >> nr;
        if(i == 1)
            dc = nr;
        else
            dc = __gcd(dc, nr);
        frq[nr]++;
    }
    if(dc != 1)
    {
        cout << -1;
        return 0;
    }
    ciur();
    fct[0] = inv[0] = 1;
    for(int i = 1; i <= 300000; ++i)
    {
        fct[i] = (fct[i-1] * i) % mod;
        inv[i] = lgput(fct[i], mod-2);
    }
    for(int i = 1; i <= 7; ++i)
    {
        for(int j = 300000; j >= 1; --j)
        {
            dp[i][j] = comb(frq[j], i);
            for(int k = j + j; k <= 300000; k += j)
            {
                dp[i][j] -= dp[i][k];
                if(dp[i][j] < 0)
                    dp[i][j] += mod;
            }
        }
        if(dp[i][1])
        {
            cout << i;
            return 0;
        }
    }
    return 0;
}

