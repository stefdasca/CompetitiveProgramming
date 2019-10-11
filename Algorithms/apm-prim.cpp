#include<bits/stdc++.h>
using namespace std;
ifstream f("apm.in");
ofstream g("apm.out");
int n, m;
vector<pair<int, int> >v[200002];
bool viz[200002], pus[200002];
set<pair<int, int> >s;
int mn[200002];
int vc[200002];
int q, sum;
pair<int, int> ans[200002];
int main()
{
    f >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        int a, b, c;
        f >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    s.insert({0, 1});
    viz[1] = 1;
    for(int i = 1; i <= n; ++i)
    {
        pair<int, int> p = *s.begin();
        s.erase(p);
        swap(p.first, p.second);
        pus[p.first] = 1;
        if(i >= 2)
        {
            ans[++q] = make_pair(vc[p.first], p.first);
            sum += mn[p.first];
        }
        for(int j = 0; j < v[p.first].size(); ++j)
        {
            int vecin = v[p.first][j].first;
            int cost = v[p.first][j].second;
            if(pus[vecin])
                continue;
            if(!viz[vecin] || cost < mn[vecin])
            {
                if(!viz[vecin])
                    s.insert({cost, vecin});
                else
                {
                    s.erase({mn[vecin], vecin});
                    s.insert({cost, vecin});
                }
                viz[vecin] = 1;
                mn[vecin] = cost;
                vc[vecin] = p.first;
            }
        }
    }
    g << sum << '\n';
    g << n-1 << '\n';
    for(int i = 1; i <= q; ++i)
        g << ans[i].first << " " << ans[i].second << '\n';
    return 0;
}
