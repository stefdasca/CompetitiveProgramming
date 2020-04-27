/*
			Baltic 08-Game

	If the shortest path between A and B has odd length, the first player can always win.
	
	Otherwise, let's analize the paths A and B have to use. If one of the players doesn't use
a shortest path, the other player can always use the shortest path to get to other's capital first.

	Now, we can divide the cells based on the distances from A and B and then use DP to solve this problem,
	
	dp[xa][xb][i] = -1 if the player A wins(A is on cell xa in list of cells of distance i, B is on cell xb in list of cells of distance i)

	The states can be checked by using some casework, check out the implementation for more details. 

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
 
const int mxsz = 302;
vector<int> v[mxsz * mxsz], va[mxsz * mxsz], vb[mxsz * mxsz];
 
char mat[mxsz][mxsz];
int n, orgA, orgB, da[mxsz * mxsz], db[mxsz * mxsz], ha[mxsz * mxsz], hb[mxsz * mxsz];
 
int dp[mxsz][mxsz][2];
 
bool viz[mxsz * mxsz];
 
int can_jump(int a, int b) 
{
	return (da[a] + db[b] + 1 == da[orgB]) && (abs(a - b) == 1 || abs(a - b) == n);
}
 
void bfs(int org, int arr[])
{
	memset(viz, 0, sizeof(viz));
	deque<int> d;
	d.pb(org);
	viz[org] = 1;
	while(!d.empty())
	{
		int nod = d[0];
		d.pop_front();
		for(int i = 0; i < v[nod].size(); ++i)
		{
			int vecin = v[nod][i];
			if(!viz[vecin])
			{
				viz[vecin] = 1;
				arr[vecin] = arr[nod] + 1;
				d.pb(vecin);
			}
		}
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
 
	int t;
	cin >> t;
	for(; t; --t)
	{
		memset(da, 0, sizeof(da));
		memset(db, 0, sizeof(db));
		memset(mat, 0, sizeof(mat));
		for(int i = 0; i < n*n; ++i)
			v[i].clear(), va[i].clear(), vb[i].clear();
		cin >> n;
		for(int i = 0; i < n; ++i)
		{
			cin >> mat[i];
			for(int j = 0; j < n; ++j)
			{
				if(mat[i][j] == 'A') 
					orgA = i * n + j;
               			if(mat[i][j] == 'B') 
					orgB = i * n + j;
                		if(mat[i][j] == '#') 
					continue;
				int x = i * n + j;
				if(j && mat[i][j - 1] != '#') 
					v[x].push_back(x - 1);
				if(i && mat[i - 1][j] != '#') 
					v[x].push_back(x - n);
				if(j + 1 < n && mat[i][j + 1] != '#') 
					v[x].push_back(x + 1);
				if(i + 1 < n && mat[i + 1][j] != '#') 
					v[x].push_back(x + n);
			}
		}
		
		bfs(orgA, da);
		bfs(orgB, db);
		
		int dist = da[orgB];
		
		if(dist % 2 == 1) 
		{
			cout << "A\n";
			continue;
		}
		
		for(int i = 0; i < n * n; i++) 
			if(da[i] + db[i] == dist) 
			{
				ha[i] = va[da[i]].size();
				va[da[i]].push_back(i);
 
				hb[i] = vb[db[i]].size();
				vb[db[i]].push_back(i);
 
				vector <int> vx;
				for(int j = 0; j < v[i].size(); ++j)
				{
					int vec = v[i][j];
					if(da[i] + 1 + db[vec] == dist || da[vec] + 1 + db[i] == dist) 
						vx.push_back(vec);
				}
				v[i] = move(vx);
			}
		memset(dp, -1, sizeof(dp));
		for(int i = dist / 2 - 1; i >= 0; i--) 
		{
			int c = (i & 1);
			for(int a : va[i])
				for(int b : vb[i])
				{
					int xa = ha[a];
					int xb = hb[b];
					if(b == orgA) 
					{ 
						dp[xa][xb][c] = 1; 
						continue; 
					}
					if(can_jump(a, b)) 
					{ 
						dp[xa][xb][c] = -1;
						continue; 
					}
					dp[xa][xb][c] = 1;
					for(int new_a : v[a]) 
					{
						if(da[a] + db[new_a] + 1 != dist) 
							continue;
						if(new_a == orgB) 
						{ 
							dp[xa][xb][c] = -1; 
							break; 
						}
						if(can_jump(new_a, b)) 
							continue;
						int cur = -1;
						for(int new_b : v[b]) 
						{
							if(da[new_b] + db[b] + 1 != dist) 
								continue;
							cur = max(cur, dp[ha[new_a]][hb[new_b]][!c]);
						}
						if(cur == -1)
						{ 
							dp[xa][xb][c] = -1; 
							break; 
						}
					}
				}
		}
		if(dp[ha[orgA]][hb[orgB]][0] == -1) 
			cout << "A\n";
		else 
			cout << "B\n";
	}
    return 0;
}
