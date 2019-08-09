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

int n;
vector<int> v[200002];
int vv[200002], o, st[200002], sf[200002], ord[200002];
int aint[800002], lazy[800002];
void dfs(int nod)
{
    ++o;
    st[nod] = o;
    ord[o] = nod;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        dfs(vecin);
    }
    sf[nod] = o;
}
void lz(int nod, int s, int d)
{
    aint[nod] = (d - s + 1) - aint[nod];
    if(s != d)
    {
        lazy[nod << 1] = (lazy[nod << 1] ^ 1);
        lazy[nod << 1|1] = (lazy[nod << 1|1] ^ 1);
    }
    lazy[nod] = 0;
}
void update(int nod, int s, int d, int L, int R)
{
    if(L <= s && d <= R)
    {
        lazy[nod] ^= 1;
        if(lazy[nod])
            lz(nod, s, d);
        return;
    }
    if(lazy[nod])
        lz(nod, s, d);
    if(d < L || s > R)
        return;
    int mid = (s + d) / 2;
    update(nod << 1, s, mid, L, R);
    update(nod << 1|1, mid+1, d, L, R);
    aint[nod] = aint[nod << 1] + aint[nod << 1|1];
}
int query(int nod, int s, int d, int L, int R)
{
    if(lazy[nod])
        lz(nod, s, d);
    if(L <= s && d <= R)
        return aint[nod];
    if(R < s || L > d)
        return 0;
    int mid = (s + d) / 2;
    int a = query(nod << 1, s, mid, L, R);
    int b = query(nod << 1|1, mid+1, d, L, R);
    aint[nod] = aint[nod << 1] + aint[nod << 1|1];
    return a+b;
}
void build(int nod, int s, int d)
{
    if(s == d)
    {
        aint[nod] = vv[ord[s]];
        return;
    }
    int mid = (s + d) / 2;
    build(nod << 1, s, mid);
    build(nod << 1|1, mid+1, d);
    aint[nod] = aint[nod << 1] + aint[nod << 1|1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 2; i <= n; ++i)
    {
        int pi;
        cin >> pi;
        v[pi].pb(i);
    }
    dfs(1);
    for(int i = 1; i <= n; ++i)
        cin >> vv[i];
    build(1, 1, n);
    int q;
    cin >> q;
    for(; q; --q)
    {
        string p;
        int pz;
        cin >> p >> pz;
        if(p == "pow")
            update(1, 1, n, st[pz], sf[pz]);
        else
            cout << query(1, 1, n, st[pz], sf[pz]) << '\n';
    }
    return 0;
}
