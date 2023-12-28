#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int NMAX = 100001;
int n, q, col[NMAX];
int anc[17][NMAX], lvl[NMAX];
vector<vector<int> > tree;

int L[NMAX], R[NMAX], cnt;

void dfs(int parent, int node)
{
    cnt++;
    L[node] = cnt;
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
    R[node] = cnt;
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
    int a, b, col, pi;
};

bool ans[100001];

class SegmentTree // range set value, range query for sum segtree, can be easily modified for other things
{
    private:
        int n;
        vector<pair<int, int> > segtree;
        vector<pair<int, int> > lazy;
    public:
        void init(int sz)
        {
            n = sz;
            segtree.resize(1 + 4 * sz);
            lazy.resize(1 + 4 * sz);
        }
        void lz(int node, int L, int R)
        {
            segtree[node] = max(segtree[node], lazy[node]);
            if(L != R)
            {
                lazy[node << 1] = max(lazy[node << 1], lazy[node]);
                lazy[node << 1|1] = max(lazy[node << 1|1], lazy[node]);
            }
            lazy[node] = {0, 0};
        }
        void update(int node, int L, int R, int Lq, int Rq, int col, int lvl)
        {
            if(lazy[node].first != 0)
                lz(node, L, R);
            if(R < Lq || L > Rq)
                return;
            if(Lq <= L && R <= Rq)
            {
                lazy[node] = max(lazy[node], {col, lvl});
                lz(node, L, R);
                return;
            }
            int mid = (L + R) / 2;
            update(node << 1, L, mid, Lq, Rq, col, lvl);
            update(node << 1|1, mid+1, R, Lq, Rq, col, lvl);
        }
        pair<int, int> query(int node, int L, int R, int Lq)
        {
            if(lazy[node].first != 0)
                lz(node, L, R);
            if(L == R)
                return segtree[node];
            int mid = (L + R) / 2;
            if(Lq <= mid)
                return query(node << 1, L, mid, Lq);
            else
                return query(node << 1|1, mid+1, R, Lq);
        }
};

vector<str> queries;
vector<int> ordnodes;

bool cmp(int a, int b)
{
    if(col[a] == col[b])
        return lvl[a] < lvl[b];
    return col[a] < col[b];
}
bool cmp2(str a, str b)
{
    return a.col < b.col;
}
int main()
{
    ifstream cin("milkvisits.in");
    ofstream cout("milkvisits.out");
    
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> col[i];
    
    tree.resize(n+1);
    
    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    dfs(0, 1);
    
    queries.resize(q+1);
    ordnodes.resize(n+1);
    for(int i = 1; i <= n; i++)
        ordnodes[i] = i;
    for(int i = 1; i <= q; i++)
    {
        cin >> queries[i].a >> queries[i].b >> queries[i].col;
        queries[i].pi = i;
    }
    
    sort(ordnodes.begin() + 1, ordnodes.begin() + n + 1, cmp);
    sort(queries.begin() + 1, queries.begin() + q + 1, cmp2);
    
    SegmentTree st;
    st.init(n);
    
    int poz = 1;
    for(int i = 1; i <= q; i++)
    {
        while(poz <= n && col[ordnodes[poz]] <= queries[i].col)
        {
            st.update(1, 1, n, L[ordnodes[poz]], R[ordnodes[poz]], col[ordnodes[poz]], lvl[ordnodes[poz]]);
            poz++;
        }
        pair<int, int> pa = st.query(1, 1, n, L[queries[i].a]);
        pair<int, int> pb = st.query(1, 1, n, L[queries[i].b]);
        int ancestor = lvl[LCA(queries[i].a, queries[i].b)];
        
        if(pa.first == queries[i].col && pa.second >= ancestor)
            ans[queries[i].pi] = 1;
        if(pb.first == queries[i].col && pb.second >= ancestor)
            ans[queries[i].pi] = 1;
    }
    
    for(int i = 1; i <= q; i++)
        cout << ans[i];
        
    return 0;
}
