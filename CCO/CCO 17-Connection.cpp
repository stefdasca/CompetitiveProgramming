/*
        CCO 17-Connection

    The implementation is inspired by https://gist.github.com/luciocf/3cae49c9fe640a7d78e22ca832908091

    The solution uses Online Bridge Searching (https://cp-algorithms.com/graph/bridge-searching-online.html), alongside
parallel binary search.

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

// #define fisier 1

using namespace std;

typedef long long ll;

int dsu_cc[150005], dsu_2cc[150005], sz_cc[150005], tt[150005];
int it, last_it[150005], n, m, q;
int ans[150005], st[150005], dr[150005];
pair<int, int> edge[150005], query[150005];
vector<int> V[150005];

void init()
{
    for(int i = 1; i <= n+1; i++)
    {
        dsu_cc[i] = dsu_2cc[i] = i;
        sz_cc[i] = 1, tt[i] = -1;
    }
    for(int i = 1; i <= m; i++)
        V[i].clear();
}

int find_2cc(int x)
{
    if(x == -1)
        return -1;
    if(dsu_2cc[x] == x)
        return x;
    return dsu_2cc[x] = find_2cc(dsu_2cc[x]);
}

int find_cc(int x)
{
    x = find_2cc(x);
    if(dsu_cc[x] == x)
        return x;
    return dsu_cc[x] = find_cc(dsu_cc[x]);
}

void make_root(int x)
{
    int root = x, ant = -1;
    while(x != -1)
    {
        int p = find_2cc(tt[x]);
        dsu_cc[x] = root, tt[x] = ant;
        ant = x;
        x = p;
    }
    sz_cc[root] = sz_cc[ant];
}

void join_path(int a, int b)
{
    ++it;
    vector<int> path_a, path_b;
    int lca = -1;
    while(lca == -1)
    {
        if(a != -1)
        {
            a = find_2cc(a);
            path_a.push_back(a);
            if(last_it[a] == it)
            {
                lca = a;
                break;
            }
            last_it[a] = it;
            a = tt[a];
        }
        if(b != -1)
        {
            b = find_2cc(b);
            path_b.push_back(b);
            if(last_it[b] == it)
            {
                lca = b;
                break;
            }
            last_it[b] = it;
            b = tt[b];
        }
    }
    for(auto v: path_a)
    {
        dsu_2cc[v] = lca;
        if (v == lca)
            break;
    }
    for(auto v: path_b)
    {
        dsu_2cc[v] = lca;
        if(v == lca)
            break;
    }
}

void add(int a, int b)
{
    a = find_2cc(a);
    b = find_2cc(b);
    if (a == b)
        return;
    int ca = find_cc(a);
    int cb = find_cc(b);
    if(ca == cb)
        join_path(a, b);
    else
    {
        if(sz_cc[ca] > sz_cc[cb])
        {
            swap(a, b);
            swap(ca, cb);
        }
        make_root(a);
        tt[a] = dsu_cc[a] = b;
        sz_cc[cb] += sz_cc[ca];
    }
}
void solve(void)
{
    for(int I = 1; I <= 25; I++)
    {
        init();
        for(int i = 1; i <= q; i++)
        {
            if(st[i] > dr[i])
                continue;
            int mid = (st[i] + dr[i]) / 2;
            V[mid].push_back(i);
        }
        for(int i = 1; i <= m; i++)
        {
            add(edge[i].fi, edge[i].se);
            for(auto qq: V[i])
            {
                int u = query[qq].fi;
                int v = query[qq].se;
                if(find_2cc(u) == find_2cc(v))
                    ans[qq] = i, dr[qq] = i-1;
                else st[qq] = i+1;
            }
        }
    }
}
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;
    for(int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        a++, b++;
        edge[i] = {a, b};
    }
    for(int i = 1; i <= q; i++)
    {
        int a, b;
        cin >> a >> b;
        a++, b++;
        query[i] = {a, b};
        st[i] = 1, dr[i] = m;
    }
    memset(ans, -1, sizeof(ans));
    solve();
    for(int i = 1; i <= q; i++)
        cout << (ans[i] == -1 ? -1 : ans[i] - 1) << '\n';
    return 0;
}
