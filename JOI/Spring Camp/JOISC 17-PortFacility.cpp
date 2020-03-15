/*

        JOISC 17-port_facility

    Let's define a graph where each container is a vertex and we draw edges between two containers which can't be put in the same area.
Therefore, the answer will be 2^(number of connected components) or 0 if the graph isn't bipartite(this can be checked with some simulation).

    In order to find the connected components, we are going to use two segment trees which will enable us to find all the containers (i, j)
such that our container (a, b) can't be put in the same area.

    This is true if one of the following is true:
        1) j > a
        2) b < i

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

// #define fisier 1

using namespace std;

typedef long long ll;

int n;
pair<int, int> bk[1000002];

int poz[2000002];

bool chk(vector <pair <int, int> > v)
{
	sort(v.begin(), v.end());
	deque<pair <int, int> > d;
	for(int i = 0; i < v.size(); i++)
	{
		while(!d.empty() && d.back().se < v[i].fi)
			d.pop_back();
		if(!d.empty() && d.back().se < v[i].se)
			return 0;
		d.push_back(v[i]);
	}
	return 1;
}


int aint[8000002], aint2[8000002];
void upd(int nod, int st, int dr, int poz, int val)
{
    if(st == dr)
    {
        aint[nod] = val;
        return;
    }
    int mid = (st + dr) / 2;
    if(poz <= mid)
        upd(nod << 1, st, mid, poz, val);
    else
        upd(nod << 1|1, mid+1, dr, poz, val);
    aint[nod] = max(aint[nod << 1], aint[nod << 1|1]);
}
int query(int nod, int st, int dr, int L, int R)
{
    if(dr < L || st > R)
        return -(1<<30);
    if(L <= st && dr <= R)
        return aint[nod];
    int mid = (st + dr) / 2;
    return max(query(nod << 1, st, mid, L, R), query(nod << 1|1, mid+1, dr, L, R));
}
void upd2(int nod, int st, int dr, int poz, int val)
{
    if(st == dr)
    {
        aint2[nod] = val;
        return;
    }
    int mid = (st + dr) / 2;
    if(poz <= mid)
        upd2(nod << 1, st, mid, poz, val);
    else
        upd2(nod << 1|1, mid+1, dr, poz, val);
    aint2[nod] = min(aint2[nod << 1], aint2[nod << 1|1]);
}
int query2(int nod, int st, int dr, int L, int R)
{
    if(dr < L || st > R)
        return (1<<30);
    if(L <= st && dr <= R)
        return aint2[nod];
    int mid = (st + dr) / 2;
    return min(query2(nod << 1, st, mid, L, R), query2(nod << 1|1, mid+1, dr, L, R));
}
bool viz[1000002];
bool col[1000002];
void dfs(int nod, int c)
{
    viz[nod] = 1;
    col[nod] = c;
    upd(1, 1, n+n, bk[nod].fi, -(1<<30));
    upd2(1, 1, n+n, bk[nod].se, (1<<30));
    while(1)
    {
        int val = (1<<30);
        if(bk[nod].fi + 1 <= bk[nod].se - 1)
            val = query2(1, 1, n+n, bk[nod].fi + 1, bk[nod].se - 1);
        if(val < bk[nod].fi)
            dfs(poz[val], c ^ 1);
        else
            break;
    }
    while(1)
    {
        int val = -(1<<30);
        if(bk[nod].fi + 1 <= bk[nod].se - 1)
            val = query(1, 1, n+n, bk[nod].fi + 1, bk[nod].se - 1);
        if(val > bk[nod].se)
            dfs(poz[val], c ^ 1);
        else
            break;
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

    cin >> n;
    for(int i = 1; i <= n+n; ++i)
    {
        upd(1, 1, n+n, i, -(1<<30));
        upd2(1, 1, n+n, i, (1<<30));
    }
    for(int i = 1; i <= n; ++i)
    {
        cin >> bk[i].fi >> bk[i].se;
        poz[bk[i].fi] = poz[bk[i].se] = i;
        upd(1, 1, n+n, bk[i].fi, bk[i].se);
        upd2(1, 1, n+n, bk[i].se, bk[i].fi);
    }
    int ans = 1;
    for(int i = 1; i <= n; ++i)
        if(!viz[i])
        {
            ans = (ans * 2) % mod;
            dfs(i, 0);
        }
    vector<pair<int, int> >a, b;
	for(int i = 1; i <= n; i++)
    {
		if(col[i])
            a.pb({bk[i].fi, bk[i].se});
		else
            b.pb({bk[i].fi, bk[i].se});
	}
    if(!chk(a) || !chk(b))
    {
        cout << 0 << '\n';
        return 0;
    }
    cout << ans << '\n';
    return 0;
}
