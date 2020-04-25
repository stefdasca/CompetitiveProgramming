/*
			CEOI 17-OneWay
 
	This is a classical exercise of using BCC. 
	
	Firstly, we will find the BCCs of the graph(this can be done with the well known O(n+m) algorithm, but one 
should be careful because there may be multiple edges between the same two nodes.
	
	Then, based on the cycles found in the first DFS, we will create a directed graph, coresponding to the relations
between BCCs, by running another DFS.
	
	Last but not least, based on the pairs we are given in the input, we will direct edges such that we can respect each condition.
This can be done by using a DP algorithm.

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
 
 
int n, m, lvl[100002], low[100002], viz[100002];
vector<pair<int, int> > v[100002], v2[100002];
 
pair<int, int> E[100002];
int ans[100002];
void dfs(int dad, int nod)
{
	viz[nod] = 1;
	low[nod] = lvl[nod];
	for(auto vecin : v[nod])
	{
		if(vecin.se == dad)
			continue;
		if(viz[vecin.fi])
		{
			low[nod] = min(low[nod], lvl[vecin.fi]);
			ans[vecin.se] = 1;
			continue;
		}
		lvl[vecin.fi] = lvl[nod] + 1;
		dfs(vecin.se, vecin.fi);
		if(low[vecin.fi] <= lvl[nod])
			ans[vecin.se] = 1;
		low[nod] = min(low[nod], low[vecin.fi]);
	}
}
 
int bcc[100002], bcnt;
void dfs2(int nod, int col)
{
	bcc[nod] = col;
	for(auto vecin : v[nod])
	{
		if(bcc[vecin.fi]) 
			continue;
		if(ans[vecin.se]) 
			dfs2(vecin.fi, col);
		else
		{
			++bcnt;
			v2[col].push_back({bcnt, vecin.se});
			dfs2(vecin.fi, bcnt);
		}
	}
}
 
int dp[100002];
void dfs3(int nod)
{
	for(auto vecin : v2[nod])
	{
		dfs3(vecin.fi);
		int nxt = E[vecin.se].fi;
		if(dp[vecin.fi] > 0)
		{
			if(bcc[nxt] == vecin.fi) 
				ans[vecin.se] = 2;
			else 
				ans[vecin.se] = 3;
		}
		else 
			if(dp[vecin.fi]<0)
			{
				if(bcc[nxt] == vecin.fi) 
					ans[vecin.se] = 3;
				else 
					ans[vecin.se] = 2;
			}
			else 
				ans[vecin.se] = 1;
		dp[nod] += dp[vecin.fi];
	}
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
	    int a, b;
	    cin >> a >> b;
	    E[i] = {a, b};
	    v[a].pb({b, i});
	    v[b].pb({a, i});
	}
	
	vector<int> rad;
	for(int i = 1; i <= n; ++i)
		if(!viz[i])
		{
			lvl[i] = 1;
			dfs(0, i);
			++bcnt;
			rad.pb(bcnt);
			dfs2(i, bcnt);
		}
	
	int p;
	cin >> p;
	for(; p; --p)
	{
		int a, b;
		cin >> a >> b;
		if(bcc[a] == bcc[b])
			continue;
		++dp[bcc[a]];
		--dp[bcc[b]];
	}
	
	for(auto it : rad) 
		dfs3(it);
	char ch[5] = "XBRL";
	for(int i = 1; i <= m; ++i)
		cout << ch[ans[i]];
    return 0;
}
