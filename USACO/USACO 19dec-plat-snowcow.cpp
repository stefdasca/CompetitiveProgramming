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

ifstream f("snowcow.in");
ofstream g("snowcow.out");

int n, q;
vector<int> v[100002];
set<pair<int, int> >s[100002];
int m, start[100002], sfarsit[100002];
void dfs(int dad, int nod)
{
    ++m;
    start[nod] = m;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin != dad)
            dfs(nod, vecin);
    }
    sfarsit[nod] = m;
}
ll aint[1000002], lazy[1000002];

void lz(int nod, int L, int R)
{
    if(!lazy[nod])
        return;
    aint[nod] += 1LL * (R - L + 1) * lazy[nod];
    if(L != R)
    {
        lazy[nod << 1] += lazy[nod];
        lazy[nod << 1|1] += lazy[nod];
    }
    lazy[nod] = 0;
}
void update(int nod, int L, int R, int st, int dr, int val)
{
    lz(nod, L, R);
    if(R < st || L > dr)
        return;
    if(st <= L && R <= dr)
    {
        aint[nod] += 1LL * (R - L + 1) * val;
        if(L != R)
        {
            lazy[nod << 1] += val;
            lazy[nod << 1|1] += val;
        }
        return;
    }
    int mid = (L + R) / 2;
    update(nod << 1, L, mid, st, dr, val);
    update(nod << 1|1, mid+1, R, st, dr, val);
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
    ll ans = query(nod << 1, st, mid, L, R) + query(nod << 1|1, mid+1, dr, L, R);
    aint[nod] = aint[nod << 1] + aint[nod << 1|1];
    return ans;
}

void proc(int nod, int col)
{
    set<pair<int, int> > ::iterator it;
    it = s[col].lower_bound({start[nod], 0});
    bool noupdate = 0;
    if(it != s[col].begin())
    {
        --it;
        int nd = (*it).se;
        if(sfarsit[nd] >= sfarsit[nod])
            noupdate = 1;
    }
    it = s[col].lower_bound({start[nod], 0});
    while(1)
    {
        if(it == s[col].end())
            break;
        if((*it).fi > sfarsit[nod])
            break;
        int xx = (*it).se;
        update(1, 1, n, start[xx], sfarsit[xx], -1);
        s[col].erase({start[xx], xx});
        it = s[col].lower_bound({start[nod], 0});
    }
    if(!noupdate)
    {
        update(1, 1, n, start[nod], sfarsit[nod], 1);
        s[col].insert({start[nod], nod});
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    f >> n >> q;
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        f >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(0, 1);
    for(int i = 1; i <= q; ++i)
    {
        int tip;
        f >> tip;
        if(tip == 2)
        {
            int nod;
            f >> nod;
            g << query(1, 1, n, start[nod], sfarsit[nod]) << '\n';
        }
        else
        {
            int nod, col;
            f >> nod >> col;
            proc(nod, col);
        }
    }
    return 0;
}
