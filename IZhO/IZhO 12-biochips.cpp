/*
                        IZhO 12-biochips

    This problem can be solved by dynamic programming. At first we will do a
DFS in order to have the DFS order of the tree, keeping the starting and the ending position
for each node's subtrees. Using this information, we will ignore the fact that we can't take ancestors,
focusing only on avoiding to take descendants. Then, we will compute dp[i][j] = max possible sum if we take(or don't take)
the node situated on position i in the dfs order, if we have already taken j nodes so far. So we have 2 cases, we either take
the node and we will consider values taken outside of subtree of node i, or we will take the son's values, whichever is better.

*/

#include<bits/stdc++.h>
using namespace std;
int n, m, root, val[200002];
vector<int>v[200002];
int dp[200002][502], val2[200002], st[200002], sf[200002], poz;
int qq = 0;
void dfs(int nod)
{
     ++poz;
     st[nod] = poz;
     val2[poz] = val[nod];
     dp[poz][1] = val[nod];
     for(int i = 0; i < v[nod].size(); ++i)
     {
         int vecin = v[nod][i];
         dfs(vecin);
     }
     sf[st[nod]] = poz;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        int parent;
        cin >> parent;
        cin >> val[i];
        if(parent == 0)
            root = i;
        else
            v[parent].push_back(i);
    }
    dfs(root);
    int ans = 0;
    for(int i = poz; i >= 1; --i)
        for(int j = 1; j <= m; ++j)
        {
            if(i + 1 <= poz)
                dp[i][j] = max(dp[i][j], dp[i+1][j]);
            if(sf[i] + 1 <= poz)
                dp[i][j] = max(dp[i][j] , dp[sf[i] + 1][j-1] + val2[i]);
            if(j == m)
                ans = max(ans, dp[i][j]);
        }
    cout << ans;
    return 0;
}
