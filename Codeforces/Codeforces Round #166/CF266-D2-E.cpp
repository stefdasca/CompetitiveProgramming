#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

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

int n, m, x, L, R;
ll pre[100005][6];
ll sum[400005][6];
int laz[400005];

inline void pushdown(int nod, int l,int r)
{
    if (laz[nod] != -1)
    {
        int m = (l + r) >> 1;
        for(int i = 0; i <= 5; ++i)
        {
            sum[nod << 1][i] = ((pre[m][i] - pre[l - 1][i]) % mod + mod) % mod * laz[nod] % mod;
            sum[nod << 1 | 1][i] = ((pre[r][i] - pre[m][i]) % mod + mod) % mod * laz[nod] % mod;
        }
        laz[nod << 1] = laz[nod << 1 | 1] = laz[nod];
        laz[nod] = -1;
    }
}
void build(int nod, int l, int r)
{
    laz[nod] = -1;
    if (l == r)
    {
        cin >> x;
        sum[nod][0] = x;
        for(int i = 1; i <= 5; ++i)
            sum[nod][i] = sum[nod][i - 1] * l % mod;
        return;
    }
    int m = (l + r) / 2;
    build(nod << 1, l, m);
    build(nod << 1|1, m+1, r);
    for(int i = 0; i <= 5; ++i)
        sum[nod][i] = add(sum[nod << 1][i], sum[nod << 1 | 1][i]);
}
void setv(int nod, int l, int r)
{
    if (L <= l && r <= R)
    {
        laz[nod] = x;
        for(int i = 0; i <= 5; ++i)
            sum[nod][i] = ((pre[r][i] - pre[l - 1][i]) % mod + mod) % mod * x % mod;
        return;
    }
    pushdown(nod, l, r);
    int m = (l + r) / 2;
    if (L <= m)
        setv(nod << 1, l, m);
    if (R > m)
        setv(nod << 1 | 1, m + 1, r);
    for(int i = 0; i <= 5; ++i)
        sum[nod][i] = add(sum[nod << 1][i], sum[nod << 1 | 1][i]);
}

ll query(int d, int nod, int l, int r)
{
    if (L <= l && r <= R)
        return sum[nod][d];
    pushdown(nod, l, r);
    int m = (l + r) >> 1;
    ll ans = 0;
    if (L <= m)
        ans += query(d, nod << 1, l, m);
    if (R > m)
        ans += query(d, nod << 1 | 1, m + 1, r);
    ans %= mod;
    for(int i = 0; i <= 5; ++i)
        sum[nod][i] = add(sum[nod << 1][i], sum[nod << 1 | 1][i]);
    return ans;
}
ll solve()
{
    ll ans;
    ll u = L - 1;
    if (x == 0)
        ans = query(0, 1, 1, n);
    if (x == 1)
    {
        ans = query(1, 1, 1, n) - u * query(0, 1, 1, n) % mod;
        ans = (ans % mod + mod) % mod;
        return ans;
    }
    if (x == 2)
    {
        ans = query(2, 1, 1, n) - 2ll * u * query(1, 1, 1, n) % mod;
        ans = (ans % mod + mod) % mod;
        ans = ans + (ll)u * u % mod * query(0, 1, 1, n) % mod;
        ans = (ans % mod + mod) % mod;
    }
    if (x == 3)
    {
        ans = query(3, 1, 1, n) - 3ll * u * query(2, 1, 1, n) % mod;
        ans = (ans % mod + mod) % mod;
        ans = ans + 3ll * u * u % mod * query(1, 1, 1, n) % mod;
        ans = (ans % mod + mod) % mod;
        ans = ans - u * u % mod * u % mod * query(0, 1, 1, n) % mod;
        ans = (ans % mod + mod) % mod;
    }
    if (x == 4)
    {
        ans = query(4, 1, 1, n) - 4ll * u * query(3, 1, 1, n) % mod;
        ans = (ans % mod + mod) % mod;
        ans = ans + 6ll * u * u % mod * query(2, 1, 1, n) % mod;
        ans = (ans % mod + mod) % mod;
        ans = ans - 4ll * u * u % mod * u % mod * query(1, 1, 1, n) % mod;
        ans = (ans % mod + mod) % mod;
        ans = ans + u * u % mod * u % mod * u % mod * query(0, 1, 1, n) % mod;
        ans = (ans % mod + mod) % mod;
    }
    if (x == 5)
    {
        ans = query(5, 1, 1, n) - 5ll * u * query(4, 1, 1, n) % mod;
        ans = (ans % mod + mod) % mod;
        ans = ans + 10ll * u * u % mod * query(3, 1, 1, n) % mod;
        ans = (ans % mod + mod) % mod;
        ans = ans - 10ll * u * u % mod * u % mod * query(2, 1, 1, n) % mod;
        ans = (ans % mod + mod) % mod;
        ans = ans + 5ll * u * u % mod * u % mod * u % mod * query(1, 1, 1, n) % mod;
        ans = (ans % mod + mod) % mod;
        ans = ans - u * u % mod * u % mod * u % mod * u % mod * query(0, 1, 1, n) % mod;
        ans = (ans % mod + mod) % mod;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        ll t = 1;
        for(int j = 0; j <= 5; ++j)
        {
            pre[i][j] = add(pre[i - 1][j], t);
            t = mul(t, i);
        }
    }
    build(1, 1, n);
    char s;
    for(int i = 1; i <= m; ++i)
    {
        cin >> s >> L >> R >> x;
        if (s == '=')
            setv(1, 1, n);
        else
            cout << solve() << '\n';

    }
    return 0;
}
