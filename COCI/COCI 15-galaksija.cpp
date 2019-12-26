/*
        COCI 15-galaksija

    It can easily be observed that if we run bfs from a certain root and compute xor of edges from root to node x, a path between
2 nodes which have the same xor will have xor 0.

    Knowing this, the approach is now a bit more classical. Run DSU from end to beginning, and at each step, run DFS in the component with less nodes.
Therefore, the worst case complexity will be O(n log^2 n), because we will visit O(n log n) nodes and we also have an extra log factor from using map.

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
int n;
struct muchii
{
    int a, b, c;
};
muchii vm[100002];

int tt[100002], sz[100002], rem[100002];
vector<pair<int, int> > v[100002];
map<int, int> mp[100002];
ll sol, ans[100002];

int Find(int nod)
{
    if(tt[nod] == nod)
        return nod;
    return tt[nod] = Find(tt[nod]);
}
int xorr[100002];
void dfs(int dad, int nod, int plc)
{
    int val = mp[plc][xorr[nod]];
    sol += val;
    mp[plc][xorr[nod]]++;
   // cout << nod << " " << xorr[nod] << '\n';
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].fi;
        if(vecin == dad)
            continue;
        xorr[vecin] = xorr[nod] ^ v[nod][i].se;
        dfs(nod, vecin, plc);
    }
}
void Union(int a, int b, int c, int tna, int tnb)
{
    if(sz[a] < sz[b])
        swap(a, b), swap(tna, tnb);
    map<int, int> ::iterator it;
    for(it = mp[b].begin(); it != mp[b].end(); ++it)
        sol -= 1LL * it -> second * (it -> second - 1) / 2;
    if(sz[a] == 1)
        mp[a][0]++;
    xorr[tnb] = xorr[tna] ^ c;
   // cout << a << " " << b << " " << c << '\n';
    dfs(0, tnb, a);
    v[tna].pb({tnb, c});
    v[tnb].pb({tna, c});
    sz[a] += sz[b];
    tt[b] = a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        tt[i] = i, sz[i] = 1;
    for(int i = 1; i < n; ++i)
        cin >> vm[i].a >> vm[i].b >> vm[i].c;
    for(int i = 1; i < n; ++i)
        cin >> rem[i];
    for(int i = n-1; i >= 1; --i)
        Union(Find(vm[rem[i]].a), Find(vm[rem[i]].b), vm[rem[i]].c, vm[rem[i]].a, vm[rem[i]].b), ans[i] = sol;
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << '\n';
    return 0;
}
