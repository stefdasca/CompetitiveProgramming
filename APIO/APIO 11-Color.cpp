/*
        APIO 11-Color

    If we fix row 1 and column 1, for all other elements, the following relations hold:

    a[i][j] = a[1][1] ^ a[1][j] ^ a[i][1] ^ ((i % 2 == 0) && (j % 2 == 0))
    a[1][j] ^ a[i][1] = a[i][j] ^ a[1][1] ^ ((i % 2 == 0) && (j % 2 == 0))

    if we fix the color of (1, 1), the answer will therefore be equal to 2^(number of components)
from the bipartite graph or 0 if the graph isn't bipartite.

    if a[1][j] ^ a[i][1] = 0 -> a[1][j] == a[i][1] -> addEdge(a[1][j], z), addEdge(z, a[i][1])
    if a[1][j] ^ a[i][1] = 1 -> a[1][j] != a[i][1] -> addEdge(a[1][j], a[i][1])

*/
#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000000
#define dancila 3.14159265359
#define eps 1e-9

// #define fisier 1

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

int n, m, k, ans, col[300002], viz[300002];
struct squares
{
    int a, b, c;
};
squares nf[300002];
vector<int> v[300002];
int getpos(int x, int y)
{
    if(x == 1)
        return y-2;
    return m+x-3;
}
void dfs(int nod)
{
    viz[nod] = 1;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(col[vecin] && col[vecin] != (3 ^ col[nod]))
            ans = 0;
        else
            col[vecin] = col[nod] ^ 3;
        if(!viz[vecin])
            dfs(vecin);
    }
}
int solve(int fix)
{
    for(int i = 0; i <= 300000; ++i)
        v[i].clear(), col[i] = viz[i] = 0;
    int p = n+m-2;
    for(int i = 1; i <= k; ++i)
    {
        if(nf[i].a == 1 || nf[i].b == 1)
        {
            if(nf[i].a == 1 && nf[i].b == 1)
            {
                if(nf[i].c != fix)
                    return 0;
            }
            else
                col[getpos(nf[i].a, nf[i].b)] = nf[i].c + 1;
            continue;
        }
        int nw = nf[i].c ^ fix ^ ((nf[i].a % 2 == 0) && (nf[i].b % 2 == 0));
        int aa = getpos(1, nf[i].b);
        int bb = getpos(nf[i].a, 1);
        if(nw)
        {
            v[aa].pb(bb);
            v[bb].pb(aa);
        }
        else
        {
            v[aa].pb(p);
            v[p].pb(aa);
            v[bb].pb(p);
            v[p].pb(bb);
            ++p;
        }
    }
    ans = 1;
    for(int i = 0; i < n+m-2; ++i)
        if(!viz[i] && col[i])
            dfs(i);
    for(int i = 0; i < n+m-2; ++i)
        if(!viz[i])
            col[i] = 1, dfs(i), ans = mul(ans, 2);
    return ans;
}
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for(int i = 1; i <= k; ++i)
        cin >> nf[i].a >> nf[i].b >> nf[i].c;
    cout << add(solve(0), solve(1));
    return 0;
}
