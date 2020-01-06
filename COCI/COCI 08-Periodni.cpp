/*
                COCI 08-Periodni

    Let's compute the answer from bottom to top, recursively using DP.

    Let dp[l][r][x][0/1] = number of ways to complete subarray [l, r] with x gases, if we normalized the array or not.

    The recurrence has 3 different cases:

    1) the subarray is empty => the answer is either 0 or 1, depending on whether we are left with gases or not.
    2) there is one empty height => we can split the heights in two parts and compute the answer separately for the two parts.
    3) there is no empty height => we can use combinatorics to find the number of ways to add 0, 1, ..., x gases in the rectangle with
width (r - l + 1) and height min(v[l], v[l+1], ..., v[r]).

    Even though this seems to be an O(n^3) recurrence, in practice we are going to have only about O(n^2) states to deal with, which is good enough for AC.

*/
#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define dancila 3.14159265359
#define eps 1e-9

// #define fisier

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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
    long long a = rng();
    return a;
}
int n, k, v[502], fact[1000002], inv[1000002];

int C(int n, int k)
{
    return mul(fact[n], mul(inv[n-k], inv[k]));
}

map<pair<int, pair<int, int> >, int> mp[2];
int solve(int L, int R, int gaz, int additional)
{
    if(mp[additional].find({gaz, {L, R}}) != mp[additional].end())
        return mp[additional][{gaz, {L, R}}];
    if(gaz > R - L + 1)
        return 0;
    if(gaz == 0)
        return 1;
    if(L > R)
        return (gaz == 0);
    int mx = 0;
    int mn = 6969696;
    for(int i = L; i <= R; ++i)
    {
        mx = max(mx, v[i]);
        mn = min(mn, v[i]);
    }
    if(mx == 0)
    {
        mp[additional][{gaz, {L, R}}] = (gaz == 0);
        return (gaz == 0);
    }
    int ans = 0;
    if(mn == 0)
    {
        for(int i = L; i <= R; ++i)
        {
            if(v[i] == 0)
            {
                int nxt = i+1;
                while(nxt <= R && v[nxt] == 0)
                    ++nxt;
                for(int gz = 0; gz <= gaz; ++gz)
                    ans = add(ans, mul(solve(L, i-1, gz, 0), solve(nxt, R, gaz - gz, 0)));
                break;
            }
        }
    }
    else
        if(mn > 0)
        {
            for(int i = L; i <= R; ++i)
                v[i] -= mn;
            for(int gz = 0; gz <= gaz; ++gz)
            {
                if(mn >= gz)
                {
                    int ct = mul(C(R - L + 1 - (gaz - gz), gz), mul(solve(L, R, gaz - gz, 1), mul(fact[mn], inv[mn - gz])));
                    ans = add(ans, ct);
                }
            }
            for(int i = L; i <= R; ++i)
                v[i] += mn;
        }
    mp[additional][{gaz, {L, R}}] = ans;
    return ans;
}
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];

    fact[0] = inv[0] = 1;
    for(int i = 1; i <= 1000000; ++i)
        fact[i] = mul(fact[i-1], i);
    inv[1000000] = pw(fact[1000000], mod-2);
    for(int i = 999999; i >= 1; --i)
        inv[i] = mul(inv[i+1], (i+1));

    cout << solve(1, n, k, 0) << '\n';
    return 0;
}
