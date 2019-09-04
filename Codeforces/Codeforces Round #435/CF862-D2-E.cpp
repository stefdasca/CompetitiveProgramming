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

ll ss, sume[100002], s2;
int n, m, q, v[100002];
ll cb(ll sum)
{
    ll opus = -sum;
    int st = 1;
    int dr = m - n + 1;
    int ans = 1;
    while(st <= dr)
    {
        int mid = (st + dr) / 2;
        if(sume[mid] <= opus)
            ans = mid, st = mid + 1;
        else
            dr = mid - 1;
    }
    ll rez = (1LL<<60);
    for(int j = ans; j <= min(ans + 4, m - n + 1); ++j)
        rez = min(rez, abs(sum + sume[j]));
    for(int j = ans; j >= max(1, ans - 4); --j)
        rez = min(rez, abs(sum + sume[j]));
    return rez;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> q;
    for(int i = 1; i <= n; ++i)
    {
        int nr;
        cin >> nr;
        if(i%2 == 1)
            s2 += nr;
        else
            s2 -= nr;
    }
    for(int i = 1; i <= m; ++i)
        cin >> v[i];
    for(int i = 1; i <= n; ++i)
        if(i%2 == 1)
            ss -= v[i];
        else
            ss += v[i];
    sume[1] = ss;
    for(int i = 2; i + n - 1 <= m; ++i)
    {
        ss += v[i-1];
        ss *= -1;
        if(n%2 == 1)
            ss -= v[i + n - 1];
        else
            ss += v[i + n - 1];
        sume[i] = ss;
    }
    sort(sume + 1, sume + (m - n + 1) + 1);
    cout << cb(s2) << '\n';
    for(int i = 1; i <= q; ++i)
    {
        int st, dr, val;
        cin >> st >> dr >> val;
        if((dr - st + 1) % 2 == 1)
        {
            if(st % 2 == 1)
                s2 += val;
            else
                s2 -= val;
        }
        cout << cb(s2) << '\n';
    }
    return 0;
}
