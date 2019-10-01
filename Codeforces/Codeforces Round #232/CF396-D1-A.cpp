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

ll fact[100002], inv[100002];
map<int, int> primes;
ll combi(ll n, ll k)
{
    ll ans = (fact[n] * inv[k]) % mod;
    ans = (ans * inv[n - k]) % mod;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    fact[0] = inv[0] =1;
    for(int i = 1; i <= 100000; ++i)
    {
        fact[i] = (fact[i - 1] * i) % mod;
        inv[i] = pw(fact[i], mod - 2);
    }
    for(int i = 1; i <= n; ++i)
    {
        int nr;
        cin >> nr;
        for(int j = 2; j * j <= nr; ++j)
            while(nr % j == 0)
            {
                primes[j]++;
                nr /= j;
            }
        if(nr > 1)
            primes[nr]++;
    }
    map<int, int> ::iterator it;
    ll ans = 1;
    for(it = primes.begin(); it != primes.end(); ++it)
    {
        ll countter = it -> second;
        ans = (ans * combi(countter + n - 1, countter)) % mod;
    }
    cout << ans;
    return 0;
}
