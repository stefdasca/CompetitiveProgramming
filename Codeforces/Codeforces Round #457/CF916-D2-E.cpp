#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

int n, q, value[100002];

ll aint[400002], lazy[400002];

void lz(int nod, int st, int dr)
{
    aint[nod] += 1LL * (dr - st + 1) * lazy[nod];
    if(st != dr)
    {
        lazy[nod << 1] += lazy[nod];
        lazy[nod << 1|1] += lazy[nod];
    }
    lazy[nod] = 0;
}
void update(int nod, int st, int dr, int pozs, int pozd, ll val)
{
    lz(nod, st, dr);
    if(dr < pozs || st > pozd)
        return;
    if(pozs <= st && dr <= pozd)
    {
        aint[nod] += 1LL * (dr - st + 1) * val;
        if(st != dr)
        {
            lazy[nod << 1] += val;
            lazy[nod << 1|1] += val;
        }
        return;
    }
    int mid = (st + dr) / 2;
    update(nod << 1, st, mid, pozs, pozd, val);
    update(nod << 1|1, mid+1, dr, pozs, pozd, val);
    aint[nod] = aint[nod << 1] + aint[nod << 1|1];
}

ll query(int nod, int st, int dr, int L, int R)
{
    lz(nod, st, dr);
    if(L <= st && dr <= R)
        return aint[nod];
    if(dr < L || st > R)
        return 0;
    int mid = (st + dr) / 2;
    return query(nod << 1, st, mid, L, R) + query(nod << 1|1, mid+1, dr, L, R);
}

vector<int> v[100002];
int start[100002], finish[100002], m, sts[100002], lvl[100002];

int rmq[20][200002], lg[200002];
int xx;
int euler[200002];
int nivel[200002];
int lst[100002];

int tt[20][100002];
void dfs(int dad, int nod)
{
    ++xx;
    euler[xx] = nod;
    nivel[xx] = lvl[nod];

    ++m;
    start[nod] = m;
    sts[nod] = 1;

    tt[0][nod] = dad;
    for(int i = 1; i <= 18; ++i)
        tt[i][nod] = tt[i-1][tt[i-1][nod]];
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        lvl[vecin] = lvl[nod] + 1;
        dfs(nod, vecin);
        sts[nod] += sts[vecin];

        ++xx;
        euler[xx] = nod;
        nivel[xx] = lvl[nod];
    }
    finish[nod] = m;

    lst[nod] = xx;
}

int kthanc(int nod, int am)
{
    for(int i = 19; i >= 0; --i)
        if(am >= (1<<i))
            am -= (1<<i), nod = tt[i][nod];
    return nod;
}

ll addtotal;
void buildLCA()
{
    for(int i = 2; i <= xx; ++i)
        lg[i] = lg[i/2] + 1;
    for(int i = 1; i <= xx; ++i)
        rmq[0][i] = i;
    for(int i = 1; i <= lg[xx]; ++i)
        for(int j = 1; j + (1<<i) - 1 <= xx; ++j)
            if(nivel[rmq[i-1][j]] < nivel[rmq[i-1][j + (1<<(i - 1))]])
                rmq[i][j] = rmq[i-1][j];
            else
                rmq[i][j] = rmq[i-1][j + (1<<(i-1))];
}
int LCA(int x, int y)
{
    int a = min(lst[x], lst[y]);
    int b = max(lst[x], lst[y]);
    int ln = lg[b - a + 1];
    int ans = rmq[ln][a];
    if(nivel[rmq[ln][b - (1<<ln) + 1]] < nivel[ans])
        ans = rmq[ln][b - (1<<ln) + 1];
    return euler[ans];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
        cin >> value[i];
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(0, 1);
    buildLCA();
    for(int i = 1; i <= n; ++i)
        update(1, 1, n, start[i], start[i], value[i]);
    int root = 1;
    for(int i = 1; i <= q; ++i)
    {
        int tip;
        cin >> tip;
        if(tip == 1)
            cin >> root;
        if(tip == 2)
        {
            ll a, b, x;
            cin >> a >> b >> x;
            int org = 0;
            if(LCA(root, a) == root && LCA(root, b) == root)
                org = LCA(a, b);
            else
                if(LCA(root, a) == root || LCA(root, b) == root)
                    org = root;
                else
                {
                    int xxx = LCA(root, a);
                    int yyy = LCA(root, b);
                    int zzz = LCA(a, b);
                    org = xxx;
                    if(lvl[org] < lvl[yyy])
                        org = yyy;
                    if(lvl[org] < lvl[zzz])
                        org = zzz;
                }
            if(org == root)
                update(1, 1, n, 1, n, x);
            else
                if(LCA(org, root) == root)
                    update(1, 1, n, start[org], finish[org], x);
                else
                    if(LCA(org, root) == org)
                    {
                        update(1, 1, n, 1, n, x);
                        update(1, 1, n, start[kthanc(root, lvl[root] - lvl[org] - 1)], finish[kthanc(root, lvl[root] - lvl[org] - 1)], -x);
                    }
                    else
                        update(1, 1, n, start[org], finish[org], x);
        }
        if(tip == 3)
        {
            int quval;
            cin >> quval;
            if(root == quval)
                cout << query(1, 1, n, 1, n) << '\n';
            else
                if(LCA(root, quval) == root)
                    cout << query(1, 1, n, start[quval], finish[quval]) << '\n';
                else
                    if(LCA(quval, root) == quval)
                    {
                        ll ans = query(1, 1, n, 1, n);
                        ans = ans - query(1, 1, n, start[kthanc(root, lvl[root] - lvl[quval] - 1)], finish[kthanc(root, lvl[root] - lvl[quval] - 1)]);
                        cout << ans << '\n';
                    }
                    else
                        cout << query(1, 1, n, start[quval], finish[quval]) << '\n';
        }
    }
    return 0;
}
