#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

ll add(ll a, ll b)
{
    ll x = a+b;
    if(x >= mod)
        x -= mod;
    return x;
}
ll mul(ll a, ll b)
{
    return (a*b) % mod;
}

struct dolls
{
    int st, dr;
};
dolls v[300002];
bool cmp(dolls a, dolls b)
{
    return a.dr < b.dr;
}

long long dp[300002], cnt[300002], aint[1200002], mnf[1200002];

long long nst, cn;
void query(int nod, int st, int dr, int L, int R)
{
    if(dr < L || st > R)
        return;
    if(L <= st && dr <= R)
    {
        if(aint[nod] < nst)
            nst = aint[nod], cn = mnf[nod];
        else
            if(aint[nod] == nst)
                cn = add(cn, mnf[nod]);
        return;
    }
    int mid = (st + dr) / 2;
    query(nod << 1, st, mid, L, R);
    query(nod << 1|1, mid+1, dr, L, R);
}
void upd(int nod, int st, int dr, int poz, int de, int vl)
{
    if(st == dr)
    {
        aint[nod] = de;
        mnf[nod] = vl;
        return;
    }
    int mid = (st + dr) / 2;
    if(poz <= mid)
        upd(nod << 1, st, mid, poz, de, vl);
    else
        upd(nod << 1|1, mid+1, dr, poz, de, vl);
    mnf[nod] = 0;
    if(aint[nod << 1] <= aint[nod << 1|1])
        aint[nod] = aint[nod << 1], mnf[nod] = add(mnf[nod], mnf[nod << 1]);
    if(aint[nod << 1] >= aint[nod << 1|1])
        aint[nod] = aint[nod << 1|1], mnf[nod] = add(mnf[nod] , mnf[nod << 1|1]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i].dr >> v[i].st;
    sort(v+1, v+n+1, cmp);
    int mx = 0;
    for(int i = 1; i <= n; ++i)
    {
        int st = 1, dr = i, ans = 0;
        while(st <= dr)
        {
            int mid = (st + dr) / 2;
            if(v[mid].dr <= v[i].st)
                ans = mid, st = mid+1;
            else
                dr = mid-1;
        }
        nst = (1LL<<60), cn = 0;
        if(ans != 0)
        {
            query(1, 1, n, 1, ans);
            dp[i] = nst - v[i].dr + v[i].st;
            cnt[i] = cn;
        }
        else
        {
            dp[i] = 1000000000 - v[i].dr + v[i].st;
            cnt[i] = 1;
        }
        upd(1, 1, n, i, dp[i], cnt[i]);
        mx = max(mx, ans);
    }
    long long mnnst = (1LL<<60), cntt = 0;
    for(int i = mx+1; i <= n; ++i)
    {
        if(dp[i] + v[i].dr < mnnst)
            mnnst = dp[i] + v[i].dr, cntt = cnt[i];
        else
            if(dp[i] + v[i].dr == mnnst)
                cntt = (cntt + cnt[i]) % 1000000007;
    }
    cout << cntt;
    return 0;
}
