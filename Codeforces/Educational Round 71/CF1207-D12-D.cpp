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

int n;

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
pair<int, int> v[300002];
ll fact[300002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> v[i].fi >> v[i].se;
    sort(v + 1, v + n + 1);
    fact[0] = 1;
    for(int i = 1; i <= n; ++i)
        fact[i] = mul(fact[i - 1], i);
    ll ans = fact[n];
	sort(v + 1, v + n + 1);
	int k = 1LL, cnt = 1;
	for(int i = 2; i <= n; i++)
        if(v[i].fi == v[i - 1].fi && v[i].se == v[i - 1].se)
            cnt++;
        else
        {
            k = mul(k, fact[cnt]);
            cnt = 1;
        }
    k = mul(k, fact[cnt]);
    for(int i = 2; i <= n; i++)
        if(v[i].fi < v[i - 1].fi || v[i].se < v[i - 1].se)
        {
            k = 0;
            break;
        }

    int p1 = 1, p2 = 1, cnt1 = 1, cnt2 = 1;
    for(int i = 2; i <= n; i++)
        if(v[i].fi == v[i - 1].fi)
            cnt1++;
        else
        {
            p1 = mul(p1, fact[cnt1]);
            cnt1 = 1;
        }

    p1 = mul(p1, fact[cnt1]);

	for(int i = 1; i <= n; i++)
        swap(v[i].fi, v[i].se);

	sort(v + 1, v + n + 1);

	for(int i = 2; i <= n; i++)
        if(v[i].fi == v[i - 1].fi)
            cnt2++;
        else
        {
            p2 = mul(p2, fact[cnt2]);
            cnt2 = 1;
        }
    p2 = mul(p2, fact[cnt2]);
	p1 = add(p1, p2);
	p1 = add(p1, -k);
	ans -= p1;
	if(ans < 0)
		ans += mod;
	ans %= mod;
	cout << ans << '\n';
    return 0;
}

