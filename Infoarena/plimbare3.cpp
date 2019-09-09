/*
        infoarena plimbare - Romanian IOI selection task(2013)

    "Given a tree with n nodes, find for each edge the maximum length of the diameter of the tree we can obtain
if we move that edge such that the given graph will keep being a tree"

    Let's compute several values for each node i in the first DFS:

    * the longest two chains in subtree of node i
    * the longest path in subtree of node i(that's the maximum between the values among the sons of node i and
the length of the longest two chains in subtree of node i)

    Then, we will run another DFS where we will combine the values which were already computed in the first DFS.

    When computing the answer for a edge which has ends a and b(a is father of b), we will proceed as follows:

    * It's obvious that the answer will be formed by the longest path in subtree of b, plus 1.
    * From the rest of the tree, we will choose the longest path so far, which is the maximum of following values:
        * the longest path of the tree if we dont include subtree of a
        * the longest path of subtree of a if we exclude subtree of b
        * the longest chain outside of subtree of a + longest chain of subtree of a if we exclude subtree of b

    This can be done in O(n) or in O(n log n)

*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("plimbare3.in");
ofstream g("plimbare3.out");
int n;
vector<pair<int, int> >v[200002];
int ans[200002];
int best_path[3][200002], wh[3][200002];
int max_length[200002];
void dfs(int dad, int nod)
{
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].first;
        if(vecin == dad)
            continue;
        dfs(nod, vecin);
        if(best_path[1][vecin] + 1 > best_path[1][nod])
        {
            best_path[2][nod] = best_path[1][nod];
            wh[2][nod] = wh[1][nod];
            best_path[1][nod] = best_path[1][vecin] + 1;
            wh[1][nod] = vecin;
        }
        else
            if(best_path[1][vecin] + 1 > best_path[2][nod])
            {
                best_path[2][nod] = best_path[1][vecin] + 1;
                wh[2][nod] = vecin;
            }
        max_length[nod] = max(max_length[nod], max_length[vecin]);
    }
    max_length[nod] = max(max_length[nod], best_path[1][nod] + best_path[2][nod]);
}
void dfs2(int dad, int nod, int best_length, int bst_path)
{
    vector<pair<int, int> >paths;
    vector<pair<int, int> >chains;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].first;
        if(vecin == dad)
            continue;
        paths.push_back({max_length[vecin], vecin});
        chains.push_back({best_path[1][vecin] + 1, vecin});
    }
    sort(paths.begin(), paths.end());
    sort(chains.begin(), chains.end());
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i].first;
        if(vecin == dad)
            continue;
        int label = v[nod][i].second;
        int potential = max_length[vecin];
        int p2 = 0;
        for(int j = paths.size() - 1; j >= 0; --j)
            if(paths[j].second != vecin)
            {
                p2 += paths[j].first;
                break;
            }
        int p3 = 0;
        bool nr = 0;
        int p4 = 0;
        for(int j = chains.size() - 1; j >= 0; --j)
            if(chains[j].second != vecin)
            {
                if(!nr)
                    p4 += chains[j].first;
                p3 += chains[j].first;
                if(nr)
                    break;
                nr = 1;
            }
        ans[label] = max(ans[label], max(p2, max(bst_path + p4, max(p3, best_length))) + potential + 1);
        dfs2(nod, vecin, max(p2, max(bst_path + p4, max(p3, best_length))), max(p4, bst_path) + 1);
    }
}
int main()
{
    f >> n;
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        f >> a >> b;
        v[a].push_back({b, i});
        v[b].push_back({a, i});
    }
    dfs(0, 1);
    dfs2(0, 1, 0, 0);
    for(int i = 1; i < n; ++i)
        g << max(ans[i], max_length[1]) << '\n';
    return 0;
}
