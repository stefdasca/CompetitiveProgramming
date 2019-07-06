#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

typedef long long ll;

ll n, p, k;
map<ll, int>mp;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> p >> k;
    ll ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        ll nr;
        cin >> nr;
        ll p4 = (nr * nr) % p;
        p4 = (p4 * p4) % p;
        ll x = p4 - nr * k;
        x %= p;
        if(x < 0)
            x += p;
        ans += mp[x];
        mp[x]++;
    }
    cout << ans;
    return 0;
}

