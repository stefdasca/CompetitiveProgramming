/*
            LIVEARCHIVE 3271

    We are going to find the MST for all the possible subsets which contain all the judges and the destination node, and choose
the minimum cost among all the possible trees, with respect to all of the tiebreakers.

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
typedef pair<int, pair<int, int> > edge;


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
int n, x, m, src, tt[25];
vector<edge> e;
vector<vector<int> > adj;
vector<int> v;
bool dfs(int u, int par)
{
    if(u == src)
    {
        v.push_back(u);
        return 1;
    }
    for(int i = 0, len = adj[u].size(); i < len; ++i)
        if(adj[u][i] != par && dfs(adj[u][i], u))
        {
            v.push_back(u);
            return 1;
        }
    return 0;
}
int Find(int nod)
{
    if(nod == tt[nod])
        return nod;
    return tt[nod] = Find(tt[nod]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 0;
    while(1)
    {
        cin >> n;
        if(n == -1)
            break;
        cin >> x;
        cin >> m;
        src = x-1;
        int judges = (1<<(x-1));
        e.resize(m);
        for(int i = 0; i < m; ++i)
        {
            cin >> e[i].se.fi >> e[i].se.se >> e[i].fi;
            --e[i].se.fi, --e[i].se.se;
        }
        sort(e.begin(), e.end());
        vector<int> J;
        int nj;
        cin >> nj;
        for(int i = 0; i < nj; ++i)
        {
            int xx;
            cin >> xx;
            --xx;
            judges |= (1<<xx);
            J.pb(xx);
        }
        int lim = (1 << n);
        int ansd = (1<<30), ansm = 0, ansc = 0;
        for(int msk = 0; msk < lim; msk = (msk + 1) | judges)
        {
            int curd = 0, curc = __builtin_popcount(msk);
            for(int i = 0; i < n; ++i)
                tt[i] = i;
            int comp = curc;
            for(int i = 0; i < m; ++i)
            {
                if(((msk >> e[i].se.fi) & 1) && ((msk >> e[i].se.se) & 1) && Find(e[i].se.se) != Find(e[i].se.fi))
                {
                    tt[tt[e[i].se.se]] = tt[e[i].se.fi];
                    curd += e[i].fi;
                    --comp;
                }
            }
            if(comp != 1)
                continue;
            if(curd < ansd)
            {
                ansd = curd;
                ansm = msk;
            }
            else
                if(curd == ansd)
                {
                    if(curc < ansc)
                    {
                        ansd = curd;
                        ansm = msk;
                    }
                    else
                        if(curc == ansc)
                        {
                            int f = msk ^ ansm;
                            f = f & -f;
                            if(f & msk)
                            {
                                ansd = curd;
                                ansm = msk;
                            }
                        }
                }
        }
        adj.clear();
        adj.resize(n);
        int msk = ansm;
        for(int i = 0; i < n; ++i)
            tt[i] = i;
        for(int i = 0; i < m; ++i)
            if(((msk >> e[i].se.fi) & 1) && ((msk >> e[i].se.se) & 1) && Find(e[i].se.se) != Find(e[i].se.fi))
            {
                tt[tt[e[i].se.se]] = tt[e[i].se.fi];
                adj[e[i].se.fi].pb(e[i].se.se);
                adj[e[i].se.se].pb(e[i].se.fi);
            }
        cout << "Case " << ++t << ": distance = " << ansd << '\n';
        for(int i = 0; i < nj; ++i)
        {
            v.clear();
            dfs(J[i], -1);
            cout << "   ";
            for(int j = v.size() - 1; j >= 0; --j)
                cout << v[j] + 1 << (!j ? '\n' : '-');
        }
        cout << '\n';
    }
    return 0;
}
