#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, r, q;
int val[100002];
vector<pair<int, int> >aint[400002];
vector<int>pmin[400002];
vector<int>tree[100002];
int poz[100002], stt[100002], sff[100002], m, lvl[100002];
void dfs(int dad, int nod)
{
    ++m;
    poz[m] = nod;
    stt[nod] = m;
    for(int i = 0; i < tree[nod].size(); ++i)
    {
        int vecin = tree[nod][i];
        if(vecin == dad)
            continue;
        lvl[vecin] = lvl[nod] + 1;
        dfs(nod, vecin);
    }
    sff[nod] = m;
}
void build(int nod, int st, int dr)
{
    if(st == dr)
    {
        aint[nod].push_back({lvl[poz[st]], val[poz[st]]});
        pmin[nod].push_back(val[poz[st]]);
        return;
    }
    int mid = (st + dr) / 2;
    build(nod << 1, st, mid);
    build(nod << 1|1, mid+1, dr);
    for(int i = 0; i < aint[nod << 1].size(); ++i)
        aint[nod].push_back(aint[nod << 1][i]), pmin[nod].push_back(0);
    for(int i = 0; i < aint[nod << 1|1].size(); ++i)
        aint[nod].push_back(aint[nod << 1|1][i]), pmin[nod].push_back(0);
    sort(aint[nod].begin(), aint[nod].end());
    for(int i = 0; i < aint[nod].size(); ++i)
    {
        pmin[nod][i] = aint[nod][i].second;
        if(i)
            pmin[nod][i] = min(pmin[nod][i], pmin[nod][i-1]);
    }
}
int last;
int cb(int wh, int lvlmax)
{
    int st = 0;
    int dr = aint[wh].size() - 1;
    int mn = (1<<30);
    while(st <= dr)
    {
        int mid = (st + dr) / 2;
        if(aint[wh][mid].first <= lvlmax)
            mn = min(mn, pmin[wh][mid]), st = mid + 1;
        else
            dr = mid - 1;
    }
    return mn;
}
void query(int nod, int st, int dr, int L, int R, int lvlmax)
{
    if(dr < L || st > R)
        return;
    if(L <= st && dr <= R)
    {
        last = min(last, cb(nod, lvlmax));
        return;
    }
    int mid = (st + dr) / 2;
    query(nod << 1, st, mid, L, R, lvlmax);
    query(nod << 1|1, mid+1, dr, L, R, lvlmax);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> r;
    for(int i = 1; i <= n; ++i)
        cin >> val[i];
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(0, r);
    build(1, 1, n);
    cin >> q;
    for(int i = 1; i <= q; ++i)
    {
        int pi, qi;
        cin >> pi >> qi;
        pi = (pi + last) % n + 1;
        qi = (qi + last) % n;
        last = (1<<30);
        query(1, 1, n, stt[pi], sff[pi], qi + lvl[pi]);
        cout << last << '\n';
    }
    return 0;
}

