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
 
int n, q, k;
vector<pair<int, int> > ve[100002], aint[400002];
 
void build(int nod, int st, int dr)
{
	if(st == dr)
	{
		aint[nod] = ve[st];
		return;
	}
	int mid = (st + dr) / 2;
	build(nod << 1, st, mid);
	build(nod << 1|1, mid+1, dr);
	int x = aint[nod << 1].size() - 1;
	int y = aint[nod << 1|1].size() - 1;
	int miniA = (1<<30);
	int miniB = (1<<30);
	while(x >= 0 && y >= 0)
	{
		int poz;
		if(aint[nod << 1][x].fi == aint[nod << 1|1][y].fi)
		{
			miniA = min(miniA, aint[nod << 1][x].se);
			miniB = min(miniB, aint[nod << 1|1][y].se);
			poz = aint[nod << 1][x].fi;
			--x;
			--y;
		}
		else
		{
			if(aint[nod << 1][x].fi > aint[nod << 1|1][y].fi)
			{
				miniA = min(miniA, aint[nod << 1][x].se);
				poz = aint[nod << 1][x].fi;
				--x;
			}
			else
			{
				miniB = min(miniB, aint[nod << 1|1][y].se);
				poz = aint[nod << 1|1][y].fi;
				--y;
			}
		}
		aint[nod].pb({poz, max(miniA, miniB)});
	}
	while(x >= 0)
	{
		miniA = min(miniA, aint[nod << 1][x].se);
		int poz = aint[nod << 1][x].fi;
		--x;
		aint[nod].pb({poz, max(miniA, miniB)});
	}
	while(y >= 0)
	{
		miniB = min(miniB, aint[nod << 1|1][y].se);
		int poz = aint[nod << 1|1][y].fi;
		--y;
		aint[nod].pb({poz, max(miniA, miniB)});
	}
	reverse(aint[nod].begin(), aint[nod].end());
}
 
bool ok;
void query(int nod, int st, int dr, int L, int R, int poza, int pozb)
{
	if(!ok)
		return;
	if(dr < L || st > R)
		return;
	if(L <= st && dr <= R)
	{
		int aa = 0;
		int bb = aint[nod].size() - 1;
		int mini = (1<<30);
		while(aa <= bb)
		{
			int hf = (aa + bb) / 2;
			if(aint[nod][hf].fi >= poza)
				mini = min(mini, aint[nod][hf].se), bb = hf - 1;
			else
				aa = hf + 1;
		}
		if(mini > pozb)
			ok = 0;
		return;
	}
	int mid = (st + dr) / 2;
	query(nod << 1, st, mid, L, R, poza, pozb);
	query(nod << 1|1, mid+1, dr, L, R, poza, pozb);
}
int main()
{
 
    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
	cin >> n >> q >> k;
	for(int i = 1; i <= n; ++i)
		ve[i].pb({(1<<30), (1<<30)});
	for(int i = 1; i <= k; ++i)
	{
		int L, R, x;
		cin >> L >> R >> x;
		ve[x].pb({L, R});
	}
	for(int i = 1; i <= n; ++i)
	{
		sort(ve[i].begin(), ve[i].end());
		for(int j = ve[i].size() - 2; j >= 0; --j)
			ve[i][j].se = min(ve[i][j].se, ve[i][j+1].se);
	}
	build(1, 1, n);
	for(; q; --q)
	{
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		ok = 1;
		query(1, 1, n, a, b, x, y);
		cout << (ok == 1 ? "yes" : "no");
		cout << endl;
	}
    return 0;
}
