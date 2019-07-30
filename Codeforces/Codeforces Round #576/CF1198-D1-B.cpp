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
int n, q;
int v[200002];

int aint[800002];
int lz[800002];
void lazy(int nod, int st, int dr)
{
    int vl = lz[nod];
    lz[nod] = 0;
    if(aint[nod] >= vl)
        return;
    if(st != dr)
    {
        lz[nod << 1] = max(lz[nod << 1], vl);
        lz[nod << 1|1] = max(lz[nod << 1|1], vl);
    }
    aint[nod] = vl;
}
int ans[200002];
void build2(int nod, int st, int dr)
{
    if(lz[nod])
        lazy(nod, st, dr);
    if(st == dr)
    {
        ans[st] = aint[nod];
        return;
    }
    int mid = (st + dr) / 2;
    build2(nod << 1, st, mid);
    build2(nod << 1|1, mid+1, dr);
    aint[nod] = min(aint[nod << 1], aint[nod << 1|1]);
}
void build(int nod, int st, int dr)
{
    if(st == dr)
    {
        aint[nod] = v[st];
        return;
    }
    int mid = (st + dr) / 2;
    build(nod << 1, st, mid);
    build(nod << 1|1, mid+1, dr);
    aint[nod] = min(aint[nod << 1], aint[nod << 1|1]);
}
void upd(int nod, int st, int dr, int poz, int val)
{
    if(lz[nod])
        lazy(nod, st, dr);
    if(st == dr)
    {
        aint[nod] = val;
        return;
    }
    int mid = (st + dr) / 2;
    if(poz <= mid)
        upd(nod << 1, st, mid, poz, val);
    else
        upd(nod << 1|1, mid+1, dr, poz, val);
    aint[nod] = min(aint[nod << 1], aint[nod << 1|1]);
}
void upd2(int nod, int st, int dr, int val)
{
    bool tr = 0;
    if(aint[nod] < val)
    {
        lz[nod] = max(lz[nod], val);
        tr = 1;
    }
    if(lz[nod])
        lazy(nod, st, dr);
    if(tr || (st == dr))
        return;
    int mid = (st + dr) / 2;
    if(aint[nod << 1] < val)
        upd2(nod << 1, st, mid, val);
    if(aint[nod << 1|1] < val)
        upd2(nod << 1|1, mid+1, dr, val);
    aint[nod] = min(aint[nod << 1], aint[nod << 1|1]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    build(1, 1, n);
    cin >> q;
    for(int i = 1; i <= q; ++i)
    {
        int tip;
        cin >> tip;
        if(tip == 1)
        {
            int p, x;
            cin >> p >> x;
            upd(1, 1, n, p, x);
        }
        else
        {
            int x;
            cin >> x;
            upd2(1, 1, n, x);
        }
    }
    build2(1, 1, n);
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    return 0;
}

