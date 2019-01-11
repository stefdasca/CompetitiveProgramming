#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
int val[200002];
vector<int>prime[200002];
bool pr[200002];
vector<int>dv[200002];
void ciur()
{
    for(int i = 2; i <= 200000; i++)
        if(!pr[i])
            for(int j = i; j <= 200000; j += i)
                prime[j].push_back(i), pr[j] = 1;
}
vector<pair<int, int> >v[200002];
vector<int>fip[200002];
bool viz[200002];
int faway, dmax;
int ans = 0;
void dfs(int divisor, int dad, int nod, int dd)
{
    int b = 0;
    int e = v[nod].size() - 1;
    int anss = 0;
    bool gg = 0;
    viz[nod] = 1;
    while(b <= e)
    {
        int mid = (b + e) / 2;
        if(v[nod][mid].first >= divisor)
            gg = 1, anss = mid, e = mid - 1;
        else
            b = mid + 1;
    }
    if(dd > dmax)
        dmax = dd, faway = nod;
    ans = max(ans, dd);
    if(gg == 0)
        return;
    for(int i = anss; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].second;
        int dv = v[nod][i].first;
        if(dv > divisor)
            break;
        if(vecin == dad)
            continue;
        dfs(divisor, nod, vecin, dd + 1);
    }
}
void dfs2(int divisor, int dad, int nod, int dd)
{
    int b = 0;
    int e = v[nod].size() - 1;
    int anss = 0;
    bool gg = 0;
    while(b <= e)
    {
        int mid = (b + e) / 2;
        if(v[nod][mid].first >= divisor)
            gg = 1, anss = mid, e = mid - 1;
        else
            b = mid + 1;
    }
    ans = max(ans, dd);
    if(gg == 0)
        return;
    for(int i = anss; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].second;
        int dv = v[nod][i].first;
        if(dv > divisor)
            break;
        if(vecin == dad)
            continue;
        dfs2(divisor, nod, vecin, dd + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    ciur();
    for(int i = 1; i <= n; ++i)
    {
        cin >> val[i];
        for(int j = 0; j < prime[val[i]].size(); ++j)
        {
            int nrprim = prime[val[i]][j];
            dv[i].push_back(nrprim), fip[nrprim].push_back(i);
        }
    }
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        for(int j = 0; j < dv[a].size(); ++j)
            if(val[b] % dv[a][j] == 0)
                v[a].push_back({dv[a][j], b});
        for(int j = 0; j < dv[b].size(); ++j)
            if(val[a] % dv[b][j] == 0)
                v[b].push_back({dv[b][j], a});
    }
    for(int i = 1; i <= n; ++i)
        sort(v[i].begin(), v[i].end());
    for(int i = 2; i <= 200000; ++i)
    {
        for(int j = 0; j < fip[i-1].size(); ++j)
            viz[fip[i-1][j]] = 0;
        for(int j = 0; j < fip[i].size(); ++j)
        {
            int root = fip[i][j];
            if(!viz[root])
            {
                faway = 0;
                dmax = 0;
                dfs(i, 0, root, 1);
                dfs2(i, 0, faway, 1);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}

