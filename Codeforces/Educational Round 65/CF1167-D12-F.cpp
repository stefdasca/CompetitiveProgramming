#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int n, v[500002];
long long aib[500002], ans;
int sa[500002];
void upd(int nod, long long val)
{
    for(; nod <= n; nod += (nod & (-nod)))
        aib[nod] += val;
}
long long compute(int nod)
{
    long long ans = 0;
    for(; nod; nod -= (nod & (-nod)))
        ans += aib[nod];
    return ans;
}
int cb(int nr)
{
    int st = 1;
    int dr = n;
    while(st <= dr)
    {
        int mid = (st + dr) / 2;
        if(sa[mid] == nr)
            return mid;
        if(sa[mid] < nr)
            st = mid + 1;
        else
            dr = mid - 1;
    }
}
int main()
{
    // so nyuh shi dae forever
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i], sa[i] = v[i];
    sort(sa + 1, sa + n + 1);
    for(int i = 1; i <= n; ++i)
        upd(cb(v[i]), n - i + 1);
    for(int i = 1; i <= n; ++i)
    {
        long long gs = 1LL * i * (n - i + 1);
        gs %= mod;
        gs = gs * v[i];
        gs %= mod;
        ans = (ans + gs) % mod;
    }
    for(int i = 1; i <= n; ++i)
    {
        upd(cb(v[i]), -(n - i + 1));
        long long xx = compute(cb(v[i]) - 1);
        xx %= mod;
        xx = (xx * v[i]) % mod;
        xx = (xx * i) % mod;
        ans = (ans + xx ) % mod;
    }
    for(int i = 1; i <= n; ++i)
    {
        long long xx = compute(cb(v[i]) - 1);
        xx %= mod;
        xx = (xx * v[i]) % mod;
        xx = (xx * (n - i + 1)) % mod;
        ans = (ans + xx) % mod;
        upd(cb(v[i]), i);
    }
    cout << ans;
    return 0;
}
