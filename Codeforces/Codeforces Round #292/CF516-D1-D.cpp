#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

typedef long long ll;
int n, root = 1, q;
vector<pair<int, int> >v[100002];
ll subdist[100002], nodes[100002];
int st[100002], dr[100002], m;
void dfs(int dad, int nod)
{
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].first;
        if(vecin == dad)
            continue;
        dfs(nod, vecin);
        subdist[nod] = max(subdist[nod], subdist[vecin] + v[nod][i].second);
    }
}
ll wh;
void dfs2(int dad, int nod, ll dist)
{
    vector<pair<ll, int> >d;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].first;
        if(vecin == dad)
            continue;
        d.push_back({subdist[vecin] + v[nod][i].second, vecin});
    }
    sort(d.begin(), d.end());
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].first;
        if(vecin == dad)
            continue;
        ll mxx = dist;
        if(d.back().second == vecin)
        {
            if(d.size() > 1)
                mxx = max(mxx, d[d.size() - 2].first);
        }
        else
            mxx = max(mxx, d.back().first);
        if(mxx == 0 && v[nod].size() != 1)
            dfs2(nod, vecin, mxx);
        else
            dfs2(nod, vecin, mxx + v[nod][i].second);
    }
    subdist[nod] = max(subdist[nod], dist);
    if(wh == 0)
        wh = nod;
    else
        if(subdist[nod] < subdist[wh])
            wh = nod;
}
void dfs3(int dad, int nod)
{
    ++m;
    st[nod] = m;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].first;
        if(vecin == dad)
            continue;
        dfs3(nod, vecin);
    }
    dr[nod] = m;
}
int aib[100002];
void update(int nod, int val)
{
    for(; nod <= n; nod += (nod & (-nod)))
        aib[nod] += val;
}
int compute(int nod)
{
    int s = 0;
    for(; nod; nod -= (nod & (-nod)))
        s += aib[nod];
    return s;
}
bool cmp(int a, int b)
{
    if(subdist[a] == subdist[b])
        return st[a] < st[b];
    return subdist[a] < subdist[b];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        nodes[i] = i;
    for(int i = 1; i < n; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    for(int i = 1; i <= n; ++i)
        if(v[i].size() > 1)
        {
            root = i;
            break;
        }
    dfs(0, root);
    dfs2(0, root, 0);
    root = wh;
    dfs3(0, root);
    sort(nodes + 1, nodes + n + 1, cmp);
    cin >> q;
    for(int i = 1; i <= q; ++i)
    {
        ll x;
        cin >> x;
        memset(aib, 0, sizeof(aib));
        int stt = 1;
        int drr = 1;
        int ans = 0;
        while(stt <= n)
        {
            while(drr <= n && subdist[nodes[drr]] - subdist[nodes[stt]] <= x)
                update(st[nodes[drr]], 1), ++drr;
            ans = max(ans, compute(dr[nodes[stt]]) - compute(st[nodes[stt]] - 1));
            update(st[nodes[stt]], -1);
            ++stt;
        }
        cout << ans << '\n';
    }
    return 0;
}
