/*
        infoarena posta2(https://infoarena.ro/problema/posta2)
   
   "Given a tree with n nodes, where each edge has a cost and each vertex has a cost which is paid every time when one visits that city,
find the best place to place the HQ of a post company, which has to sent mails to M cities. The post company will have to pay no tax for
all the times when it enters in the HQ city and for the first time when it enters in every other city."

    We can observe that some of the costs are constant no matter which city we will choose as HQ. For the variable costs, we can do a DFS
and modify some data for each new starting point. 


*/
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
