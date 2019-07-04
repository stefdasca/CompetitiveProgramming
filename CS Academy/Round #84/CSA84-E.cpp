#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

typedef long long ll;

int n, d;
struct str
{
    int vecin;
    int cost;
    int vari;
};
vector<str>v[250002];
ll wh, mx;
ll mxd[250002];
void dfs(int d, int dad, int nod)
{
    mxd[nod] = 0;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].vecin;
        if(vecin == dad)
            continue;
        ll cost = 1LL * v[nod][i].cost + 1LL * v[nod][i].vari * d;
        dfs(d, nod, vecin);
        mxd[nod] = max(mxd[nod], max(cost, mxd[vecin] + cost));
    }
    mx = max(mx, mxd[nod]);
}
void dfs2(int d, int dad, int nod, ll dist)
{
    mx = max(mx, max(dist + mxd[nod], dist));
    ll mx1 = 0, mx2 = 0;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].vecin;
        if(vecin == dad)
            continue;
        ll cost = 1LL * v[nod][i].cost + 1LL * v[nod][i].vari * d;
        ll vl = max(cost + mxd[vecin], cost);
        if(vl > mx1)
            mx2 = mx1, mx1 = vl;
        else
            if(vl > mx2)
                mx2 = vl;
    }
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].vecin;
        if(vecin == dad)
            continue;
        ll cost = 1LL * v[nod][i].cost + 1LL * v[nod][i].vari * d;
        ll val = max(cost + mxd[vecin], cost);
        ll nxt = max(dist + cost, cost);
        if(mx1 == val)
            nxt = max(nxt, cost + mx2);
        else
            nxt = max(nxt, cost + mx1);
        dfs2(d, nod, vecin, nxt);
    }
}
ll diametru(int d)
{
    mx = 0;
    dfs(d, 0, 1);
    dfs2(d, 0, 1, 0);
    return mx;
}
int cb()
{
    int st = 0;
    int dr = d;
    ll val = diametru(0);
    while(st < dr)
    {
        int mid = (st + dr) / 2;
        ll a = diametru(mid);
        ll b = diametru(mid + 1);
        if(a <= b)
            dr = mid;
        else
            st = mid+1;
    }
    return st;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> d;
    for(int i = 1; i < n; ++i)
    {
        int s, e, c, vi;
        cin >> s >> e >> c >> vi;
        v[s].push_back({e, c, vi});
        v[e].push_back({s, c, vi});
    }
    int ans = cb();
    cout << ans << '\n';
    cout << diametru(ans);
    return 0;
}

