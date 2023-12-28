#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int NMAX = 100001;
int n, q, col[NMAX];
int anc[17][NMAX], lvl[NMAX];
vector<vector<int> > tree, nodes;

void dfs(int parent, int node)
{
    anc[0][node] = parent;
    for(int i = 1; i <= 16; i++)
        anc[i][node] = anc[i-1][anc[i-1][node]];
    for(int i = 0; i < (int) tree[node].size(); i++)
    {
        int nxt = tree[node][i];
        if(nxt == parent)
            continue;
        lvl[nxt] = lvl[node] + 1;
        dfs(node, nxt);
    }
}

int LCA(int a, int b)
{
	if(lvl[a] < lvl[b])
		swap(a, b);
	for(int i = 16; i >= 0; --i)
		if(lvl[a] - (1<<i) >= lvl[b])
			a = anc[i][a];
	if(a == b)
		return a;
	for(int i = 16; i >= 0; --i) 
		if(anc[i][a] != anc[i][b])
			a = anc[i][a], b = anc[i][b];
	return anc[0][a];
}

struct str
{
    int pos, LCA, col;
};
vector<vector<str > > queries;

bool ans[100001];

void dfs2(int parent, int node)
{
    nodes[col[node]].push_back(node);
    for(int i = 0; i < (int) queries[node].size(); i++)
    {
        str query = queries[node][i];
        if(!nodes[query.col].empty() && lvl[nodes[query.col].back()] >= lvl[query.LCA])
            ans[query.pos] = 1;
    }
    
    for(int i = 0; i < (int) tree[node].size(); i++)
    {
        int nxt = tree[node][i];
        if(nxt == parent)
            continue;
        dfs2(node, nxt);
    }
    nodes[col[node]].pop_back();
}
int main()
{
    ifstream cin("milkvisits.in");
    ofstream cout("milkvisits.out");
    
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> col[i];
    
    tree.resize(n+1);
    nodes.resize(n+1);
    queries.resize(n+1);
    
    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    dfs(0, 1);
    
    for(int i = 1; i <= q; i++)
    {
        int a, b, col;
        cin >> a >> b >> col;
        str qa = {i, LCA(a, b), col};
        queries[a].push_back(qa);
        queries[b].push_back(qa);
    }
    
    dfs2(0, 1);
    
    for(int i = 1; i <= q; i++)
        cout << ans[i];
        
    return 0;
}
