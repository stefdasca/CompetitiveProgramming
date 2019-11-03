#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

struct qu
{
    int tip, a, b;
};
qu vq[100002];

int n, q, v[100002], vv[100002];

int prv[100002], nxt[100002];

ll ans[100002];

vector<ll>ft[400002];
vector<int>vft[400002];


ll vm(ll nod, ll poz)
{
    ll ans = 0;
    for(; poz; poz -= (poz & (-poz)))
        ans += ft[nod][poz];
    return ans;
}

int lb(int nod, int val)
{
    int st = 0;
    int dr = vft[nod].size() - 1;
    int ans = -1;
    while(st <= dr)
    {
        int mid = (st + dr) / 2;
        if(vft[nod][mid] <= val)
            ans = mid, st = mid + 1;
        else
            dr = mid - 1;
    }
    return ans;
}
ll query(int nod, int st, int dr, int L, int R, int tip)
{
    if(dr < L || st > R)
        return 0;
    if(L <= st && dr <= R)
    {
        if(tip == 0)
        {
            if(!vft[nod].size())
                return 0;
            return vm(nod, lb(nod, L - 1) + 1);
        }
        else
        {
            if(!vft[nod].size())
                return 0;
            return vm(nod, ft[nod].size() - 1) - vm(nod, lb(nod, R) + 1);
        }
    }
    int mid = (st + dr) / 2;
    return query(nod << 1, st, mid, L, R, tip) +
           query(nod << 1|1, mid+1, dr, L, R, tip);
}

bool sgn;
void add(int mare, int poz, int val)
{
    for(; poz < ft[mare].size(); poz += (poz & (-poz)))
        if(sgn == 0)
            ft[mare][poz] += val;
        else
            ft[mare][poz] -= val;
}
int ggg;
void update(int nod, int st, int dr, int poz, int val, int tip, int ox)
{
    if(ox == 0)
        vft[nod].pb(val);
    else
        add(nod, lb(nod, val) + 1, poz);
    if(st == dr)
        return;
    int mid = (st + dr) / 2;
    if(poz <= mid)
        update(nod << 1, st, mid, poz, val, tip, ox);
    else
        update(nod << 1|1, mid+1, dr, poz, val, tip, ox);
}

set<int> s[100002];

void work(int poz, int val, int tip, int ox)
{
    if(v[poz] == val)
        return;
    // drop the current element
    set<int> ::iterator it = s[v[poz]].lower_bound(poz);
    set<int> ::iterator it2 = it, it3 = it;
    int vp1 = 0;
    int vp2 = n+1;
    if(it2 != s[v[poz]].begin())
        --it2, vp1 = *it2;
    sgn = 1;
    ++it3;
    if(it3 != s[v[poz]].end())
        vp2 = *it3;
    if(tip == 1)
        update(1, 1, n, poz, vp2, 1, ox);
    if(tip == 0)
        update(1, 1, n, poz, vp1, 0, ox);
    if(vp1 != 0 && tip == 1)
        update(1, 1, n, vp1, poz, 1, ox);
    if(vp2 != n+1 && tip == 0)
        update(1, 1, n, vp2, poz, 0, ox);
    sgn = 0;
    if(vp1 != 0 && tip == 1)
        update(1, 1, n, vp1, vp2, 1, ox);
    if(vp2 != n+1 && tip == 0)
        update(1, 1, n, vp2, vp1, 0, ox);
    s[v[poz]].erase(poz);

    // add the new element
    v[poz] = val;
    s[v[poz]].insert(poz);
    it = s[v[poz]].lower_bound(poz);
    it2 = it, it3 = it;
    vp1 = 0;
    vp2 = n+1;
    if(it2 != s[v[poz]].begin())
        --it2, vp1 = *it2;
    ++it3;
    if(it3 != s[v[poz]].end())
        vp2 = *it3;
    sgn = 1;
    if(vp1 != 0 && tip == 1)
        update(1, 1, n, vp1, vp2, 1, ox);
    if(vp2 != n+1 && tip == 0)
        update(1, 1, n, vp2, vp1, 0, ox);
    sgn = 0;
    if(tip == 1)
        update(1, 1, n, poz, vp2, 1, ox);
    if(tip == 0)
        update(1, 1, n, poz, vp1, 0, ox);
    if(vp1 != 0 && tip == 1)
       update(1, 1, n, vp1, poz, 1, ox);
    if(vp2 != n+1 && tip == 0)
       update(1, 1, n, vp2, poz, 0, ox);
}

void proc(int ox, int txp)
{
    int sgn = -1;
    if(txp == 1)
        sgn = 1;
    for(int i = 1; i <= n; ++i)
        s[i].clear(), v[i] = vv[i];
    for(int i = 1; i <= n; ++i)
        s[v[i]].insert(i);
    if(txp == 0)
    {
        for(int i = 1; i <= n; ++i)
        {
            update(1, 1, n, i, prv[v[i]], 0, ox);
            prv[v[i]] = i;
        }
    }
    else
    {
        for(int i = n; i >= 1; --i)
        {
            if(nxt[v[i]] == 0)
                nxt[v[i]] = n+1;
            update(1, 1, n, i, nxt[v[i]], 1, ox);
            nxt[v[i]] = i;
        }
    }
    for(int i = 1; i <= q; ++i)
    {
        int tip = vq[i].tip;
        if(tip == 2)
        {
            int st, dr;
            st = vq[i].a;
            dr = vq[i].b;
            if(ox == 1)
                ans[i] += sgn * query(1, 1, n, st, dr, txp);
        }
        else
        {
            int poz, val;
            poz = vq[i].a;
            val = vq[i].b;
            work(poz, val, txp, ox);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        vv[i] = v[i];
    }
    for(int i = 1; i <= q; ++i)
        cin >> vq[i].tip >> vq[i].a >> vq[i].b;
    proc(0, 0);
    memset(prv, 0, sizeof(prv));
    for(int i = 0; i <= 400000; ++i)
    {
        sort(vft[i].begin(), vft[i].end());
        vft[i].erase(unique(vft[i].begin(), vft[i].end()), vft[i].end());
    }
    for(int i = 0; i <= 400000; ++i)
        ft[i].resize(vft[i].size() + 5);
    proc(1, 0);
    for(int i = 0; i <= 400000; ++i)
        vft[i].clear();
    for(int i = 0; i <= 400000; ++i)
        ft[i].clear();
    ggg = 1;
    proc(0, 1);
    for(int i = 0; i <= 400000; ++i)
    {
        sort(vft[i].begin(), vft[i].end());
        vft[i].erase(unique(vft[i].begin(), vft[i].end()), vft[i].end());
    }
    for(int i = 0; i <= 400000; ++i)
        ft[i].resize(vft[i].size() + 5);
    memset(nxt, 0, sizeof(nxt));
    proc(1, 1);
    for(int i = 1; i <= q; ++i)
        if(vq[i].tip == 2)
            cout << ans[i] << '\n';
    return 0;
}
