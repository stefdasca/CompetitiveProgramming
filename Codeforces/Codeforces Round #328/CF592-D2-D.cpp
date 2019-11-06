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

int n, m;

ll dp[150002];
int lpath[150002], good[150002];
int oras;
ll mincost = (1LL<<60);

bool oki[150002];
vector<int> v[150002];

void dfs(int dad, int nod)
{
    lpath[nod] = -1;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        dfs(nod, vecin);
        if(lpath[vecin] != -1)
        {
            lpath[nod] = max(lpath[nod], lpath[vecin] + 1);
            dp[nod] += dp[vecin] + 2;
        }
    }
    if(oki[nod])
        lpath[nod] = max(lpath[nod], 0);
}
void dfs2(int dad, int nod, ll sm, int mxpth)
{
    if(nod == 1)
    {
        oras = 1;
        mincost = dp[1] - lpath[1];
    }
    else
    {
        ll trycost = sm + dp[nod] - max(lpath[nod], mxpth);
        if(trycost < mincost)
            mincost = trycost, oras = nod;
        else
             if(trycost == mincost && oras > nod)
                 mincost = trycost, oras = nod;
    }
    vector<pair<int, int> >vx;
    vector<ll> sp;
    if(mxpth != 0)
        vx.pb({mxpth, 0});
    else
        if(oki[nod])
            vx.pb({0, 0});
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        if(lpath[vecin] == -1)
            continue;
        vx.pb({lpath[vecin] + 1, vecin});
    }
    sort(vx.begin(), vx.end());
    sp.resize(vx.size());
    for(int i = 0; i < vx.size(); ++i)
    {
        if(i == 0)
            sp[i] = vx[i].fi;
        else
            sp[i] = sp[i-1] + vx[i].fi;
    }
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        if(lpath[vecin] == -1)
            continue;
        ll mxpath = 0, summ = sm + dp[nod] - dp[vecin] - 2;
        if(vx[vx.size() - 1].se == vecin)
        {
            if(vx.size() == 1)
            {
                if(mxpth != 0)
                    summ += 2;
            }
            else
                mxpath = vx[vx.size() - 2].fi + 1, summ += 2;
        }
        else
            mxpath = vx[vx.size() - 1].fi + 1, summ += 2;
        dfs2(nod, vecin, summ, mxpath);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    for(int i = 1; i <= m; ++i)
    {
        int nr;
        cin >> nr;
        oki[nr] = 1;
    }
    dfs(0, 1);
    dfs2(0, 1, 0, 0);
    cout << oras << '\n';
    cout << mincost << '\n';
    return 0;
}

