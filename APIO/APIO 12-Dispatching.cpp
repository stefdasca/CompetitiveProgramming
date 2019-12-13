/*
        APIO 12-Dispatching

    Classical segment tree task, it can easily be solved with queries based on a DFS order segment tree.

    For a query, one can binary search the maximum value of x such that we can buy all ninjas with strength less or equal to x
and then update the answer.


*/
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
    long long a = rng();
    return a;
}
int n, b, skill[100002], salariu[100002];
vector<int> v[100002];
vector<int> aint[400002];
vector<ll> sp[400002];

int m, st[100002], dr[100002], ord[100002];
void dfs(int nod)
{
    ++m;
    st[nod] = m;
    ord[m] = nod;
    for(int i = 0; i < v[nod].size(); ++i)
        dfs(v[nod][i]);
    dr[nod] = m;
}
void build(int nod, int st, int dr)
{
    if(st == dr)
    {
        aint[nod].pb(salariu[ord[st]]);
        sp[nod].pb(salariu[ord[st]]);
        return;
    }
    int mid = (st + dr) / 2;
    build(nod << 1, st, mid);
    build(nod << 1|1, mid+1, dr);
    int x = 0;
    int y = 0;
    while(x < aint[nod << 1].size() && y < aint[nod << 1|1].size())
    {
        if(aint[nod << 1][x] < aint[nod << 1|1][y])
            aint[nod].pb(aint[nod << 1][x++]);
        else
            aint[nod].pb(aint[nod << 1|1][y++]);
    }
    while(x < aint[nod << 1].size())
        aint[nod].pb(aint[nod << 1][x++]);
    while(y < aint[nod << 1|1].size())
        aint[nod].pb(aint[nod << 1|1][y++]);
    for(int i = 0; i < aint[nod].size(); ++i)
    {
        if(i == 0)
            sp[nod].pb(aint[nod][i]);
        else
            sp[nod].pb(aint[nod][i] + sp[nod][i-1]);
    }
}

pair<ll, int> query(int nod, int st, int dr, int L, int R, int para)
{
    if(dr < L || st > R)
        return {0, 0};
    if(L <= st && dr <= R)
    {
        pair<ll, int> anss = {0, 0};
        int LL = 0;
        int RR = aint[nod].size() - 1;
        while(LL <= RR)
        {
            int mid = (LL + RR) / 2;
            if(aint[nod][mid] <= para)
                anss = {sp[nod][mid], mid + 1}, LL = mid + 1;
            else
                RR = mid - 1;
        }
        return anss;
    }
    int mid = (st + dr) / 2;
    pair<ll, int> xx = query(nod << 1, st, mid, L, R, para);
    pair<ll, int> yy = query(nod << 1|1, mid+1, dr, L, R, para);
    return {xx.fi + yy.fi, xx.se + yy.se};
}
ll qu(int nod)
{
    int L = 1;
    int R = b;
    ll ans = 0;
    while(L <= R)
    {
        int mid = (L + R) / 2;
        pair<ll, int> va = query(1, 1, n, st[nod], dr[nod], mid);
        if(va.fi <= b)
            ans = va.se, L = mid + 1;
        else
            R = mid - 1;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> b;
    for(int i = 1; i <= n; ++i)
    {
        int boss;
        cin >> boss >> salariu[i] >> skill[i];
        if(i != 1)
            v[boss].pb(i);
    }
    dfs(1);
    build(1, 1, n);
    ll ans = 0;
    for(int i = 1; i <= n; ++i)
        if(1LL * skill[i] * (dr[i] - st[i] + 1) > ans)
            ans = max(ans, 1LL * skill[i] * qu(i));
    cout << ans;
    return 0;
}

