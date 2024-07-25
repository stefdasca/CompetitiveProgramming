// https://cses.fi/problemset/task/1683/

#include <iostream>
#include <vector>
#include <stack>
 
using namespace std;
 
stack<int> s;
 
void dfs (int node, vector<vector<int>> &v, vector<int> &vis) {
    vis[node] = 1;
    for (int j = 0; j < (int) v[node].size(); ++j) {
        int nxt = v[node][j];
        if (!vis[nxt]) {
            dfs(nxt, v, vis);
        }
    }
    s.push(node);
}
void dfs2 (int node, int cnt, vector<vector<int>> &tr, vector<int> &vis2, vector<int> &scc)
{
    vis2[node] = 1;
    scc[node] = cnt;
    for (int j = 0; j < (int) tr[node].size(); ++j) {
        int nxt = tr[node][j];
        if (!vis2[nxt]) {
            dfs2(nxt, cnt, tr, vis2, scc);
        }
    }
}
 
int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> vis(n+1), vis2(n+1), scc(n+1);
    vector<vector<int>> v(n+1), tr(n+1);
    
    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        tr[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i, v, vis);
        }
    }
    
    int cnt = 0;
    while (!s.empty()) {
        int node = s.top();
        s.pop();
        if (!vis2[node]) {
            ++cnt;
            dfs2(node, cnt, tr, vis2, scc);
        }
    }
    cout << cnt << '\n';
    for (int i = 1; i <= n; ++i) {
        cout << scc[i] << " ";
    }
    return 0;
}
