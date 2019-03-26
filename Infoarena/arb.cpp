#include<bits/stdc++.h>
using namespace std;
ifstream f("arb.in");
ofstream g("arb.out");
int n, m;
int nr[250002], st[250002], sf[250002], vt[250002], poz, lvl[250002];
struct query
{
    int pz, lvls, pi;
};
query q[500002];
bool cmp2(query a, query b)
{
    return a.lvls > b.lvls;
}
struct nodd
{
    int wh;
    int lvl;
};
nodd vv[250002];
bool cmp1(nodd a, nodd b)
{
    return a.lvl < b.lvl;
}
vector<int>v[250002];
void dfs(int nod)
{
    ++poz;
    st[nod] = poz;
    vt[poz] = nr[nod];
    vv[poz] = {poz, lvl[nod]};
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        lvl[vecin] = lvl[nod] + 1;
        dfs(vecin);
    }
    sf[nod] = poz;
}
int aint[1000002];
void update(int nod, int L, int R, int poz, int val)
{
    if(L == R)
    {
        aint[nod] += val;
        return;
    }
    int mid = (L + R) / 2;
    if(poz <= mid)
        update(nod << 1, L, mid, poz, val);
    else
        update(nod << 1|1, mid + 1, R, poz, val);
    aint[nod] = aint[nod << 1] + aint[nod << 1|1];
}
int query(int nod, int L, int R, int st, int dr)
{
    if(R < st || L > dr)
        return 0;
    if(st <= L && R <= dr)
        return aint[nod];
    int mid = (L + R) / 2;
    return (query(nod << 1, L, mid, st, dr) + query(nod << 1|1, mid + 1, R, st, dr));
}
int ans[500002];
int main()
{
    f >> n;
    for(int i = 1; i <= n; ++i)
        f >> nr[i];
    for(int i = 2; i <= n; ++i)
    {
        int x;
        f >> x;
        v[x].push_back(i);
    }
    dfs(1);
    for(int i = 1; i <= n; ++i)
        update(1, 1, n, i, vt[i]);
    sort(vv + 1, vv + n + 1, cmp1);
    f >> m;
    for(int i = 1; i <= m; ++i)
    {
        f >> q[i].pz >> q[i].lvls;
        q[i].pi = i;
        q[i].lvls += lvl[q[i].pz];
    }
    sort(q + 1, q + m + 1, cmp2);
    int pp = n;
    for(int i = 1; i <= m; ++i)
    {
        while(pp && vv[pp].lvl > q[i].lvls)
        {
            update(1, 1, n, vv[pp].wh, -vt[vv[pp].wh]);
            --pp;
        }
        ans[q[i].pi] = query(1, 1, n, st[q[i].pz], sf[q[i].pz]);
    }
    for(int i = 1; i <= m; ++i)
        g << ans[i] << '\n';
    return 0;
}
