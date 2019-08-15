#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

ll add(ll a, ll b)
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

ll ans = 0;

int n, val[200002];
vector<int>v[200002];

int pd[200002], id[200002];

void dfs(int dad, int nod)
{
    pd[nod] = 1;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        dfs(nod, vecin);
        pd[nod] += id[vecin];
        id[nod] += pd[vecin];
    }
}

void dfs2(int dad, int nod, int pr, int imp)
{
    ll ct = 0;
    ct = add(ct, mul(val[nod], mul(pr, pd[nod] + id[nod])));
    ct = add(ct, -mul(val[nod], mul(imp, pd[nod] + id[nod])));
    ct = add(ct, mul(val[nod], n));
    int sim = 0, sp = 0;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        sim += id[vecin];
        sp += pd[vecin];
    }
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        sim -= id[vecin];
        sp -= pd[vecin];
        ct = add(ct, mul(val[nod], mul(id[vecin], pr + imp + sim + sp + 1)));
        ct = add(ct, -mul(val[nod], mul(pd[vecin], pr + imp + sim + sp + 1)));
        dfs2(nod, vecin, imp + sp, pr + sim + 1);
        sim += id[vecin];
        sp += pd[vecin];
    }
    ans = add(ans, ct);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> val[i];
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(0, 1);
    dfs2(0, 1, 0, 0);
    cout << ans;
    return 0;
}

