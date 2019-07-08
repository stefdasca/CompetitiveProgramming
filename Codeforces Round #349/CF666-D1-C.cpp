#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

typedef long long ll;

int t;
string s;
ll p25[100002], fct[100002], inv[100002], mod = 1000000007, c;
map<int, int> mp;
vector<int>ans[1002];
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
ll moduri(ll n, ll k)
{
    if(n < k)
        return 0;
    ll ans = fct[n] * inv[k];
    ans %= mod;
    ans = ans * inv[n-k];
    ans %= mod;
    ans = ans * p25[n-k];
    ans %= mod;
    return ans;
}
void solve()
{
    if(mp[s.size()])
        return;
    ++c;
    mp[s.size()] = c;
    ll total = 0;
    ans[c].push_back(0);
    for (int len = 1; len <= 100000; len++)
	{
		total = (total * 26) % mod;
		total += moduri(len - 1, s.size() - 1);
		total %= mod;
		ans[c].push_back(total);
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    p25[0] = fct[0] = inv[0] = 1;
    for(int i = 1; i <= 100000; ++i)
    {
        fct[i] = (fct[i-1] * i) % mod;
        inv[i] = lgput(fct[i], mod-2);
        p25[i] = (p25[i-1] * 25) % mod;
    }
    cin >> t;
    cin >> s;
    solve();
    for(; t; --t)
    {
        int tip;
        cin >> tip;
        if(tip == 1)
        {
            cin >> s;
            solve();
        }
        else
        {
            int nr;
            cin >> nr;
            int plc = mp[s.size()];
            cout << ans[plc][nr] << '\n';
        }
    }
    return 0;
}

