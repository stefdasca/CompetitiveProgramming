/// leader of NumaNumaTei

#include<bits/stdc++.h>
using namespace std;
ifstream f("omizi.in");
ofstream g("omizi.out");
int n, m;
int pos[20002], is[20002], sol[20002], tt[16002], gr[16002];
int st[16002], sf[16002], pp, aa[16002], ans[16002];
int aint[100002];
vector<int>v[16002];
int frunze[16002];
void init()
{
    f >> n >> m;
    int i = 1;
    while(i <= n)
    {
        int nr;
        f >> nr;
        if(nr == 0)
            ++i;
        else
            v[i].push_back(nr), tt[nr] = i, gr[i]++;
    }
    for(int i = 1; i <= m; ++i)
    {
        int a;
        char b;
        f >> a >> b;
        pos[i] = a;
        if(b == 'S')
            is[a] = 1;
        else
            is[a] = 2;
    }
}
void dfs(int nod)
{
    frunze[nod] = 1;
    aa[++pp] = nod;
    st[nod] = pp;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        frunze[nod] = 0;
        int vecin = v[nod][i];
        dfs(vecin);
    }
    sf[nod] = pp;
}
void build(int nod, int st, int dr)
{
    if(st == dr)
    {
        aint[nod] = frunze[aa[st]];
        return;
    }
    int mid = (st + dr) / 2;
    build(nod << 1, st, mid);
    build(nod << 1|1, mid+1, dr);
    aint[nod] = aint[nod << 1] + aint[nod << 1 | 1];
}
int query(int nod, int st, int dr, int x, int y, int care)
{
    if(dr < x || st > y)
        return 0;
    if(aint[nod] == 0)
        return 0;
    if(st == dr)
        return aa[st];
    int mid = (st + dr)/2;
    if(is[care] == 1)
    {
        int ans = query(nod << 1, st, mid, x, y, care);
        if(ans == 0)
            ans = query(nod << 1|1, mid+1, dr, x, y, care);
        return ans;
    }
    else
    {
        int ans = query(nod << 1|1, mid+1, dr, x, y, care);
        if(ans == 0)
            ans = query(nod << 1, st, mid, x, y, care);
        return ans;
    }
}
void update(int nod, int st, int dr, int aa, int cat)
{
    if(st == dr)
    {
        aint[nod] += cat;
        return;
    }
    int mid = (st + dr)/2;
    if(aa <= mid)
        update(nod << 1, st, mid, aa, cat);
    else
        update(nod << 1|1, mid+1, dr, aa, cat);
    aint[nod] = aint[nod << 1] + aint[nod << 1 | 1];
}
void dfs2(int nod)
{
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        dfs2(vecin);
    }
    if(is[nod])
    {
        int sol = query(1, 1, n, st[nod], sf[nod], nod);
        ans[nod] = sol;
        update(1, 1, n, st[sol], -1);
        --gr[tt[sol]];
        if(gr[tt[sol]] == 0)
            update(1, 1, n, st[tt[sol]], 1);
    }
}
int main()
{
    init();
    dfs(1);
    build(1, 1, n);
    dfs2(1);
    for(int i = 1; i <= m; ++i)
        g << ans[pos[i]] << '\n';
    return 0;
}
