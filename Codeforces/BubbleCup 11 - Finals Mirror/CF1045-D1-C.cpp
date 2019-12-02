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

vector<int> v[100002], v2[200002];

int n, m, q;
int level[200002], minim[200002];
int stramos[30][200002];

int componentCnt = 0;

stack<pair<int, int> > edges;

void addComp(int x, int y)
{
    componentCnt++;
    int a, b;
    while(1)
    {
        a = edges.top().fi;
        b = edges.top().se;
        edges.pop();
        v2[componentCnt].pb(b);
        v2[b].pb(componentCnt);
        if(a == x && b == y)
        {
            v2[componentCnt].pb(a);
            v2[a].pb(componentCnt);
            return;
        }
    }
}

void dfs(int nod, int dad, int nivel)
{
    level[nod] = minim[nod] = nivel;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int x = v[nod][i];
        if(x == dad)
            continue;
        if(level[x] == 0)
        {
            edges.push({nod, x});
            dfs(x, nod, nivel + 1);
            if(minim[x] >= nivel)
                addComp(nod, x);
            minim[nod] = min(minim[nod], minim[x]);
        }
        else
            minim[nod] = min(minim[nod], level[x]);
    }
}

void dfs2(int nod, int dad, int nivel)
{
    stramos[0][nod] = dad;
    level[nod] = nivel;
    for(int i = 1; i < 20; ++i)
        stramos[i][nod] = stramos[i-1][stramos[i-1][nod]];
    for(int i = 0; i < v2[nod].size(); ++i)
    {
        int x = v2[nod][i];
        if(x == dad)
            continue;
        dfs2(x, nod, nivel + 1);
    }

}

int lca(int a, int b)
{
    if(level[a] <= level[b])
        swap(a, b);
    int dif = level[a] - level[b];
    for(int step = 20; step >= 0; --step)
        if(dif & (1<<step))
            a = stramos[step][a];

    if(a == b)
        return a;

    for(int step = 20; step >= 0; --step)
        if(stramos[step][a] != stramos[step][b])
        {
            a = stramos[step][a];
            b = stramos[step][b];
        }
    return stramos[0][a];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> q;
    componentCnt = n;
    for(int i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(1, 0, 1);
    dfs2(1, 0, 1);
    for(int i = 1; i <= q; ++i)
    {
        int a, b;
        cin >> a >> b;
        int ans = (level[a] + level[b] - 2 * level[lca(a, b)]);
        cout << ans / 2 << '\n';
    }
    return 0;
}
