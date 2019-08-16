#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

ll cmmdc(ll a, ll b)
{
    ll c = 0;
    while(b)
    {
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}
string ans;
ll n, hsh[1000002], hsh2[1000002];
ll hsh3[1000002], hsh4[1000002];
ll base = 100003, mod = 100123456789;
ll base2 = 99991, mod2 = 1000000007;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> ans;
    for(int i = 2; i <= n; ++i)
    {
        string ans2;
        cin >> ans2;
        for(int j = 0; j < min(ans.size(), ans2.size()); ++j)
        {
            hsh2[j] = (j > 0) * hsh2[j-1] * base + (ans2[j] - '0');
            hsh2[j] %= mod;
            hsh4[j] = (j > 0) * hsh4[j-1] * base2 + (ans2[j] - '0');
            hsh4[j] %= mod2;
        }
        ll pw = 1;
        ll pw2 = 1;
        for(int j = 0; j < min(ans.size(), ans2.size()); ++j)
        {
            hsh[j] = (j > 0) * hsh[j-1] + pw * (ans[ans.size() - j - 1] - '0');
            hsh[j] %= mod;
            hsh3[j] = (j > 0) * hsh3[j-1] + pw2 * (ans[ans.size() - j - 1] - '0');
            hsh3[j] %= mod2;
            pw *= base;
            pw %= mod;
            pw2 *= base2;
            pw2 %= mod2;
        }
        int rem = 0;
        for(int j = 0; j < min(ans.size(), ans2.size()); ++j)
            if(hsh[j] == hsh2[j] && hsh3[j] == hsh4[j])
                rem = j+1;
        for(int j = 1; j <= rem; ++j)
            ans.pop_back();
        ans += ans2;
    }
    cout << ans;
    return 0;
}
