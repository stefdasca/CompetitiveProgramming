/*
        POI 11-pro

    We are going to greedily match the problems with the people, as long as this is possible. Since the given graph
is bipartite, we can run an algorithm similar to max matching in bipartite graph, which is polynomial and good enough
for this task.

*/
#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define dancila 3.14159265359
#define eps 1e-9

// #define fisier 1

using namespace std;

typedef long long ll;

int n, m, r, t, k, cnt;

bool bad[502];

int st[502], dr[502], ok[502], solvedcount[502];

vector<int> v[502];

bool dfs(int nod)
{
    if(st[nod] == cnt)
        return 0;
    st[nod] = cnt;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(dr[vecin] == cnt)
            continue;
        dr[vecin] = cnt;
        if(!ok[vecin] || dfs(ok[vecin]))
        {
            ok[vecin] = nod;
            return 1;
        }
    }
    return 0;
}
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> r >> t >> k;
    for(int i = 1; i <= k; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
    }
    int solved = 0, penalty = 0;
    for(int i = 1; i <= m && i * r <= t; ++i)
        for(int j = 1; j <= n; ++j)
        {
            if(bad[j])
                continue;
            ++cnt;
            if(dfs(j))
            {
                penalty += i * r;
                ++solved;
            }
            else
                bad[j] = 1;
        }
    cout << solved << " " << penalty << '\n';
    for(int i = 1; i <= m; ++i)
        if(ok[i])
        {
            cout << ok[i] << " " << i << " " << r * solvedcount[ok[i]] << '\n';
            ++solvedcount[ok[i]];
        }
    return 0;
}
