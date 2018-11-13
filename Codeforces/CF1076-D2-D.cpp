/// Never do the same mistake twice

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, m, k;
vector<pair<int, int> >v[300002];
int fw[300002];
bool viz[300002];
long long shp[300002];
int sz = 0;
map<pair<int, int>, int>mp;
bool gg[300002];
bool was[300002];
struct cmp
{
    bool operator()(int a, int b)
    {
        return shp[a] > shp[b];
    }
};
priority_queue<pair<long long, int>, vector<pair<long long, int> > > q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
        mp[{a, b}] = i;
        mp[{b, a}] = i;
    }
    q.push(make_pair(shp[1], 1));
    viz[1] = 1;
    while(!q.empty())
    {
        int nod = q.top().second;
        q.pop();
        if(was[nod])
            continue;
        if(fw[nod] && sz < k)
            gg[mp[{nod, fw[nod]}]] = 1, ++sz;
        was[nod] = 1;
        for(int i = 0; i < v[nod].size(); ++i)
        {
            int zq = v[nod][i].first;
            int p = v[nod][i].second;
            if(!viz[zq] || shp[nod] + p < shp[zq])
            {
                shp[zq] = shp[nod] + p;
                viz[zq] = 1;
                fw[zq] = nod;
                q.push(make_pair(-shp[zq], zq));
            }
        }
    }
    cout << sz << '\n';
    for(int i = 1; i <= m; ++i)
        if(gg[i])
            cout << i << " ";
    return 0;
}
