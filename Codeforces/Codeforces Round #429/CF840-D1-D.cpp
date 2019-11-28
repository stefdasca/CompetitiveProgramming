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

int n, q, v[300002];
vector<int> prz[300002];
vector<pair<int, int> >frq[1200002];
int aint[1200002][12];
int val[1200002][12];
void build(int nod, int st, int dr)
{
    if(st == dr)
    {
        frq[nod].pb({v[st], 1});
        aint[nod][1] = v[st];
        val[nod][1] = 1;
        return;
    }
    int mid = (st + dr) / 2;
    build(nod << 1, st, mid);
    build(nod << 1|1, mid+1, dr);
    int x = 0, y = 0;
    while(x < frq[nod << 1].size() && y < frq[nod << 1|1].size())
    {
        if(frq[nod << 1][x].fi == frq[nod << 1|1][y].fi)
        {
            frq[nod].pb({frq[nod << 1][x].fi, frq[nod << 1][x].se + frq[nod << 1|1][y].se});
            ++x, ++y;
        }
        else
            if(frq[nod << 1][x].fi < frq[nod << 1|1][y].fi)
                frq[nod].pb({frq[nod << 1][x].fi, frq[nod << 1][x].se}), ++x;
            else
                frq[nod].pb({frq[nod << 1|1][y].fi, frq[nod << 1|1][y].se}), ++y;
    }
    while(x < frq[nod << 1].size())
        frq[nod].pb({frq[nod << 1][x].fi, frq[nod << 1][x].se}), ++x;
    while(y < frq[nod << 1|1].size())
        frq[nod].pb({frq[nod << 1|1][y].fi, frq[nod << 1|1][y].se}), ++y;
    for(int i = 0; i < frq[nod].size(); ++i)
    {
        for(int j = 1; j <= 6; ++j)
            if(frq[nod][i].se > val[nod][j])
            {
                for(int k = 6; k > j; --k)
                {
                    val[nod][k] = val[nod][k - 1];
                    aint[nod][k] = aint[nod][k - 1];
                }
                val[nod][j] = frq[nod][i].se;
                aint[nod][j] = frq[nod][i].fi;
                break;
            }
    }
}
int ans = -1;
int cb(int val, int mx)
{
    int st = 0;
    int dr = prz[val].size() - 1;
    int ans = 0;
    while(st <= dr)
    {
        int mid = (st + dr) / 2;
        if(prz[val][mid] <= mx)
            ans = mid + 1, st = mid + 1;
        else
            dr = mid - 1;
    }
    return ans;
}
bool viz[300002];
vector<int> xx;
void query(int nod, int st, int dr, int L, int R, int rap)
{
    if(dr < L || st > R)
        return;
    if(L <= st && dr <= R)
    {
        for(int j = 1; j <= 6 && val[nod][j] != 0; ++j)
        {
            if(viz[aint[nod][j]])
                continue;
            if(prz[aint[nod][j]].size() <= (R - L + 1) / rap)
                continue;
            viz[aint[nod][j]] = 1;
            xx.pb(aint[nod][j]);
        }
        return;
    }
    int mid = (st + dr) / 2;
    query(nod << 1, st, mid, L, R, rap);
    query(nod << 1|1, mid + 1, dr, L, R, rap);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        prz[v[i]].pb(i);
    }
    build(1, 1, n);
    for(int i = 1; i <= q; ++i)
    {
        int L, R, k;
        cin >> L >> R >> k;
        ans = -1;
        query(1, 1, n, L, R, k);
        for(int j = 0; j < xx.size(); ++j)
        {
            viz[xx[j]] = 0;
            if(ans != -1 && xx[j] >= ans)
                continue;
            int qx = cb(xx[j], R) - cb(xx[j], L - 1);
            if(qx > (R - L + 1) / k)
            {
                if(ans == -1)
                    ans = xx[j];
                else
                    ans = min(ans, xx[j]);
            }
        }
        xx.clear();
        cout << ans << '\n';
    }
    return 0;
}
