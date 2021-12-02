#include<bits/stdc++.h>
 
#define fi first
#define se second 
 
using namespace std;
 
typedef long long ll;
 
ifstream f("darb.in");
ofstream g("darb.out");
 
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
		int Find(int nod, vector<int> &tt)
		{
			if(tt[nod] == nod)
				return nod;
			return tt[nod] = Find(tt[nod], tt);
		}
		void Union(int a, int b, vector<int> &sz, vector<int> &tt)
		{
			if(sz[a] >= sz[b])
				sz[a] += sz[b], tt[b] = a;
			else
				sz[b] += sz[a], tt[a] = b;
		}
		void cost_graph(vector<vector<pair<int, int> > > &costs, vector<pair<int, pair<int, int> > > &edges)
		{
			f >> n >> m;
			costs.resize(n+1);
			for(int i = 1; i <= m; ++i)
			{
				int a, b, c;
				f >> a >> b >> c;
				costs[a].push_back({b, c});
				edges.push_back({c, {a, b}});
			}
		}
		void dsu()
		{
			f >> n >> m;
			vector<int> tt(n+1, 0);
			vector<int> sz(n+1, 0);
			for(int i = 1; i <= n; ++i)
				tt[i] = i, sz[i] = 1;
			for(; m; --m)
			{
				int tip, a, b;
				f >> tip >> a >> b;
				if(tip == 1)
				{
					int fnd_a = Find(a, tt);
					int fnd_b = Find(b, tt);
					Union(fnd_a, fnd_b, sz, tt);
				}
				else
				{
					int fnd_a = Find(a, tt);
					int fnd_b = Find(b, tt);
					if(fnd_a == fnd_b)
						g << "DA\n";
					else
						g << "NU\n";
				}
			}
		}
		void apm()
		{
			vector<vector<pair<int, int> > > costs;
			vector<pair<int, pair<int, int> > > edges, apm;
			long long cost = 0;
			cost_graph(costs, edges);
			sort(edges.begin(), edges.end());
			vector<int> tt(n+1, 0);
			vector<int> sz(n+1, 0);
			for(int i = 1; i <= n; ++i)
				tt[i] = i, sz[i] = 1;
			for(int i = 0; i < m; ++i)
			{
				int a = edges[i].second.first;
				int b = edges[i].second.second;
				int c = edges[i].first;
				int fnd_a = Find(a, tt);
				int fnd_b = Find(b, tt);
				if(fnd_a != fnd_b)
				{
					Union(fnd_a, fnd_b, sz, tt);
					cost += c;
					apm.push_back(edges[i]);
				}
			}
			g << cost << '\n';
			g << n-1 << '\n';
			for(auto x : apm)
				g << x.second.first << " " << x.second.second << '\n';
		}
		void dijkstra()
		{
			vector<vector<pair<int, int> > > costs;
			vector<pair<int, pair<int, int> > > edges;
			cost_graph(costs, edges);
			vector<long long> dist(n+1, 0);
			set<pair<long long, int> > djk;
			djk.insert({0, 1});
			while(!djk.empty())
			{
				pair<long long, int> nod = *djk.begin();
				djk.erase(nod);
				for(auto x : costs[nod.second])
				{
					int nxt = x.first;
					int cst = x.second;
					if(nxt == 1)
						continue;
					if(dist[nxt] == 0 || nod.first + cst < dist[nxt])
					{
						djk.erase({dist[nxt], nxt});
						dist[nxt] = nod.first + cst;
						djk.insert({dist[nxt], nxt});
					}
				}
			}
			for(int i = 2; i <= n; ++i)
				g << dist[i] << " ";
			g << '\n';
		}
		void bellman_ford()
		{
			vector<vector<pair<int, int> > > costs;
			vector<pair<int, pair<int, int> > > edges;
			cost_graph(costs, edges);
			vector<long long> dist(n+1, 0);
			vector<int> viz(n+1, 0);
			vector<int> isqueue(n+1, 0);
			for(int i = 2; i <= n; ++i)
				dist[i] = (1LL<<60);
			queue <int> q;
			q.push(1);
			viz[1] = 1;
			isqueue[1] = 1;
			bool neg_cicle = 0;
			while(!q.empty())
			{
				int nod = q.front();
				q.pop();
				isqueue[nod] = 0;
				for(auto x : costs[nod])
				{
					int nxt = x.first;
					int cost = x.second;
					if(dist[nxt] > dist[nod] + cost)
					{
						dist[nxt] = dist[nod] + cost;
						++viz[nxt];
						if(viz[nxt] >= n-1)
						{
							neg_cicle = 1;
							while(!q.empty())
								q.pop();
							break;
						}
						if(!isqueue[nxt])
						{
							q.push(nxt);
							isqueue[nxt] = 1;
						}
					}
				}
			}
			if(neg_cicle)
				g << "Ciclu negativ!";
			else
			{
				for(int i = 2; i <= n; ++i)
					g << dist[i] << " ";
			}
		}
		int maxflow()
		{
			vector<vector<pair<int, int> > > costs;
			vector<pair<int, pair<int, int> > > edges;
			cost_graph(costs, edges);
			v.resize(n+2);
			int C[n+2][n+2], flow = 0, F[n+2][n+2], TT[n+2];
			for(int i = 0; i <= n; ++i)
				for(int j = 0; j <= n; ++j)
					C[i][j] = F[i][j] = TT[i] = 0;
			for(auto x : edges)
			{
				v[x.se.fi].push_back(x.se.se);
				v[x.se.se].push_back(x.se.fi);
				C[x.se.fi][x.se.se] += x.fi;
			}
			while(1)
			{
				int cd[n+2], viz[n+2];
				for(int i = 0; i <= n; ++i)
					cd[i] = 0;
				cd[0]=cd[1]=1;
				memset(viz, 0, sizeof(viz));
				viz[1] = 1;
				for (int i=1;i<=cd[0];i++)
				{
					int nod = cd[i];
					if (nod == n)
						continue;
					for (int j = 0; j < v[nod].size(); j++)
					{
						int V = v[nod][j];
						if (C[nod][V] == F[nod][V] || viz[V])
							continue;
						viz[V] = 1;
						cd[++cd[0]] = V;
						TT[V] = nod;
					}
				}
				for (int i=0;i<v[n].size();i++)
				{
					int nod=v[n][i];
					if (F[nod][n] == C[nod][n] || !viz[nod])
						continue;
					TT[n] = nod;
					int fmin = (1<<30);
					for (nod = n; nod != 1; nod=TT[nod])
					{
						int R=TT[nod];
						fmin=min(fmin,C[R][nod]-F[R][nod]);
					}
					if (fmin == 0)
						continue;
					for (nod = n; nod != 1; nod = TT[nod])
					{
						int R=TT[nod];
						F[R][nod]+=fmin;
						F[nod][R]-=fmin;
					}
					flow+=fmin;
				}
				if(!viz[n])
					break;
			}
			return flow;
		}
		void floyd_warshall()
		{
			f >> n;
			int a[n+2][n+2];
			for(int i = 1; i <= n; ++i)
				for(int j = 1; j <= n; ++j)
					f >> a[i][j];
			for(int k = 1; k <= n; k++)
				for(int i = 1; i <= n; i++)
					for(int j = 1; j <= n; j++)
						if(a[i][k] && a[k][j] && (a[i][j] > a[i][k] + a[k][j] || !a[i][j]) && i != j)
							a[i][j] = a[i][k] + a[k][j];
			for(int i = 1; i <= n; g << '\n', ++i)
				for(int j = 1; j <= n; ++j)
					g << a[i][j] << " ";
		}
		int bfs_new(int node)
		{
			for(int i = 1; i <= n; ++i)
				dist[i] = -1;
			dist[node] = 0;
			queue<int> q;
			q.push(node);
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
			int mx = node;
			for(int i = 1; i <= n; ++i)
				if(dist[i] > dist[mx])
					mx = i;
			return mx;
		}
		void darb()
		{
			f >> n;
			dist.resize(n+1);
			v.resize(n+1);
			for(int i = 1; i < n; ++i)
			{
				int a, b;
				f >> a >> b;
				v[a].push_back(b);
				v[b].push_back(a);
			}
			g << dist[bfs_new(bfs_new(1))]+1 << '\n';
		}
};
 
Graph_Solver gr;
int main()
{
	gr.darb();
	return 0;
}
