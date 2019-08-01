/*
        COCI 16-zamjene

    We can implement the queries using DSU, while at the same time we have to be careful with the time limit, since it's
quite tight.

    In order to store efficiently the multiset of numbers included in a component, we will use hashing and using DSU, we can
unite the hash values.


*/

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define NMAX 1000010

using namespace std;

typedef long long ll;

int n, q;
int v[NMAX];
int st[NMAX];
int tt[NMAX], sz[NMAX];
ll hsh[NMAX], sthsh[NMAX], pw[NMAX];

unordered_map<ll, int> diff_nodes;
ll tot_pairs;

void add_nodes(int sgn, ll diff, int m)
{
    if(diff != 0)
        tot_pairs += sgn * m * diff_nodes[-diff];
    diff_nodes[diff] += sgn * m;
}
int Find(int a)
{
    if(tt[a] == a)
        return a;
    return tt[a] = Find(tt[a]);
}
void Union(int a, int b)
{
    add_nodes(-1, hsh[a] - sthsh[a], sz[a]);
    add_nodes(-1, hsh[b] - sthsh[b], sz[b]);
    if(sz[a] > sz[b])
    {
        tt[b] = a, sz[a] += sz[b];
        hsh[a] = hsh[a]+hsh[b];
        sthsh[a] = sthsh[a]+sthsh[b];
        add_nodes(1, hsh[a] - sthsh[a], sz[a]);
    }
    else
    {
        tt[a] = b, sz[b] += sz[a];
        hsh[b] = hsh[a]+hsh[b];
        sthsh[b] = sthsh[a]+sthsh[b];
        add_nodes(1, hsh[b] - sthsh[b], sz[b]);
    }

}
void add(int sgn, int u, int pos, int value)
{
  sthsh[u] += sgn * pw[pos];
  hsh[u] += sgn * pw[value];
  sz[u] += sgn;
}
void swp(int a, int b)
{
    int u = Find(a);
    int vv = Find(b);
    add_nodes(-1, hsh[u] - sthsh[u], sz[u]);
    add_nodes(-1, hsh[vv] - sthsh[vv], sz[vv]);
    add(-1, Find(a), a, v[a]);
    add(-1, Find(b), b, v[b]);

    swap(v[a], v[b]);

    add(1, Find(a), a, v[a]);
    add(1, Find(b), b, v[b]);
    add_nodes(1, hsh[u] - sthsh[u], sz[u]);
    add_nodes(1, hsh[vv] - sthsh[vv], sz[vv]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    pw[0] = 1;
    for(int i = 1; i < NMAX; ++i)
        pw[i] = pw[i-1] * 1234577;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        st[i] = v[i];
        tt[i] = i;
        sz[i] = 1;
    }
    sort(st + 1, st + n + 1);
    for(int i = 1; i <= n; ++i)
    {
        hsh[i] = pw[v[i]];
        sthsh[i] = pw[st[i]];
        add_nodes(1, hsh[i] - sthsh[i], sz[i]);
    }
    for(int i = 1; i <= q; ++i)
    {
        int tip;
        cin >> tip;
        if(tip == 1)
        {
            int a, b;
            cin >> a >> b;
            if(Find(a) == Find(b))
            {
                swap(v[a], v[b]);
                continue;
            }
            swp(a, b);
        }
        if(tip == 2)
        {
            int a, b;
            cin >> a >> b;
            if(Find(a) != Find(b))
                Union(Find(a), Find(b));
        }
        if(tip == 3)
        {
            if(diff_nodes[0] == n)
                cout << "DA\n";
            else
                cout << "NE\n";
        }
        if(tip == 4)
        {
            cout << tot_pairs << '\n';
        }
    }
    return 0;
}

