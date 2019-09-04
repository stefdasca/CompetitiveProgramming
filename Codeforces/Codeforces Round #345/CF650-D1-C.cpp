#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

int n, m, pz;

vector<vector<int> >mat, ans;
vector<int> mex, wh, mexc, wh2;
vector<pair<int, int> >po;

struct BFR
{
    int L, C, val;
};
BFR v[1000002];
bool cmp(BFR a, BFR b)
{
    return a.val < b.val;
}
vector<int> col[1000002], lin[1000002];
void proc()
{
    for(int j = 0; j < po.size(); ++j)
    {
        int i = po[j].se;
        po[j].fi = max(mex[v[i].L] + (wh[v[i].L] < v[i].val), mexc[v[i].C] + (wh2[v[i].C] < v[i].val));
    }
    sort(po.begin(), po.end());
    for(int qx = po.size() - 1; qx >= 0; --qx)
    {
        int i = po[qx].se;
        if(lin[v[i].L].empty() || col[v[i].C].empty())
            continue;
        queue<pair<int, int> >q;
        q.push({v[i].L, v[i].C});
        int nnr = max(mex[v[i].L] + (wh[v[i].L] < v[i].val), mexc[v[i].C] + (wh2[v[i].C] < v[i].val));
        while(!q.empty())
        {
            pair<int, int> pz = q.front();
            mex[pz.fi] = mexc[pz.se] = nnr;
            wh[pz.fi] = wh2[pz.se] = v[i].val;
            ans[pz.fi][pz.se] = nnr;
            q.pop();
            while(!lin[pz.fi].empty())
            {
                q.push({pz.fi, lin[pz.fi].back()});
                lin[pz.fi].pop_back();
            }
            while(!col[pz.se].empty())
            {
                q.push({col[pz.se].back(), pz.se});
                col[pz.se].pop_back();
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    mex.resize(n+2); wh.resize(n+2);
    mexc.resize(m+2); wh2.resize(m+2);
    for(int i = 1; i <= n; ++i)
    {
        vector<int>ta;
        for(int j = 1; j <= m; ++j)
        {
            int nr;
            cin >> nr;
            ta.pb(nr);
            v[++pz] = {i - 1, j - 1, nr};
        }
        mat.pb(ta);
        ans.pb(ta);
    }
    sort(v+1, v+pz+1, cmp);
    for(int i = 1; i <= pz; ++i)
    {
        if(v[i].val > v[i-1].val && i)
            proc(), po.clear();
        lin[v[i].L].pb(v[i].C);
        col[v[i].C].pb(v[i].L);
        po.pb({-1, i});
    }
    proc();
    for(int i = 0; i < n; cout << '\n', ++i)
        for(int j = 0; j < m; ++j)
            cout << ans[i][j] << " ";
    return 0;
}
