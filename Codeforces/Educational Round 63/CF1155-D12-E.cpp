#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define ll long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rand_seed()
{
    return rng();
}
ll A[52][15], X[15];
ll mod = 1000003;
ll lgput(ll a, ll b)
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
int main()
{
    set<ll>s;
    while(s.size() < 50)
    {
        ll nr = rand_seed() % mod;
        s.insert(nr);
    }
    ll n = 0;
    for(set<ll> ::iterator it = s.begin(); it != s.end(); ++it)
    {
        ++n;
        ll nr = *it;
        ll aa = 1;
        for(ll j = 1; j <= 11; ++j)
        {
            A[n][j] = aa;
            aa = (aa * nr) % mod;
        }
        cout << "? " << nr << endl;
        cin >> A[n][12];
    }
    ll L = 1, C = 1, m = 11;
    while(L <= n && C <= m)
    {
        int k = n+1;
        for(k = L; k <= n; ++k)
            if(A[k][C] != 0)
                break;
        if(k == n+1)
        {
            ++C;
            continue;
        }
        for(int poz = 1; poz <= m+1; ++poz)
            swap(A[L][poz], A[k][poz]);
        long long val = lgput(A[L][C], mod - 2);
        for(int poz = C; poz <= m+1; ++poz)
            A[L][poz] = (A[L][poz] * val) % mod;
        for(int i = L+1; i <= n; ++i)
        {
            val = A[i][C];
            for (int j = 1; j <= m+1; ++j)
                A[i][j] = ((A[i][j] - val * A[L][j]) % mod + mod) % mod;
        }
        ++L;
        ++C;
    }
    for(ll i = n; i; --i)
    {
        ll an = -1;
        for(ll j = 1; j <= m; ++j)
            if(A[i][j] != 0)
            {
                an = j;
                break;
            }
        if(an == -1)
            if(A[i][m+1] == 0)
                continue;
            else
                break;
        ll now = A[i][m+1];
        for (int j = an+1; j <= m; ++j)
            now = ((now - 1LL * A[i][j] * X[j]) % mod + mod)%mod;
        X[an] = now;
    }
    for(ll i = 0; i < mod; ++i)
    {
        ll ans = 0;
        ll pw = 1;
        for(ll j = 1; j <= m; ++j)
            ans = (ans + 1LL * X[j] * pw) % mod, pw = (pw * i) % mod;
        if(ans == 0)
        {
            cout << "! " << i << endl;
            return 0;
        }
    }
    cout << "! " << -1 << endl;
    return 0;
}
