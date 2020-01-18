/*
		USACO 19jan-exercise-plat

     editorial - http://usaco.org/current/data/sol_exercise_platinum_jan19.html
	
*/
#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define dancila 3.14159265359
#define eps 1e-9

#define fisier 1

using namespace std;

typedef long long ll;

int N, Q, M;
vector<int> v[200005];
int x[200005], y[200005], anc[200005];
int p[200005][20];
int lvl[200005];

int intern[200005];
int sp[200005];
map<pair<int,int>, int> MP;

void dfs(int i, int tt, int depth)
{
	p[i][0] = tt;
	lvl[i] = depth;
	for(int j = 1; j <= 19; ++j)
        if(p[i][j - 1] == -1)
            p[i][j] = -1;
        else
            p[i][j] = p[p[i][j-1]][j-1];
	for(int j = 0; j < v[i].size(); j++)
		if(v[i][j] != tt)
			dfs(v[i][j], i, depth+1);
}

void dfsSum(int i, int sum)
{
	sp[i] = sum;
	for(int j = 0; j < v[i].size(); j++)
		if(v[i][j] != p[i][0])
			dfsSum(v[i][j], sum + intern[v[i][j]]);
}

int lca(int a,int b)
{
	for(int j = 19; j >= 0; j--)
		if(lvl[p[a][j]] >= lvl[b])
			a = p[a][j];
	for(int j = 19; j >= 0; j--)
		if(lvl[p[b][j]] >= lvl[a])
			b = p[b][j];
	for(int j = 19; j >= 0; j--)
		if(p[a][j] != p[b][j])
			a = p[a][j], b = p[b][j];
	if(a==b)
        return a;
	return p[a][0];
}

int topEdge(int top, int bot)
{
	if(top == bot)
		return -1;
	for(int j = 19; j >= 0; j--)
		if(lvl[p[bot][j]] > lvl[top])
			bot = p[bot][j];
	return bot;
}

int main()
{

    #ifdef fisier
        ifstream f("exercise.in");
        ofstream g("exercise.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    f >> N >> M;
	Q = M - (N-1);
	for(int i = 1; i < N; i++)
	{
	    int a, b;
		f >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, -1, 1);
	long long ans = 0;
	for(int i = 1; i <= Q; i++)
	{
		f >> x[i] >> y[i];
		anc[i] = lca(x[i], y[i]);
		int topx = topEdge(anc[i], x[i]);
		if(topx != -1)
		{
			ans -= intern[topx] + 1;
			intern[topx]++;
		}
		int topy = topEdge(anc[i], y[i]);
		if(topy != -1)
		{
			ans -= intern[topy] + 1;
			intern[topy]++;
		}
		if(topx != -1 && topy != -1)
		{
			if(topx > topy)
                swap(topx,topy);
			ans -= MP[{topx,topy}];
			MP[{topx,topy}]++;
		}
	}
	dfsSum(1, 0);
	for(int i = 1; i <= Q; i++)
		ans += sp[x[i]] + sp[y[i]] - 2 * sp[anc[i]];
	g << ans << '\n';
    return 0;
}
