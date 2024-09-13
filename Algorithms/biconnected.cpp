// based on https://cses.fi/problemset/task/2177

// it finds BCCs, bridges, articulation points

#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
vector<vector<int> > v;

vector<int> vis, lvl, low;
deque<int> d;

set<pair<int, int> > edges; // for fixing directions

vector<vector<int> > bccs;

void dfs (int parent, int node) {
    vis[node] = 1;
    low[node] = lvl[node];
    d.push_back(node);
    
    bool articulation = 0;
    
    int children = 0;
    for (int i = 0; i < (int) v[node].size(); ++i) {
        int nxt = v[node][i];
        if (nxt == parent) {
            continue;
        }
        if (vis[nxt]) {
            low[node] = min(low[node], lvl[nxt]);
            
            if (lvl[node] > lvl[nxt]) {
                edges.insert({node, nxt});
            }
            else {
                edges.insert({nxt, node});
            }
            continue;
        }
        
        lvl[nxt] = lvl[node] + 1;
        children++;
        dfs(node, nxt);
        low[node] = min(low[node], low[nxt]);
        
        if (lvl[node] < lvl[nxt]) {
            edges.insert({node, nxt});
        }
        else {
            edges.insert({nxt, node});
        }
            
        if (low[nxt] >= lvl[node]) {
            cnt++;
            
            if (parent != 0) {
                articulation = 1;
            }
            int lst;
            do
            {
                lst = d.back();
                sol[cmt].push_back(d.back());
                d.pop_back();
            }while(!d.empty() && lst != nxt);
        }
        
        if (low[nxt] > lvl[node]) {
            // bridge between node and nxt
            cout << "IMPOSSIBLE\n";
            exit(0);
        }
    }
    
    if (parent == 0 && children >= 2) {
        articulation = 1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    v.resize(n+1); vis.resize(n+1);
    lvl.resize(n+1); low.resize(n+1);
    
    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    dfs(0, 1);
    
    if (edges.size() != m) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    for (auto x : edges) {
        cout << x.first << " " << x.second << '\n';
    }
    return 0;
}
