/*
            infoarena regat(https://www.infoarena.ro/problema/regat)

    "Given a tree with n nodes and M queries of type S, find for each of the queries the jth longest path starting from Si.
j = the number of times S was already in input"

    There is one solution based on DFS order, which solves the problem in O(n log n), using segment tree and lazy propagation for updating
the lengths during the DFS

    The other solution I managed to find is a O(n sqrt n), which is running pretty fast in practice. For nodes with more than a certain amount of
queries, I implemented simple DFS, while for all other nodes I found a DP solution based on the following array: sz[i][j] = jth longest path starting
from i, with an endpoint in subtree of i. Using 2 DFS, we can process all other queries.

*/

#include<bits/stdc++.h>
#define Bucket 105
using namespace std;
ifstream f("regat.in");
ofstream g("regat.out");
int n, m;
int qu[100002], ct[100002], mmx;
vector<pair<int, int> >v[100002];
vector<int>ans[100002];
struct cmp
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};
priority_queue<int, vector<int>, cmp>q;
int dist[100002], st;
void dfsnormal(int dad, int nod)
{
    q.push(dist[nod]);
    if(q.size() > ct[qu[st]])
        q.pop();
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].first;
        int d = v[nod][i].second;
        if(vecin == dad)
            continue;
        dist[vecin] = dist[nod] + d;
        dfsnormal(nod, vecin);
    }
}
int sz[100002][Bucket], ctt[100002];
void dfsbuild(int dad, int nod)
{
    vector<int>fii, pz, dist;
    int sum = 0;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].first;
        int d = v[nod][i].second;
        if(vecin == dad)
            continue;
        dfsbuild(nod, vecin);
        fii.push_back(vecin);
        pz.push_back(ctt[vecin]);
        dist.push_back(d);
        sum += ctt[vecin];
    }
    if(v[nod].size() == 1 && nod != 1)
        ctt[nod] = 1;
    else
    {
        int bo = 0;
        if(sum <= Bucket - 2)
            bo = 1, ++sum;
        else
            sum = Bucket - 1;
        ctt[nod] = sum;
        while(sum > bo)
        {
            int mx = -1;
            int wh = -1;
            for(int i = 0; i < fii.size(); ++i)
            {
                if(pz[i] == 0)
                    continue;
                if(sz[fii[i]][pz[i]] + dist[i] > mx)
                    mx = sz[fii[i]][pz[i]] + dist[i], wh = i;
            }
            sz[nod][sum] = mx;
            --sum;
            --pz[wh];
        }
    }
}
int nn[Bucket + 1];
void dfssolve(int dad, int nod, int aa[Bucket + 1], int c)
{
    if(ct[nod] < Bucket)
    {
        if(nod == 1)
            for(int i = ctt[nod] - ct[nod] + 1; i <= ctt[nod]; ++i)
                ans[nod].push_back(sz[nod][i]);
        else
        {
            int a = c;
            int b = ctt[nod];
            for(int i = ct[nod]; i >= 1; --i)
            {
                if(aa[a] >= sz[nod][b])
                    ans[nod].push_back(aa[a]), --a;
                else
                    ans[nod].push_back(sz[nod][b]), --b;
            }
            reverse(ans[nod].begin(), ans[nod].end());
        }
    }
    vector<int>fii, pz, dist;
    int sum = 0;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].first;
        int d = v[nod][i].second;
        if(vecin == dad)
            continue;
        fii.push_back(vecin);
        pz.push_back(ctt[vecin]);
        dist.push_back(d);
        sum += ctt[vecin];
    }
    int neww[3 * Bucket + 1], org[3 * Bucket + 1], szz;
    szz = min(2 * Bucket, sum);
    int zzz = 0;
    int cc = c;
    for(int j = szz; j >= 1; --j)
    {
        int mx = -1;
        int wh = -1;
        int ppz = -1;
        for(int i = 0; i < fii.size(); ++i)
        {
            if(pz[i] == 0)
                continue;
            if(sz[fii[i]][pz[i]] + dist[i] > mx)
                mx = sz[fii[i]][pz[i]] + dist[i], wh = fii[i], ppz = i;
        }
        while(aa[cc] > mx)
            neww[++zzz] = aa[cc], org[zzz] = -1, --cc;
        neww[++zzz] = mx;
        org[zzz] = wh;
        --sum;
        --pz[ppz];
    }
    while(cc)
        neww[++zzz] = aa[cc], org[zzz] = -1, --cc;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].first;
        int d = v[nod][i].second;
        if(vecin == dad)
            continue;
        int p = 0;
        int poz = 1;
        while(poz <= zzz && p <= Bucket - 2)
        {
            while(poz <= zzz && org[poz] == vecin)
                ++poz;
            if(poz > zzz)
                break;
            nn[++p] = neww[poz] + d;
            ++poz;
        }
        if(p <= Bucket - 2)
            ++p;
        reverse(nn + 1, nn + p + 1);
        dfssolve(nod, vecin, nn, p);
    }
}
int main()
{
    f >> n >> m;
    for(int i = 1; i < n; ++i)
    {
        int a, b, c;
        f >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    for(int i = 1; i <= m; ++i)
    {
        f >> qu[i];
        ct[qu[i]]++;
    }
    for(int i = 1; i <= n; ++i)
        if(ct[i] >= Bucket)
        {
            st = i;
            dist[i] = 0;
            dfsnormal(0, i);
            while(!q.empty())
                ans[i].push_back(q.top()), q.pop();
        }
        else
            mmx = max(mmx, ct[i]);
    dfsbuild(0, 1);
    dfssolve(0, 1, nn, 1);
    for(int i = 1; i <= m; ++i)
    {
        g << ans[qu[i]].back() << '\n';
        ans[qu[i]].pop_back();
    }
    return 0;
}
