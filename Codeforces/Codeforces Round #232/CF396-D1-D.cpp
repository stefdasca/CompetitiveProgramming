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

int n, p[1000002];
int aib[1000002];

void add(int nod)
{
    for(; nod <= n; nod += (nod & (-nod)))
        aib[nod]++;
}
int compute(int nod)
{
    int ans = 0;
    for(int i = nod; i; i -= (i & (-i)))
        ans += aib[i];
    return ans;
}

ll total[1000002], fact[1000002], ind[1000002];

ll gauss(ll x)
{
    if(x % 2 == 0)
        return mul(x/2, x+1);
    else
        return mul(x, (x+1)/2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> p[i];
    total[2] = 1;
    fact[0] = 1;
    for(int i = 1; i <= n; ++i)
        fact[i] = (fact[i-1] * i) % mod;
    for(int i = 3; i <= n; ++i)
    {
        total[i] = mul(total[i-1], i);
        total[i] = add(total[i], mul(fact[i-1], gauss(i-1)));
    }
    ind[n] = 1;
    add(p[n]);
    for(int i = n-1; i >= 1; --i)
    {
        ind[i] = mul(compute(p[i] - 1), fact[n - i]);
        ind[i] = add(ind[i], ind[i+1]);
        add(p[i]);
    }
    memset(aib, 0, sizeof(aib));
    ll sol = 0;
    for(int i = 1; i <= n; ++i)
    {
        int val = p[i] - compute(p[i]);
        sol = add(sol, mul(val - 1, total[n - i]));
        sol = add(sol, mul(gauss(val - 2), fact[n - i]));
        sol = add(sol, mul(ind[i + 1], val - 1));
        add(p[i]);
    }
    cout << sol << '\n';
    return 0;
}
