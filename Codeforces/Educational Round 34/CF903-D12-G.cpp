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

ll a[200002], b[200002];
vector<pair<int, ll> > g[200002];
ll sum[200002];
ll tree[800002], lazy[800002];
multiset<ll> limit;

void build(int node, int st, int dr)
{
    if (st == dr)
    {
        tree[node] = b[st];
        return;
    }
    int middle = (st + dr) / 2;
    build(2 * node, st, middle);
    build(2 * node + 1, middle + 1, dr);
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

void Propagate(int node)
{
    lazy[2 * node] += lazy[node];
    lazy[2 * node + 1] += lazy[node];
    lazy[node] = 0;
}

long long Query(int node, int st, int dr, int L, int R)
{
    if (L <= st && dr <= R)
        return tree[node] - lazy[node];
    Propagate(node);
    int middle = (st + dr) / 2;
    ll answer = (1LL<<60);
    if (L <= middle)
        answer = min(answer, Query(2 * node, st, middle, L, R));
    if (middle + 1 <= R)
        answer = min(answer, Query(2 * node + 1, middle + 1, dr, L, R));
    tree[node] = min(tree[2 * node] - lazy[2 * node], tree[2 * node + 1] - lazy[2 * node + 1]);
    return answer;
}

void Update(int node, int st, int dr, int L, int R, long long add)
{
    if (L <= st && dr <= R)
    {
        lazy[node] += add;
        return;
    }
    Propagate(node);
    int middle = (st + dr) / 2;
    ll answer = (1LL<<60);
    if (L <= middle)
        Update(2 * node, st, middle, L, R, add);
    if (middle + 1 <= R)
        Update(2 * node + 1, middle + 1, dr, L, R, add);
    tree[node] = min(tree[2 * node] - lazy[2 * node], tree[2 * node + 1] - lazy[2 * node + 1]);
}

void Precompute(int n)
{
    build(1, 1, n);
    for (int i = 1; i <= n; i++)
    {
        sort(g[i].begin(), g[i].end());
        reverse(g[i].begin(), g[i].end());
        long long now = 0;
        for(int j = 0; j < g[i].size(); ++j)
        {
            pair<int, ll> it = g[i][j];
            long long add = min(Query(1, 1, n, it.first, n), it.second);
            now += add;
            Update(1, 1, n, it.first, n, add);
        }
        sum[i] = sum[i - 1] + now;
    }
    for (int i = 1; i <= n; i++)
        limit.insert(sum[i] + a[i]);
}

void Change(int x, int y)
{
    limit.erase(limit.find(sum[x] + a[x]));
    a[x] = y;
    limit.insert(sum[x] + a[x]);
}
int n, m, q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> q;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i] = x;
        b[i] = y;
    }
    b[n] = (1LL << 60);
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].pb({y, z});
    }
    Precompute(n);
    cout << *limit.begin() << '\n';
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        cin >> x >> y;
        Change(x, y);
        cout << *limit.begin() << '\n';
    }
    return 0;
}
