/*
        Infoarena kdtree - Romanian IOI selection task(2010)

    * We can solve this task using greedy and DFS.

    * If diameter of a subtree is not bigger than K, we can let it as it is,
or else we will have to cut the subtrees which have the highest depth and then compute the highest depth possible.



*/

#include<bits/stdc++.h>
using namespace std;
ifstream f("kdtree.in");
ofstream g("kdtree.out");
int ans, n, k;
vector<int> v[200002];
int depth[200002];
bool cmp(int a, int b)
{
    return depth[a] < depth[b];
}
void dfs(int dad, int nod)
{
    vector<int>v2;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        dfs(nod, vecin);
        v2.push_back(vecin);
    }
    sort(v2.begin(), v2.end(), cmp);
    while(!v2.empty() && depth[v2.back()] == k)
        ++ans, v2.pop_back();
    while(v2.size() >= 2 && depth[v2.back()] + depth[v2[v2.size() - 2]] + 2 > k)
        ++ans, v2.pop_back();
    if(!v2.empty())
        depth[nod] = depth[v2.back()] + 1;
}
int main()
{
    f >> n >> k;
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        f >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(0, 1);
    g << ans;
    return 0;
}
