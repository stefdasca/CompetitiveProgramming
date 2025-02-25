/*
    solution code by Stefan Dascalescu

    For this problem, the relations between the strings form a tree like structure and the M values we have to print are actually the answers for the leaves from this tree.

    Now, in order to solve the problem, there are several approaches, but what I did was to run a DFS from 0 and every time I had two or more leaves in a subtree, I would
    have the answer for the earliest (cnt - 1) leaves as (lvl + 1), where cnt is the number of such leaves and lvl is the distance from 0 to that given node, and keep going
    with the last leaf which shows in the queries among the ones present there.

    This can be done easily with some sorting and a preprocessing in O(n log n).
    
    video link: https://www.youtube.com/watch?v=1Tk99-nfbSA

*/

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;

vector<vector<int>> tree;

int cntleaves = 0;

void dfs (int node) {
    bool leaf = 1;
    for (auto x : tree[node]) {
        dfs(x);
        leaf = 0;
    }
    cntleaves += leaf;
}

vector<int> pos, lf, ans;

void dfs2 (int node, int lvl) {
    bool leaf = 1;
    for (auto x : tree[node]) {
        dfs2(x, lvl+1);
        leaf = 0;
    }
    if (leaf) {
        lf[node] = node;
    }
    else {
        vector<pair<int, int>> queries;
        for (auto x : tree[node]) {
            queries.push_back({pos[lf[x]], lf[x]});
        }
        sort(queries.begin(), queries.end());
        for (int i = 0; i + 1 < (int) queries.size(); i++) {
            ans[queries[i].second] = lvl+1;
        }
        lf[node] = queries.back().second;
    }
}
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    tree.resize(n+1);
    pos.resize(n+1);
    lf.resize(n+1);
    ans.resize(n+1);
    
    vector<int> v(n+1);
    
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        tree[v[i]].push_back(i);
    }
    dfs(0);
    
    vector<int> queries(cntleaves);
    for (int i = 0; i < cntleaves; i++) {
        cin >> queries[i];
        pos[queries[i]] = i;
    }
    dfs2(0, 0);
    
    for (int i = 0; i < cntleaves; i++) {
        cout << ans[queries[i]] << '\n';
    }
    return 0;
}
