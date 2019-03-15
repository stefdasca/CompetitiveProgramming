#include<bits/stdc++.h>
using namespace std;
ifstream f("posta2.in");
ofstream g("posta2.out");
int n, m, tax[100002], subtree[100002];
long long nr[100002], ans1, ans2, mn;
bool gg[100002];
vector<pair<int, int> >v[100002];
void dfs(int dad, int nod)
{
    subtree[nod] = gg[nod];
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].first;
        if(vecin == dad)
            continue;
        dfs(nod, vecin);
        if(subtree[vecin])
            ans1 += v[nod][i].second, ++nr[nod];
        subtree[nod] += subtree[vecin];
    }
    if(subtree[nod])
        ++nr[nod];
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
    for(int i = 1; i <= n; ++i)
        f >> tax[i];
    for(int i = 1; i <= m; ++i)
    {
        int b;
        f >> b;
        gg[b] = 1;
    }
    dfs(0, 1);
    ans1 *= 2;
    mn = (1LL<<60);
    --nr[1];
    long long md = 0;
    for(int i = 1; i <= n; ++i)
        if(nr[i])
            md += (nr[i] - 1) * tax[i];
    for(int i = 1; i <= n; ++i)
    {
        if(!nr[i])
            continue;
        md -= (nr[i] - 1) * tax[i];
        mn = min(mn, ans1 + md);
        md += (nr[i] - 1) * tax[i];
    }
    g << mn << '\n';
    return 0;
}
