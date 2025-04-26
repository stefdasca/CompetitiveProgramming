// https://cses.fi/problemset/task/1688/

#include <iostream>
#include <vector>

using namespace std;

int anc[20][200002], lvl[200002];
vector<vector<int>> tree;

void dfs(int par, int node) {
    anc[0][node] = par;

    for (int i = 1; i <= 18; ++i) {
        anc[i][node] = anc[i - 1][anc[i - 1][node]];
    }

    for (int i = 0; i < (int) tree[node].size(); ++i) {
        int nxt = tree[node][i];
        if (nxt == par) {
            continue;
        }

        lvl[nxt] = lvl[node] + 1;
        dfs(node, nxt);
    }
}

int solve(int a, int b) {
    if (lvl[a] < lvl[b]) {
        swap(a, b);
    }

    for (int i = 18; i >= 0; --i) {
        if (lvl[a] - (1 << i) >= lvl[b]) {
            a = anc[i][a];
        }
    }

    if (a == b) {
        return a;
    }

    for (int i = 18; i >= 0; --i) {
        if (anc[i][a] != anc[i][b]) {
            a = anc[i][a], b = anc[i][b];
        }
    }

    return anc[0][a];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    
    tree.resize(n+1);
    for (int node = 2; node <= n; node++) {
        int par;
        cin >> par;
        
        tree[par].push_back(node);
    }
    
    dfs(0, 1);
    while (q--) {
        int a, b;
        cin >> a >> b;
        
        cout << solve(a, b) << '\n';
    }
    return 0;
}
