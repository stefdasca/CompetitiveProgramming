#include<bits/stdc++.h>
#define MAXN 200000
#define mod 998244353
#define INF 1000000000
using namespace std;

int n, q;
struct Line
{
    long long a, b;
};
Line lazy[1 + 4 * MAXN];
long long aint[1 + 4 * MAXN];
int Left, Right;
Line val;
long long ans;

inline Line Combine(Line A, Line B)
{
    return {(A.a * B.a) % mod, (A.b * B.a + B.b) % mod};
}
void update(int p, int st, int dr)
{
    if(Left <= st && dr <= Right)
    {
        lazy[p] = Combine(lazy[p], val);
        if(st != dr)
        {
            lazy[2 * p] = Combine(lazy[2 * p], lazy[p]);
            lazy[2 * p + 1] = Combine(lazy[2 * p + 1], lazy[p]);
        }
        aint[p] = (lazy[p].a * aint[p] + lazy[p].b * (dr - st + 1)) % mod;
        lazy[p] = {1, 0};
    }
    else
    {
        lazy[2 * p] = Combine(lazy[2 * p], lazy[p]);
        lazy[2 * p + 1] = Combine(lazy[2 * p + 1], lazy[p]);
        lazy[p] = {1, 0};
        int m = (st + dr) / 2;
        if(Left <= m)
            update(2 * p, st, m);
        if(m + 1 <= Right)
            update(2 * p + 1, m + 1, dr);
        aint[p] = ((lazy[2 * p].a * aint[2 * p] + lazy[2 * p].b * (m - st + 1)) + (lazy[2 * p + 1].a * aint[2 * p + 1] + lazy[2 * p + 1].b * (dr - m))) % mod;
    }
}

void query(int p, int st, int dr)
{
    if(Left <= st && dr <= Right)
    {
        if(st != dr)
        {
            lazy[2 * p] = Combine(lazy[2 * p], lazy[p]);
            lazy[2 * p + 1] = Combine(lazy[2 * p + 1], lazy[p]);
        }
        aint[p] = (lazy[p].a * aint[p] + lazy[p].b * (dr - st + 1)) % mod;
        lazy[p] = {1, 0};
        ans = (ans + aint[p]) % mod;
    }
    else
    {
        lazy[2 * p] = Combine(lazy[2 * p], lazy[p]);
        lazy[2 * p + 1] = Combine(lazy[2 * p + 1], lazy[p]);
        lazy[p] = {1, 0};

        int m = (st + dr) / 2;
        if(Left <= m)
            query(2 * p, st, m);
        if(m + 1 <= Right)
            query(2 * p + 1, m + 1, dr);

        aint[p] = ((lazy[2 * p].a * aint[2 * p] + lazy[2 * p].b * (m - st + 1)) + (lazy[2 * p + 1].a * aint[2 * p + 1] + lazy[2 * p + 1].b * (dr - m))) % mod;
    }
}

map <int, set <pair <int, int>>> M;
pair <int, int> S, T;
pair <int, int> gInt(int x, int l, int r)
{
    auto it = M[x].lower_bound({l, INF});
    if(it != M[x].begin() && prev(it) -> second >= l)
        it--;
    if(it == M[x].end())
        return {-1, -1};
    if(it -> first > r)
        return {-1, -1};

    pair <int, int> q = *it;
    T = *it;
    M[x].erase(it);
    return {max(q.first, l), min(q.second, r)};
}
void Insert(int x, int l, int r)
{
    Left = l, Right = r, val = {1, 1};
    update(1, 1, n);

    int ok = 0;
    pair <int, int> A = gInt(x, l, r);
    S = T;
    while(A != make_pair(-1, -1))
    {
        ok = 1;
        Left = A.first, Right = A.second, val = {1, -1};
        update(1, 1, n);
        val = {2, 0};
        update(1, 1, n);
        A = gInt(x, l, r);
    }
    if(ok)
        M[x].insert({min(S.first, l), max(T.second, r)});
    else
        M[x].insert({l, r});
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for(int i = 1; i < 4 * n; i++)
        lazy[i] = {1, 0};
    for(int i = 1; i <= q; i++)
    {
        int t, l, r, x;
        cin >> t;
        if(t == 1)
        {
            cin >> l >> r >> x;
            Insert(x, l, r);
            ans = 0, Left = 3, Right = 4;
            query(1, 1, n);
        }
        else
        {
            cin >> l >> r;
            ans = 0, Left = l, Right = r;
            query(1, 1, n);
            cout << ans << '\n';
        }
    }
    return 0;
}
