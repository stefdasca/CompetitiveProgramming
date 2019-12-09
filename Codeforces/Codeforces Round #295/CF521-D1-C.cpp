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
int n, k;
string s;
ll ans = 0;

ll inv[100002], fact[100002], sc[100002];

ll C(ll n, ll k)
{
    return mul(fact[n], mul(inv[k], inv[n-k]));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    cin >> s;
    if(k == 0)
    {
        ll ans = 0;
        for(int i = 0; i < n; ++i)
        {
            ans = mul(ans, 10);
            ans = add(ans, s[i] - '0');
        }
        cout << ans;
        return 0;
    }
    fact[0] = inv[0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        fact[i] = mul(fact[i-1], i);
        inv[i] = pw(fact[i], mod - 2);
    }
    int mx = 0;
    for(int i = 0; n - i - 2 >= k - 1; ++i)
    {
        sc[i] = mul(pw(10, i), C(n - i - 2, k - 1));
        if(i >= 1)
            sc[i] = add(sc[i], sc[i-1]);
        mx = i;
    }
    for(int i = 0; i < s.size(); ++i)
    {
        int df = s.size() - i - 1;
      //  cout << i << " " << k << " " << mx << '\n';
        if(i < k)
            ans = add(ans, mul((int)(s[i] - '0'), sc[mx]));
        else
        {
            if(df > 0)
                ans = add(ans, mul((int)(s[i] - '0'), sc[df - 1]));
            ans = add(ans, mul(pw(10, s.size() - i - 1), mul((int)(s[i] - '0'), C(i, k))));
        }
     //   cout << ans << '\n';
    }
    cout << ans;
    return 0;
}
