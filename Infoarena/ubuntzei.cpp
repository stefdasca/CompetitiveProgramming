#include<bits/stdc++.h>
using namespace std;
ifstream f("ubuntzei.in");
ofstream g("ubuntzei.out");
int n, m, k;
vector<pair<int, int> >v[2002];
int shp[2002][2002];
int dp[(1<<16)][16];
int arr[16];
bool viz[2002];
int curr;
struct cmp
{
    bool operator()(int a, int b)
    {
        return shp[curr][a] > shp[curr][b];
    }
};
priority_queue<int, vector<int>, cmp>q;
bool was[2002];
void dijk(int nr)
{
    memset(viz, 0, sizeof(viz));
    memset(was, 0, sizeof(was));
    viz[nr] = 1;
    q.push(nr);
    while(!q.empty())
    {
        int nod = q.top();
        q.pop();
        if(was[nod])
            continue;
        was[nod] = 1;
        for(int i = 0; i < v[nod].size(); ++i)
        {
            int aa = v[nod][i].first;
            int bb = v[nod][i].second;
            if(!viz[aa] || shp[curr][aa] > shp[curr][nod] + bb)
            {
                shp[curr][aa] = shp[curr][nod] + bb;
                shp[aa][curr] = shp[curr][aa];
                viz[aa] = 1;
                q.push(aa);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    f >> n >> m;
    f >> k;
    for(int j = 0; j < k; ++j)
        f >> arr[j];
    for(int i = 1; i <= m; ++i)
    {
        int a, b, c;
        f >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    for(int i = 0; i < k; ++i)
        curr = arr[i], dijk(arr[i]);
    curr = 1, dijk(1);
    if(k == 0)
    {
        g << shp[1][n] << '\n';
        return 0;
    }
    int sol = (1<<28);
    for(int i = 0; i < (1<<k); ++i)
    {
        if(i == 0)
        {
            for(int j = 0; j < k; ++j)
                dp[(1<<j)][j] = shp[1][arr[j]];
            continue;
        }
        if(i == (1<<k) - 1)
        {
            for(int j = 0; j < k; ++j)
                if(dp[i][j] != 0)
                    sol = min(sol, dp[i][j] + shp[arr[j]][n]);
            continue;
        }
        for(int j = 0; j < k; ++j)
        {
            if(!dp[i][j])
                continue;
            for(int pp = 0; pp < k; ++pp)
            {
                if(i & (1<<pp))
                    continue;
                if(!dp[i + (1<<pp)][pp])
                    dp[i + (1<<pp)][pp] = dp[i][j] + shp[arr[j]][arr[pp]];
                else
                    dp[i + (1<<pp)][pp] = min(dp[i + (1<<pp)][pp], dp[i][j] + shp[arr[j]][arr[pp]]);
            }
        }
    }
    g << sol;
    return 0;
}
