/*
    solution code by Stefan Dascalescu
    
    I will add the detailed writeup soon

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
