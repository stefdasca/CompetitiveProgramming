/*
        Infoarena asmin(https://www.infoarena.ro/problema/asmin)

    "Given a tree with n nodes and an array with reminders, put values on each of the nodes such that the sum of the values is minimal
and sum of the elements on the path from the root to ith node has remainder Ri. Find the nodes which can be chosen as root such that
the sum of the values in tree is minimal"

    This is a rather classical dp on trees, which can be solved using 2 dfs. We will compute in the first dfs
dp[i] = min sum of values in subtree of i such that the remainder relations are respected, if the root is i.
In the second dfs we will extend the computations to the other nodes, therefore finding the answers.


*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("asmin.in");
ofstream g("asmin.out");
int n, k, rest[18002];
int dp[18002];
vector<int>v[18002];
int ans[18002];
int mini, cate;
int dr(int a, int b)
{
    if(b >= a)
        return b - a;
    else
        return k - a + b;
}
void dfs1(int dad, int nod)
{
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        dfs1(nod, vecin);
        dp[nod] = dp[nod] + dp[vecin] + dr(rest[nod], rest[vecin]);
    }
}
void dfs2(int dad, int nod, int val)
{
    if(nod != 1)
    {
        int pa = dp[nod] + val + rest[nod];
        ans[nod] = pa;
        if(pa < mini)
            mini = pa, cate = 1;
        else
            if(pa == mini)
                ++cate;
    }
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        int nv = val + dp[nod] - dp[vecin] - dr(rest[nod], rest[vecin]);
        nv += dr(rest[vecin], rest[nod]);
        dfs2(nod, vecin, nv);
    }
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
    for(int i = 1; i <= n; ++i)
        f >> rest[i];
    dfs1(0, 1);
    mini = dp[1] + rest[1];
    cate = 1;
    ans[1] = mini;
    dfs2(0, 1, 0);
    g << mini << " " << cate << '\n';
    for(int i = 1; i <= n; ++i)
        if(ans[i] == mini)
            g << i << " ";
    return 0;
}
