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

ll n, m;
ll k;
ll tt[1000002], sz[1000002], wh[1002][1002];
ll nr[1002][1002];

struct s
{
    ll val, L, C;
};
s st[1000002];
bool cmp(s a, s b)
{
    return a.val > b.val;
}
bool viz[1002][1002];
ll ox[] = {-1, 0, 1, 0};
ll oy[] = {0, 1, 0, -1};
ll Find(ll nod)
{
    if(tt[nod] == nod)
        return nod;
    return tt[nod] = Find(tt[nod]);
}
void Union(ll a, ll b)
{
    if(sz[a] >= sz[b])
        tt[b] = a, sz[a] += sz[b];
    else
        tt[a] = b, sz[b] += sz[a];
}
ll ans[1002][1002];
void process(ll val, ll poz)
{
    memset(viz, 0, sizeof(viz));
    deque<pair<ll, ll> >d;
    for(ll i = 1; i <= n; ++i)
        for(ll j = 1; j <= m; ++j)
            if(nr[i][j] == val && Find(wh[i][j]) == poz)
            {
                d.pb({i, j});
                viz[i][j] = 1;
                break;
            }
    ll s = 0;
    while(!d.empty())
    {
        pair<ll, ll> pz = d[0];
        d.pop_front();
        ans[pz.fi][pz.se] = val;
        ++s;
        if(1LL * s * val == k)
            break;
        for(ll j = 0; j <= 3; ++j)
        {
            ll nL = pz.fi + ox[j];
            ll nC = pz.se + oy[j];
            if(!(nL >= 1 && nL <= n && nC >= 1 && nC <= m) || viz[nL][nC])
                continue;
            if(Find(wh[nL][nC]) == poz)
            {
                d.pb({nL, nC});
                viz[nL][nC] = 1;
            }
        }
    }
    cout << "YES\n";
    for(ll i = 1; i <= n; cout << '\n', ++i)
        for(ll j = 1; j <= m; ++j)
            cout << ans[i][j] << " ";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    ll p = 0;
    for(ll i = 1; i <= n; ++i)
        for(ll j = 1; j <= m; ++j)
        {
            ++p;
            cin >> nr[i][j];
            st[p] = {nr[i][j], i, j};
            tt[p] = p;
            sz[p] = 1;
            wh[i][j] = p;
        }
    sort(st + 1, st + p + 1, cmp);
    for(ll i = 1; i <= p; ++i)
    {
        for(ll j = 0; j <= 3; ++j)
        {
            ll nL = st[i].L + ox[j];
            ll nC = st[i].C + oy[j];
            if(!(nL >= 1 && nL <= n && nC >= 1 && nC <= m))
                continue;
            if(!viz[nL][nC])
                continue;
            if(Find(wh[nL][nC]) != Find(wh[st[i].L][st[i].C]))
                Union(Find(wh[nL][nC]), Find(wh[st[i].L][st[i].C]));
        }
        if(1LL * sz[Find(wh[st[i].L][st[i].C])] * st[i].val >= k && k % st[i].val == 0)
        {
            process(st[i].val, Find(wh[st[i].L][st[i].C]));
            return 0;
        }
        viz[st[i].L][st[i].C] = 1;
    }
    cout << "NO\n";
    return 0;
}
