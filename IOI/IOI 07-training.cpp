/*
		IOI 07-training
	
	Since the biggest degree is at most 10, we can use bitmasks to solve the tasks. Also,
we can use tree dp because we have a tree part and a non-tree part.

	The non-tree edges can be split in odd and even edges, based on distance between
the ends of the edge.
	
	Now, we have to block the odd edges(they generate odd cycles).

	An even cycle is formed from the even edges if they overlap, therefore, 
each tree edge can be part of at most 1 odd cycle

	Let's define dp[i][mask] = max sum of non-tree edges we keep in subtree of i
when the children specified in mask aren't considered
        dp[i][mask] = max(sum_of_children(dp[child][0]), max(Edge cost + sum_of_decomposed_paths_from_edge));
    
    In order to compute the DP, we can use LCA and bitmasking, and since the constraints are small,
we can use naive methods to compute them, it will be fast enough. 

*/
#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front

// #define fisier 1

using namespace std;

typedef long long ll;

const int mod = 1000000007;
const double dancila = 3.14159265359; // PI 
const double eps = 1e-9;



int n, m, cost;
vector<int> v[1002];

int dp[1001][1024], tt[12][1002], lvl[1002], st[1002], dr[1002], dt, grad[1002];

pair<int, int> p[1002];

struct muchie
{
	int a, b, c, lca;
};
bool cmp(muchie a, muchie b)
{
	return dr[a.lca] < dr[b.lca];
}

vector<muchie> muchii;
void dfs(int dad, int nod)
{
	lvl[nod] = lvl[dad] + 1;
	tt[0][nod] = dad;
	++dt;
	st[nod] = dt;
	for(int i = 1; i <= 10; ++i)
		tt[i][nod] = tt[i-1][tt[i-1][nod]];
	for(int i = 0; i < v[nod].size(); ++i)
	{
		int vecin = v[nod][i];
		if(vecin == dad)
			continue;
		p[vecin] = {nod, (1 << grad[nod])};
		++grad[nod];
		dfs(nod, vecin);
	}
	++dt;
	dr[nod] = dt;
}
int LCA(int a, int b)
{
	if(lvl[a] > lvl[b])
		swap(a, b);
	for(int i = 10; i >= 0; --i)
		if(lvl[b] - (1<<i) >= lvl[a])
			b = tt[i][b];
	if(a == b)
		return a;
	for(int i = 10; i >= 0; --i)
		if(tt[i][a] != tt[i][b])	
			a = tt[i][a], b = tt[i][b];
	return tt[0][a];
}
int main()
{
   	#ifdef fisier
		ifstream f("input.in");
		ofstream g("output.out");
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for(int i = 1; i <= m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		cost += c;
		if(c == 0)
		{
			v[a].pb(b);
			v[b].pb(a);
		}
		muchii.pb({a, b, c, 0});
	}
	dfs(0, 1);
	for(int i = 0; i < m; ++i)
		muchii[i].lca = LCA(muchii[i].a, muchii[i].b);
   	sort(muchii.begin(), muchii.end(), cmp);
	for(muchie i : muchii) 
	{
		int de = lvl[i.a] % 2;
		int dx = lvl[i.b] % 2;
		if(i.c && (de ^ dx))
			continue;
		int sm = i.c;
		pair<int, int> A, B;
		for(A = {i.a, 0}; A.fi != i.lca; A = p[A.fi]) 
			sm += dp[A.fi][A.se];
		for(B = {i.b, 0}; B.fi != i.lca; B = p[B.fi]) 
			sm += dp[B.fi][B.se];
		for(int mask = (1 << grad[i.lca]) - 1; mask >= 0; mask--) 
			if(!(mask & A.se || mask & B.se))
				dp[i.lca][mask] = max(dp[i.lca][mask], sm + dp[i.lca][mask | A.se | B.se]);
	}
    cout << cost - dp[1][0];
    return 0;
}
