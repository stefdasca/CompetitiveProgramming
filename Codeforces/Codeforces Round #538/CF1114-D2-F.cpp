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

int n, q;
struct qu
{
    int L, R, val;
};
qu vq[200002];

int v[400002];

ll aint[1600002], lazy[1600002], ok[1600002], lazyok[1600002];

int xx, inv[302], viz[302];
vector<int> pr;
vector<int> pz[302];

ll findmsk(ll x)
{
    ll ans = 0;
    for(int i = 0; i < pr.size(); ++i)
        if(x % pr[i] == 0)
            ans |= (1LL<<i);
    return ans;
}
void ciur()
{
    for(int i = 2; i <= 300; ++i)
        if(!viz[i])
        {
            ++xx;
            pr.pb(i);
            for(int j = i; j <= 300; j += i)
                viz[j] = 1;
        }
}
void lz(int nod, int st, int dr)
{
    if(lazy[nod] != 1)
        aint[nod] = mul(aint[nod], pw(lazy[nod], dr - st + 1));
    ok[nod] |= lazyok[nod];
    if(st != dr)
    {
        lazyok[nod << 1] |= lazyok[nod];
        lazyok[nod << 1|1] |= lazyok[nod];

        lazy[nod << 1] = mul(lazy[nod << 1], lazy[nod]);
        lazy[nod << 1|1] = mul(lazy[nod << 1|1], lazy[nod]);
    }
    lazy[nod] = 1;
    lazyok[nod] = 0;
}
void build(int nod, int st, int dr)
{
    lazy[nod] = 1;
    if(st == dr)
    {
        aint[nod] = v[st];
        ok[nod] = findmsk(v[st]);
        return;
    }
    int mid = (st + dr) / 2;
    build(nod << 1, st, mid);
    build(nod << 1|1, mid+1, dr);
    ok[nod] = (ok[nod << 1] | ok[nod << 1|1]);
    aint[nod] = mul(aint[nod << 1], aint[nod << 1|1]);
}
void update(int nod, int st, int dr, int L, int R, ll val, ll msk)
{
    if(dr < L || st > R)
        return;
    lz(nod, st, dr);
    if(L <= st && dr <= R)
    {
        lazy[nod] = val;
        lazyok[nod] = msk;
        return;
    }
    int mid = (st + dr) / 2;
    update(nod << 1, st, mid, L, R, val, msk);
    update(nod << 1|1, mid+1, dr, L, R, val, msk);
    aint[nod] = mul(aint[nod], pw(val, min(R, dr) - max(st, L) + 1));
    ok[nod] = ok[nod << 1] | ok[nod << 1|1] | lazyok[nod << 1] | lazyok[nod << 1|1];
}
ll prod, orr;
pair<ll, ll> query(int nod, int st, int dr, int L, int R)
{
    if(dr < L || st > R)
        return {1, 0};
    lz(nod, st, dr);
    if(L <= st && dr <= R)
        return {aint[nod], ok[nod]};
    int mid = (st + dr) / 2;
    pair<ll, ll> aa = query(nod << 1, st, mid, L, R);
    pair<ll, ll> bb = query(nod << 1|1, mid+1, dr, L, R);
    return {mul(aa.fi, bb.fi), aa.se | bb.se};
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ciur();
    for(int i = 2; i <= 300; ++i)
        inv[i] = pw(i, mod - 2);
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    build(1, 1, n);
    for(int i = 1; i <= q; ++i)
    {
        string s;
        cin >> s;
        if(s[0] == 'M')
        {
            cin >> vq[i].L >> vq[i].R >> vq[i].val;
            update(1, 1, n, vq[i].L, vq[i].R, vq[i].val, findmsk(vq[i].val));
        }
        else
        {
            cin >> vq[i].L >> vq[i].R;
            pair<ll, ll> ans = query(1, 1, n, vq[i].L, vq[i].R);
            for(int j = 0; j < pr.size(); ++j)
                if(ans.se & (1LL<<j))
                {
                    ans.fi = mul(ans.fi, inv[pr[j]]);
                    ans.fi = mul(ans.fi, pr[j] - 1);
                }
            cout << ans.fi << '\n';
        }
    }
    return 0;
}
