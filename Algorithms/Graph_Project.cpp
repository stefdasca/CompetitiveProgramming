#include<bits/stdc++.h>

#define fi first
#define se second 
 
using namespace std;
 
typedef long long ll;
 
ifstream f("dfs.in");
ofstream g("dfs.out");

class Graph_Solver
{
	int n, m, st, nr, scc;
	vector<vector<int> > v, sol, tr;
	vector<int> visited, dist, niv, low;
	vector<pair<int, int> > critical;
	deque<int> d;
	stack<int> s;
	public:
		void dfs(int nod)
		{
			visited[nod] = 1;
			for(auto x : v[nod])
				if(visited[x] == 0)
					dfs(x);
			if(scc == 1)
				s.push(nod);
		}
		void dfs2(int nod)
		{
			sol[nr].push_back(nod);
			visited[nod] = 1;
			for(auto x : tr[nod])
				if(visited[x] == 0)
					dfs2(x);
		}
		void dfs_biconex(int dad, int nod)
		{
			visited[nod] = 1;
			low[nod] = niv[nod];
			d.push_back(nod);
			for(int i = 0; i < v[nod].size(); ++i)
			{
				int vecin = v[nod][i];
				if(vecin == dad)
					continue;
				if(visited[vecin])
				{
					low[nod] = min(low[nod], niv[vecin]);
					continue;
				}
				niv[vecin] = niv[nod] + 1;
				dfs_biconex(nod, vecin);
				low[nod] = min(low[nod], low[vecin]);
				if(low[vecin] >= niv[nod])
				{
					if(low[vecin] > niv[nod])
						critical.push_back({nod, vecin});
					nr++;
					int lst;
					do
					{
						sol[nr].push_back(d.back());
						lst = d.back();
						d.pop_back();
					}while(!d.empty() && lst != vecin);
					sol[nr].push_back(nod);
				}
			}
		}
		void solve_biconex()
		{
			visited.resize(n+1);
			niv.resize(n+1);
			low.resize(n+1);
			sol.resize(n+1);
			for(int i = 1; i <= n; ++i)
				visited[i] = niv[i] = low[i] = 0;
			nr = 0;
			dfs_biconex(0, 1);
			g << nr << '\n';
			for(int i = 1; i <= nr; g << '\n', ++i)
				for(int j = 0; j < sol[i].size(); ++j)
					g << sol[i][j] << " ";
			// muchii critice
			for(auto x : critical)
				g << x.first << " " << x.second << '\n';
		}
		void solve_scc()
		{
			visited.resize(n+1);
			sol.resize(n+1);
			tr.resize(n+1);
			for(int i = 1; i <= n; ++i)
				visited[i] = 0;
			for(int i = 1; i <= n; ++i)
			{
				for(auto x : v[i])
					tr[x].push_back(i);
			}
			nr = 0;
			scc = 1;
			for(int i = 1; i <= n; ++i)
				if(!visited[i])
					dfs(i);
			for(int i = 1; i <= n; ++i)
				visited[i] = 0;
			scc = 2;
			while(!s.empty())
			{
				int nod = s.top();
				s.pop();
				if(visited[nod] == 0)
				{
					++nr;
					dfs2(nod);
				}
			}
			g << nr << '\n';
			for(int i = 1; i <= nr; g << '\n', ++i)
				for(int j = 0; j < sol[i].size(); ++j)
					g << sol[i][j] << " ";
		}
		void solve_toposort()
		{
			dist.resize(n+1);
			for(int i = 1; i <= n; ++i)
			{
				for(auto x : v[i])
					++dist[x];
			}
			for(int i = 1; i <= n; ++i)
				if(dist[i] == 0)
					d.push_back(i);
			while(!d.empty()) 
			{
				int p = d.front();
				d.pop_front();
				for (int j = 0; j < v[p].size(); j++) 
				{
					dist[v[p][j]]--;
					if(dist[v[p][j]] == 0)
						d.push_back(v[p][j]);
				}
				g << p << " ";
			}	
		}
		void bfs()
		{
			dist.resize(n+1);
			for(int i = 1; i <= n; ++i)
				dist[i] = -1;
			dist[st] = 0;
			queue<int> q;
			q.push(st);
			while(!q.empty())
			{
				int nod = q.front();
				q.pop();
				for(auto x : v[nod])
				{
					if(dist[x] == -1)
					{
						dist[x] = dist[nod] + 1;
						q.push(x);
					}
				}
			}
			for(int i = 1; i <= n; ++i)
				g << dist[i] << " ";
			g << '\n';
		}
		void citire(int pr, int tip)
		{
			f >> n >> m;
			if(pr == 1)
				f >> st;
			v.resize(n+1);
			visited.resize(n+1);
			for(int i = 1; i <= n; ++i)
				visited[i] = 0;
			for(int i = 1; i <= m; ++i)
			{
				int a, b;
				f >> a >> b;
				v[a].push_back(b);
				if(tip == 0) // undirected
					v[b].push_back(a);
			}
		}
		int conex()
		{
			int ans = 0;
			for(int i = 1; i <= n; ++i)
				if(visited[i] == 0)	
					dfs(i), ++ans;
			return ans;
		}
		void havel_hakimi()
		{
			f >> n;
			vector<int> vals(n);
			map<pair<int, int>, int> mp;
			bool bad = 0;
			long long sum = 0;
			for(int i = 0; i < n; ++i)
			{
				f >> vals[i];
				sum += vals[i];
			}
			set<pair<int, int> > s;
			for(int i = 0; i < n; ++i)
				s.insert({vals[i], i});
			while(!s.empty())
			{
				pair<int, int> nod = *s.rbegin();
				s.erase(nod);
				vector<pair<int, int> > to_insert;
				while(!s.empty() && nod.first != 0)
				{
					pair<int, int> nod2 = *s.rbegin();
					s.erase(nod2);
					if(mp.find({min(nod.se, nod2.se), max(nod.se, nod2.se)}) == mp.end())
					{
						--nod.fi;
						--nod2.fi;
						mp[{min(nod.se, nod2.se), max(nod.se, nod2.se)}] = 1;
						if(nod2.fi != 0)
							to_insert.push_back(nod2);
					}
					else
						to_insert.push_back(nod2);
				}
				if(nod.fi > 0)
					bad = 1;
				for(auto x : to_insert)	
					s.insert(x);
			}
			if(sum % 2 == 1) 
				bad = 1;
			if(bad == 1)
				g << "No graph\n";
			else
				for(map<pair<int, int>, int> :: iterator it = mp.begin(); it != mp.end(); ++it)
					g << (it->first).fi << " " << (it->first).se << '\n';
		}
};

Graph_Solver gr;
int main()
{
	gr.havel_hakimi();
	return 0;
}
