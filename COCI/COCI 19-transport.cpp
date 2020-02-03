/*
        COCI 19-transport

    detailed solution + implementation hints: https://github.com/thecodingwizard/competitive-programming/blob/master/COCI/COCI%2019-transport.cpp

*/
#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second

using namespace std;
typedef long long ll;

int n, gas[100002];
vector<pair<int, int> > v[100002];
ll ans;

int costid[100002];
ll aib[100005];
void upd(int nod, int val, int sz)
{
    for(; nod <= sz; nod += (nod & (-nod)))
        aib[nod] += val;
}
ll compute(int nod)
{
    ll ans = 0;
    for(; nod; nod -= (nod & (-nod)))
        ans += aib[nod];
    return ans;
}

bool block[100002];
int sts[100002];
ll distup[100002], distdown[100002];

void dfs_size(int dad, int nod)
{
    sts[nod] = 1;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].fi;
        if(vecin == dad || block[vecin])
            continue;
        dfs_size(nod, vecin);
        sts[nod] += sts[vecin];
    }
}
int dfs_center(int dad, int nod, int big_size)
{
    int max_size = 0;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].fi;
        if(vecin == dad || block[vecin])
            continue;
        if(sts[vecin] > big_size / 2)
            return dfs_center(nod, vecin, big_size);
    }
    return nod;
}
vector<pair<ll, int> > ord;
void dfs_down(int dad, int nod, ll worst, ll tot)
{
    ord.pb({worst, nod});
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].fi;
        if(vecin == dad || block[vecin])
            continue;
        dfs_down(nod, vecin, min(worst, tot + gas[nod] - v[nod][i].se), tot + gas[nod] - v[nod][i].se);
    }
}
vector<ll>ord_up;
void dfs_up(int dad, int nod, ll worst, ll tot)
{
    if(worst >= 0)
        ord_up.pb(tot);
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].fi;
        if(vecin == dad || block[vecin])
            continue;
        dfs_up(nod, vecin, min(0LL + gas[vecin] - v[nod][i].se, worst + gas[vecin] - v[nod][i].se), tot + gas[vecin] - v[nod][i].se);
    }
}
void find_center(int rad)
{
    ord.clear();
    ord_up.clear();
    dfs_size(0, rad);
    int centru = dfs_center(0, rad, sts[rad]);
    block[centru] = 1;
    for(int i = 0; i < v[centru].size(); ++i)
    {
        int vecin = v[centru][i].fi;
        if(block[vecin])
            continue;
        dfs_down(centru, vecin, gas[centru] - v[centru][i].se, gas[centru] - v[centru][i].se);
    }
    for(int i = 0; i < ord.size(); ++i)
        if(ord[i].fi >= 0)
            ++ans;
    sort(ord.begin(), ord.end());

    int N = ord.size() + 1;
    vector<pair<ll, int> >ord_centroid_down = ord;
    for(int i = 0; i <= N; ++i)
        aib[i] = 0;
    for(int i = 0; i < ord_centroid_down.size(); ++i)
    {
        costid[ord_centroid_down[i].se] = i+1;
        upd(i+1, 1, N);
    }
    for(int i = 0; i < v[centru].size(); ++i)
    {
        int vecin = v[centru][i].fi;
        if(block[vecin])
            continue;
        ord.clear();
        dfs_down(centru, vecin, gas[centru] - v[centru][i].se, gas[centru] - v[centru][i].se);
        for(int j = 0; j < ord.size(); ++j)
            upd(costid[ord[j].se], -1, N);
        dfs_up(centru, vecin, gas[vecin] - v[centru][i].se, gas[vecin] - v[centru][i].se);
        for(int j = 0; j < ord_up.size(); ++j)
        {
            ll cost = ord_up[j];
            auto it = lower_bound(ord_centroid_down.begin(), ord_centroid_down.end(), make_pair(-cost, -1));
            if (it != ord_centroid_down.end())
                ans += compute(N) - compute(costid[it -> se] - 1);
            if(cost >= 0)
                ++ans;
        }
        ord_up.clear();
        for(int j = 0; j < ord.size(); ++j)
            upd(costid[ord[j].se], 1, N);
    }
    ord.clear();
    for(int i = 0; i < v[centru].size(); ++i)
    {
        int vecin = v[centru][i].fi;
        if(!block[vecin])
            find_center(vecin);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> gas[i];
    for(int i = 1; i < n; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].pb({b, c});
        v[b].pb({a, c});
    }
    find_center(1);
    cout << ans;
    return 0;
}
