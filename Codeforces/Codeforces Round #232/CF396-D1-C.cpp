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

vector<int>v[300002];
int n, m, q, lvl[300002], start[300002], sfarsit[300002];
void dfs(int nod)
{
    ++m;
    start[nod] = m;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        lvl[vecin] = lvl[nod] + 1;
        dfs(vecin);
    }
    sfarsit[nod] = m;
}

ll aint[3][1200002];
void update(int zona, int nod, int st, int dr, int L, int R, ll val)
{
    if(dr < L || st > R)
        return;
    if(L <= st && dr <= R)
    {
        aint[zona][nod] = add(aint[zona][nod], val);
        return;
    }
    int mid = (st + dr) / 2;
    update(zona, nod << 1, st, mid, L, R, val);
    update(zona, nod << 1|1, mid+1, dr, L, R, val);
}
ll query(int zona, int nod, int st, int dr, int L, int R)
{
    if(L <= st && dr <= R)
        return aint[zona][nod];
    if(dr < L || st > R)
        return 0;
    int mid = (st + dr) / 2;
    return add(aint[zona][nod], add(query(zona, nod << 1, st, mid, L, R), query(zona, nod << 1|1, mid+1, dr, L, R)));
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
    cin >> q;
    for(int i = 1; i <= q; ++i)
    {
        int tip;
        cin >> tip;
        if(tip == 1)
        {
            int poz, val, dif;
            cin >> poz >> val >> dif;
            update(1, 1, 1, n, start[poz], sfarsit[poz], add(val, mul(lvl[poz], dif)));
            update(2, 1, 1, n, start[poz], sfarsit[poz], dif);
        }
        else
        {
            int poz;
            cin >> poz;
            cout << add(query(1, 1, 1, n, start[poz], start[poz]), -mul(query(2, 1, 1, n, start[poz], start[poz]), lvl[poz])) << '\n';
        }
    }
    return 0;
}
