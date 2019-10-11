// https://www.infoarena.ro/problema/ciclueuler

#include<bits/stdc++.h>
using namespace std;
ifstream f("ciclueuler.in");
ofstream g("ciclueuler.out");
int n, m;
bool was[500002];
vector<pair<int, int> >v[100002];
int main()
{
    f >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        int x, y;
        f >> x >> y;
        v[x].push_back({y, i});
        v[y].push_back({x, i});
    }
    for(int i = 1; i <= n; ++i)
        if((int)v[i].size() & 1)
        {
            g << -1;
            return 0;
        }
    int st = 1;
    deque<int>d;
    d.push_back(st);
    vector<int>sol;
    while(!d.empty())
    {
        int st = d.back();
        if(!v[st].size())
        {
            sol.push_back(st);
            d.pop_back();
            continue;
        }
        int a = v[st].back().first;
        int b = v[st].back().second;
        v[st].pop_back();
        if(was[b])
            continue;
        d.push_back(a);
        was[b] = 1;
    }
    sol.pop_back();
    for(int i = 0; i < sol.size(); ++i)
        g << sol[i] << " ";
    return 0;
}
