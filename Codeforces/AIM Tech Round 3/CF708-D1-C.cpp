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

vector<int>v[400002];

int n, sts[400002], m, st[400002], dr[400002], ord[400002];
map<int, int> aint[400002 * 3];

int val[400002];

void dfs(int dad, int nod)
{
    sts[nod] = 1;
    ++m;
    ord[m] = nod;
    st[nod] = m;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        dfs(nod, vecin);
        sts[nod] += sts[vecin];
    }
    val[nod] = sts[nod];
    dr[nod] = m;
}


inline void update(int nod, int L, int R, int poz, int val, int tip)
{
    if(tip == 0)
    {
        aint[nod][val]--;
        if(aint[nod][val] == 0)
            aint[nod].erase(val);
    }
    else
        aint[nod][val]++;
    if(L == R)
        return;
    int mid = (L + R) / 2;
    if(poz <= mid)
        update(nod << 1, L, mid, poz, val, tip);
    else
        update(nod << 1|1, mid+1, R, poz, val, tip);
}

bool ans;
inline void build(int nod, int L, int R)
{
    for(int i = L; i <= R; ++i)
        if(sts[ord[i]] <= n/2)
            aint[nod][sts[ord[i]]]++;
    if(L == R)
        return;
    int mid = (L + R) / 2;
    build(nod << 1, L, mid);
    build(nod << 1|1, mid+1, R);
}
inline bool ub(int nod, int L, int R, int ss, int dd, int src)
{
    if(R < ss || L > dd)
        return 0;
    if(ans)
        return 0;
    if(ss <= L && R <= dd)
    {
        map<int, int> ::iterator it;
        it = aint[nod].lower_bound(src - n/2);
        if(it == aint[nod].end())
            return 0;
        int nr = it->fi;
        if(nr <= n/2 && src - nr <= n/2)
        {
            ans = 1;
            return 1;
        }
        return 0;
    }
    int mid = (L + R) / 2;
    return (ub(nod << 1, L, mid, ss, dd, src) | ub(nod << 1|1, mid+1, R, ss, dd, src));
}
bool ok[400002];
void dfs2(int dad, int nod, int xtr)
{
    int mx = xtr;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        mx = max(mx, sts[vecin]);
    }
    if(mx <= n/2)
        ok[nod] = 1;
    else
    {
        if(xtr > n/2)
        {
            if(st[nod] > 1)
                ans = 0, ok[nod] |= ub(1, 1, n, 1, st[nod] - 1, xtr);
            if(!ok[nod] && dr[nod] < n)
                ans = 0, ok[nod] |= ub(1, 1, n, dr[nod] + 1, n, xtr);
        }
        else
        {
            for(int i = 0; i < v[nod].size(); ++i)
            {
                int vecin = v[nod][i];
                if(vecin == dad)
                    continue;
                if(sts[vecin] > n/2)
                    ans = 0, ok[nod] |= ub(1, 1, n, st[vecin], dr[vecin], sts[vecin]);
            }
        }
    }
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        if(val[nod] <= n/2)
            update(1, 1, n, st[nod], val[nod], 0);
        val[nod] = n - sts[vecin];
        if(val[nod] <= n/2)
            update(1, 1, n, st[nod], val[nod], 1);
        dfs2(nod, vecin, n - sts[vecin]);
    }
    if(val[nod] != sts[nod] && val[nod] <= n/2)
        update(1, 1, n, st[nod], val[nod], 0);
    val[nod] = sts[nod];
    if(val[nod] <= n/2)
        update(1, 1, n, st[nod], val[nod], 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(0, 1);
    build(1, 1, n);
    dfs2(0, 1, 0);
    for(int i = 1; i <= n; ++i)
        cout << ok[i] << " ";
    return 0;
}
