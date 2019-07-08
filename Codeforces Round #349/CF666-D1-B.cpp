#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

typedef long long ll;
vector<int>v[3002], tr[3002];
int n, m;
int dist[3002][3002], rdist[3002][3002];
int bst[5][3002], rbst[5][3002];
bool viz[5002];
void bfs(int st)
{
    deque<pair<int, int> >d;
    d.push_back({st, 0});
    memset(viz, 0, sizeof(viz));
    viz[st] = 1;
    while(!d.empty())
    {
        int nod = d[0].first;
        int di = d[0].second;
        d.pop_front();
        if(nod != st)
        {
            dist[st][nod] = di;
            for(int i = 1; i <= 3; ++i)
            {
                if(di > dist[st][bst[i][st]])
                {
                    for(int j = 3; j > i; --j)
                        bst[j][st] = bst[j-1][st];
                    bst[i][st] = nod;
                    break;
                }
            }
        }
        for(int i = 0; i < v[nod].size(); ++i)
        {
            int vecin = v[nod][i];
            if(viz[vecin])
                continue;
            d.push_back({vecin, di+1});
            viz[vecin] = 1;
        }
    }
}
void rbfs(int st)
{
    deque<pair<int, int> >d;
    d.push_back({st, 0});
    memset(viz, 0, sizeof(viz));
    viz[st] = 1;
    while(!d.empty())
    {
        int nod = d[0].first;
        int di = d[0].second;
        d.pop_front();
        if(nod != st)
        {
            rdist[st][nod] = di;
            for(int i = 1; i <= 3; ++i)
            {
                if(di > rdist[st][bst[i][st]])
                {
                    for(int j = 3; j > i; --j)
                        rbst[j][st] = rbst[j-1][st];
                    rbst[i][st] = nod;
                    break;
                }
            }
        }
        for(int i = 0; i < tr[nod].size(); ++i)
        {
            int vecin = tr[nod][i];
            if(viz[vecin])
                continue;
            d.push_back({vecin, di+1});
            viz[vecin] = 1;
        }
    }
}
vector<int>sol;
int aaa = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        tr[b].push_back(a);
    }
    for(int i = 1; i <= n; ++i)
        bfs(i), rbfs(i);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
        {
            if(i == j)
                continue;
            if(dist[i][j] == 0)
                continue;
            for(int x = 1; x <= 3; ++x)
            {
                if(rbst[x][i] == 0 || rbst[x][i] == j || rbst[x][i] == i)
                    continue;
                for(int y = 1; y <= 3; ++y)
                {
                    if(bst[y][j] == 0 || bst[y][j] == i || bst[y][j] == j || bst[y][j] == rbst[x][i])
                        continue;
                    int oofz = dist[rbst[x][i]][i] + dist[i][j] + dist[j][bst[y][j]];
                    if(oofz > aaa)
                    {
                        aaa = oofz;
                        sol.clear();
                        sol.push_back(rbst[x][i]); sol.push_back(i);
                        sol.push_back(j); sol.push_back(bst[y][j]);
                    }
                }
            }
        }
    for(int i = 0; i < sol.size(); ++i)
        cout << sol[i] << " ";
    return 0;
}
