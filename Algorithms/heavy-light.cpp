// https://cses.fi/problemset/task/2134/

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
vector<vector<int>> tree;
vector<int> values, indices, top, sts, lvl, order, pos;
 
int binjump[18][200005];
 
// LCA + binary lifting
 
void dfs(int parent, int node) {
    binjump[0][node] = parent;
    sts[node] = 1;
    for (int i = 1; i <= 17; i++) {
        binjump[i][node] = binjump[i-1][binjump[i-1][node]];
    }
    
    for (int i = 0; i < (int) tree[node].size(); i++) {
        int nxt = tree[node][i];
        if (nxt == parent) {
            continue;
        }
        lvl[nxt] = lvl[node] + 1;
        dfs(node, nxt);
        sts[node] += sts[nxt];
    }
}
 
int LCA(int a, int b) {
    if (lvl[b] < lvl[a]) {
        swap(a, b);
    }
    
    for (int i = 17; i >= 0; i--) {
        if (lvl[b] - (1<<i) >= lvl[a]) {
            b = binjump[i][b];
        }
    }
    
    if (a == b) {
        return a;
    }
    
    for (int i = 17; i >= 0; i--) {
        if (binjump[i][a] != binjump[i][b]) {
            a = binjump[i][a];
            b = binjump[i][b];
        }
    }
    return binjump[0][a];
}
 
int cnt = 0;
void dfs_hld(int parent, int node, int topp) {
    cnt++;
    top[node] = topp;
    pos[node] = cnt;
    order[cnt] = node;
    
    int mx = 0;
    for (int i = 0; i < (int) tree[node].size(); i++) {
        int nxt = tree[node][i];
        if (nxt == parent) {
            continue;
        }
        if (mx == 0 || sts[nxt] > sts[mx]) {
            mx = nxt;
        }
    }
    
    if (mx != 0) {
        dfs_hld(node, mx, topp);
    }
    
    for (int i = 0; i < (int) tree[node].size(); i++) {
        int nxt = tree[node][i];
        if (nxt == parent) {
            continue;
        }
        if (nxt != mx) {
            dfs_hld(node, nxt, nxt);
        }
    }
}
 
vector<int> segtree, start_node, len, start_pos;
 
void build (int start_node, int node, int L, int R) {
    if (L == R) {
        segtree[start_node + node - 1] = values[order[L]];
        return;
    }
    
    int mid = (L + R) / 2;
    build(start_node, node << 1, L, mid);
    build(start_node, node << 1|1, mid+1, R);
    
    segtree[start_node + node - 1] = max(segtree[start_node + (node << 1) - 1], segtree[start_node + (node << 1|1) - 1]);
}
 
void update (int start_node, int node, int L, int R, int pos) {
    if (L == R) {
        segtree[start_node + node - 1] = values[order[L]];
        return;
    }
    
    int mid = (L + R) / 2;
    if (pos <= mid) {
        update (start_node, node << 1, L, mid, pos);
    }
    else {
        update (start_node, node << 1|1, mid+1, R, pos);
    }
    segtree[start_node + node - 1] = max(segtree[start_node + (node << 1) - 1], segtree[start_node + (node << 1|1) - 1]);
}
 
int query (int start_node, int node, int L, int R, int Lq, int Rq) {
    if (R < Lq || L > Rq) {
        return -1;
    }
    
    if (Lq <= L && R <= Rq) {
        return segtree[start_node + node - 1];
    }
    
    int mid = (L + R) / 2;
    return max(query(start_node, node << 1, L, mid, Lq, Rq), query(start_node, node << 1|1, mid+1, R, Lq, Rq));
}
 
void init(int n) {
    values.resize(n+1);
    indices.resize(n+1);
    top.resize(n+1);
    tree.resize(n+1);
    sts.resize(n+1);
    lvl.resize(n+1);
    order.resize(n+1);
    segtree.resize(4*n+1);
    start_node.resize(n+1);
    len.resize(n+1);
    pos.resize(n+1);
    start_pos.resize(n+1);
} 
 
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    
    init(n);
    
    for (int i = 1; i <= n; i++) {
        cin >> values[i];
    }
    
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    dfs(0, 1);
    dfs_hld(0, 1, 1);
    
    int fi_node = 1;
    for (int i = 1; i <= n; ) {
        int pos = i;
        while (pos <= n && top[order[pos]] == top[order[i]]) {
            pos++;
        }
        for (int j = i; j < pos; j++) {
            start_node[order[j]] = fi_node;
            len[order[j]] = pos - i;
            start_pos[order[j]] = i;
        }
        build(fi_node, 1, i, pos-1);
        fi_node += 4 * (pos - i);
        i = pos;
    }
    
    for (; q; q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int node, val;
            cin >> node >> val;
            values[node] = val;
            update (start_node[node], 1, start_pos[node], start_pos[node] + len[node] - 1, pos[node]);
        }
        else {
            int L, R;
            cin >> L >> R;
            
            int val = LCA(L, R);
            int ans = 0;
            while (order[start_pos[L]] != order[start_pos[val]]) {
                ans = max(ans, query(start_node[L], 1, start_pos[L], start_pos[L] + len[L] - 1, start_pos[L], pos[L]));
                int node = order[start_pos[L]];
                L = binjump[0][node];
            }
            
            while (order[start_pos[R]] != order[start_pos[val]]) {
                ans = max(ans, query(start_node[R], 1, start_pos[R], start_pos[R] + len[R] - 1, start_pos[R], pos[R]));
                int node = order[start_pos[R]];
                R = binjump[0][node];
            }
            
            ans = max(ans, query(start_node[val], 1, start_pos[val], start_pos[val] + len[val] - 1, pos[val], max(pos[L], pos[R])));
            cout << ans << " ";
        }
    }
    return 0;
}
