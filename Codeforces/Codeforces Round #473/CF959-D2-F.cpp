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

int n, q, v[100002], is[2000002], ans[100002];
struct x
{
    int a, b, pi;
};
x vq[100002];
bool cmp(x a, x b)
{
    return a.a < b.a;
}
vector<int> prz;
int lg(int x)
{
    int ans = 0;
    while(x != 1)
        x /= 2, ++ans;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    for(int i = 1; i <= q; ++i)
    {
        cin >> vq[i].a >> vq[i].b;
        vq[i].pi = i;
    }
    sort(vq + 1, vq + q + 1, cmp);
    is[0] = 1;
    prz.pb(0);
    int z = 1;
    for(int i = 1; i <= n; ++i)
    {
        if(is[v[i]]);
        else
        {
            int xx = prz.size();
            for(int j = 0; j < xx; ++j)
            {
                is[prz[j] ^ v[i]] = 1;
                prz.pb(prz[j] ^ v[i]);
            }
        }
        while(z <= q && vq[z].a == i)
        {
            if(!is[vq[z].b]);
            else
                ans[vq[z].pi] = pw(2, i - lg(prz.size()));
            ++z;
        }
    }
    for(int i = 1; i <= q; ++i)
        cout << ans[i] << '\n';
    return 0;
}
