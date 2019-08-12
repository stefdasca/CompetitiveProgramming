/*
        infoarena ratway

    We have to observe that the number of edges must be even and the degree of each edge must be even.

    After we add edges between all nodes with odd degree and we add the edge (1, 1) if the number of edges
is still odd, we can find an eulerian cycle. After we find it, we will print the edges alternatively, in order
to match the given condition.


*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("ratway.in");
ofstream g("ratway.out");
int n, m, q, gr[100002];
bool pus[400002];
vector<int>ans;
vector<pair<int, int> >v[100002];
int main()
{
    f >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        int a, b;
        f >> a >> b;
        v[a].push_back({b, i});
        v[b].push_back({a, i});
        gr[a]++;
        gr[b]++;
    }
    int im = 0;
    for(int i = 1; i <= n; ++i)
        if(gr[i] % 2 == 1)
        {
            if(im)
            {
                v[im].push_back({i, m+1});
                v[i].push_back({im, m+1});
                im = 0;
                ++m;
            }
            else
                im = i;
        }
    if(m % 2 == 1)
        v[1].push_back({1, ++m});
    deque<int>d;
    d.push_back(1);
    while(!d.empty())
    {
        int nod = d.back();
        if(v[nod].empty())
        {
            d.pop_back();
            ans.push_back(nod);
            continue;
        }
        pair<int, int> z = v[nod].back();
        v[nod].pop_back();
        if(pus[z.second])
            continue;
        pus[z.second] = 1;
        d.push_back(z.first);
    }
    g << m << '\n';
    for(int i = 0; i < ans.size() - 1; ++i)
        if(i % 2 == 1)
            g << ans[i] << " " << ans[i+1] << '\n';
        else
            g << ans[i+1] << " " << ans[i] << '\n';
    return 0;
}
