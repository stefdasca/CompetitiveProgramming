#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, m;
vector<int>v[1000002];
int deg[1000002];
int degmx[1000002];
set<pair<int, int>>s;
map<pair<int, int>, int>mp;
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
        v[b].push_back(a);
        mp[{min(a, b), max(a, b)}] = 1;
        deg[a]++;
        deg[b]++;
    }
    int edgmx = (n+m+1) / 2;
    for(int i = 1; i <= n; ++i)
    {
        degmx[i] = (deg[i] + 1) / 2;
        s.insert({deg[i], i});
    }
    while(m > edgmx && !s.empty())
    {
        pair<int, int> p = *s.rbegin();
        int nod = p.second;
        int gr = p.first;
        if(v[nod].empty())
        {
            s.erase(p);
            continue;
        }
        int nod2 = v[nod].back();
        v[nod].pop_back();
        if(mp.find({min(nod, nod2), max(nod, nod2)}) == mp.end())
            continue;
        if(deg[nod] - 1 >= degmx[nod] && deg[nod2] - 1 >= degmx[nod2])
        {
            mp.erase({min(nod, nod2), max(nod, nod2)});
            s.erase({deg[nod], nod});
            s.erase({deg[nod2], nod2});
            --deg[nod];
            --deg[nod2];
            --m;
            s.insert({deg[nod], nod});
            s.insert({deg[nod2], nod2});
        }
    }
    cout << m << '\n';
    for(map<pair<int, int>, int> ::iterator it = mp.begin(); it != mp.end(); ++it)
        cout << it -> first.first << " " << it -> first.second << '\n';
    return 0;
}
